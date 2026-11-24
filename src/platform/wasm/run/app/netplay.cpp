// Online co-op, the runner's side (wnet1, D246; docs/multiplayer.md section 17): the lobby, the transport and the
// lockstep. The module's side is src/platform/wasm/gfx/netplay.c (the `hulk` imports net_* below are its calls).
//
// - Lobby: the netplay Worker (net/worker/; HULK_NET_WORKER): the host makes a room and shows its code, up to two
//   guests join by the code. A star: each guest has one libjuice agent to the host, the host one per guest; the
//   Worker carries their descriptions and candidates (HTTP polling), and hands out ICE servers (Cloudflare's STUN, and
//   short-lived TURN credentials when the Worker has the TURN key).
// - Transport: libjuice (ICE: a direct UDP path when the NATs allow, else the TURN relay; netplay_juice_*.c). Datagrams
//   of at most ~1.1 KB: the pads and sets are sent redundantly until acknowledged, the join's state by a windowed,
//   acknowledged stream.
// - Lockstep (delay-based; rollback later, section 2): at its update U every peer publishes its pad for update U+D;
//   the host gathers its own and each guest's pad for U into the set for U and sends it to every guest; every peer
//   plays update U with that set. D comes from the round trip measured at the first join (HULK_COOP_DELAY overrides).
// - Join mid-game: a guest that connects says hello; the host writes its state at its next frame end (the module),
//   this side packs it with the host's save folder and settings, compresses it (zlib) and streams it; the guest puts
//   it back at one of its own frame ends, with its saves in a throwaway folder removed when it quits.
// - Desync check: every HULK_COOP_HASH_EVERY updates (60) each guest sends its state hash; the host compares.
//
// Knobs (tests and the launch options; the menu's Co-op row sets the same through net_menu): HULK_NET_WORKER=URL,
// HULK_COOP_HOST=1, HULK_COOP_JOIN=CODE (or @FILE: the code in a file, waited for), HULK_COOP_CODE_FILE=F (the host
// writes its code there), HULK_COOP_DELAY=N, HULK_COOP_HASH_EVERY=N, HULK_COOP_SHIM=seed=S,delay=MS,jitter=MS,loss=PCT
// (impairment on every datagram this peer sends), HULK_COOP_RELAY=PORT (run a local TURN relay in this process:
// tests), HULK_COOP_LOG=1|2, HULK_COOP_TMP=DIR.
#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <deque>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

#include <unistd.h>

#include "game.h"
#include "netplay_net.h"
#include "../net/libjuice/src/juice.h"
#include "../disc.h"

#if __has_include("hulk_build_id.h")
#include "hulk_build_id.h"           // (the app's build id: start.cpp)
#endif
#ifndef HULK_BUILD_ID
#define HULK_BUILD_ID "unknown"
#endif

using namespace coopnet;

extern "C" uint8_t* hulk_run_memory(void);    // run/native.c
static uint8_t* M(u32 a) { return a ? hulk_run_memory() + a : nullptr; }

namespace {

// ------------------------------------------------------------------------------------------------ constants
constexpr u32 kProto = 1;
constexpr u32 kRing = 8192;               // updates kept (sets, inputs, hashes)
constexpr int kMaxGuests = 2;
constexpr size_t kChunk = 1100;           // one datagram's share of the join's state
constexpr double kPeerTimeoutMs = 10000;  // a silent peer is gone
enum : uint8_t { T_HELLO = 1, T_WELCOME, T_SNAP, T_SNAPACK, T_INPUT, T_SET, T_HASH, T_DESYNC, T_PING, T_PONG, T_BYE };
constexpr uint8_t kMagic = 'H';

struct Pad {
    uint8_t b[18];
};
static const Pad kNeutral = {};

int env_int(const char* name, int dflt) {
    const char* v = getenv(name);
    return v && *v ? atoi(v) : dflt;
}
int g_log = -1;
#define LOG(lvl, ...)                                         \
    do {                                                      \
        if (g_log < 0) g_log = env_int("HULK_COOP_LOG", 0);   \
        if (g_log >= (lvl)) {                                 \
            fprintf(stderr, "hulk: co-op: " __VA_ARGS__);     \
            fputc('\n', stderr);                              \
        }                                                     \
    } while (0)
#define SAY(...) LOG(0, __VA_ARGS__)

void put32(std::vector<uint8_t>& v, u32 x) {
    for (int i = 0; i < 4; i++) v.push_back((uint8_t)(x >> (8 * i)));
}
u32 get32(const uint8_t* p) { return p[0] | p[1] << 8 | p[2] << 16 | (u32)p[3] << 24; }
void put64(std::vector<uint8_t>& v, uint64_t x) {
    put32(v, (u32)x);
    put32(v, (u32)(x >> 32));
}
uint64_t get64(const uint8_t* p) { return get32(p) | (uint64_t)get32(p + 4) << 32; }

// ------------------------------------------------------------------------------------------------ the shim
struct Shim {
    bool on = false;
    uint64_t s = 1;
    double delay = 0, jitter = 0, loss = 0;
    double rnd() {          // xorshift64*: seeded, so a test's impairment is the same run to run
        s ^= s >> 12, s ^= s << 25, s ^= s >> 27;
        return (double)((s * 0x2545f4914f6cdd1dull) >> 11) / 9007199254740992.0;
    }
};

// ------------------------------------------------------------------------------------------------ a connection
enum PeerState { P_CONNECTING, P_CONNECTED, P_WANT_JOIN, P_PREPARING, P_SENDING, P_SESSION, P_GONE };
struct Transfer {             // the join's state, sender's or receiver's side
    std::vector<uint8_t> data;
    u32 id = 0, total = 0, nchunks = 0;
    std::vector<uint8_t> acked;            // per chunk
    std::vector<double> sent_at;           // sender: last send time (0: never)
    std::deque<u32> inflight;              // sender: chunks in send order (acknowledged ones leave lazily)
    std::deque<u32> retx;                  // sender: chunks to send again
    u32 cum = 0, next_new = 0, in_flight = 0;
    double rate = 1000;                    // sender: bytes a millisecond (paced; adapted to the loss each round trip)
    double credit = 0, last_tick = 0, epoch = 0;
    u32 epoch_sent = 0, epoch_lost = 0;
    u32 got = 0, since_ack = 0;            // receiver
    double last_ack = 0, started = 0;
    bool done = false;
};
struct Peer {
    int slot = 0, gen = 0;
    juice_agent_t* agent = nullptr;
    PeerState st = P_CONNECTING;
    bool ice_failed = false;
    bool dead = false;                     // a stopped attempt's: never deleted (queued events point at it), ignored
    // signalling
    std::string desc;                      // our description (ufrag, pwd), to post
    std::vector<std::string> cands_out;    // trickled, to post
    bool desc_posted = false, done_local = false, done_posted = false;
    bool remote_desc = false, remote_done = false;
    size_t remote_cands = 0;
    // liveness
    double last_recv = 0, last_ping = 0, rtt = -1, hello_at = 0;
    // host's view of a guest
    u32 start = 0;                         // first update with this guest in the set
    u32 in_next = 0;                       // first of its pads not yet received (from start + D)
    u32 set_next = 0;                      // first set it has not acknowledged
    Pad in[kRing];
    u32 in_u[kRing];
    bool left = false;
    u32 left_at = 0;                       // first update without it
    Transfer xfer;
    double last_set_send = 0;
    std::string refuse;
};

// ------------------------------------------------------------------------------------------------ the session
enum Role { R_NONE, R_HOST, R_GUEST };
enum { ST_IDLE, ST_WORKING, ST_HOSTING, ST_JOINING, ST_IN, ST_FAILED };
struct SetRec {
    u32 u = ~0u, mask = 0;
    Pad pads[3];
};
struct State {
    std::mutex mu;
    std::condition_variable cv;
    Role role = R_NONE;
    bool started = false, quitting = false;
    std::atomic<bool> stopping{false}, signal_done{true};
    int status = 0;                        // ST_*: what the menu's status line says
    std::string why;                       // ST_FAILED: why
    std::string worker, code, token, settings_json;
    int my_slot = 0, my_gen = 0;
    std::vector<juice_turn_server_t> turn;
    std::vector<std::string> turn_str;     // (the strings turn points into)
    std::string stun_host;
    int stun_port = 0;
    Peer* peers[kMaxGuests + 1] = {};      // host: by guest slot (1, 2); guest: [0] the host
    Shim shim;
    struct Delayed {
        double due;
        Peer* p;
        std::vector<uint8_t> d;
    };
    struct Later {
        bool operator()(const Delayed& a, const Delayed& b) const { return a.due > b.due; }
    };
    std::priority_queue<Delayed, std::vector<Delayed>, Later> delayed;
    // lockstep
    bool session = false;                  // a set is in effect (the host: some guest is in; a guest: restored)
    u32 delay = 0, flags = 0, hash_every = 60;
    SetRec sets[kRing];
    u32 last_final = 0;                    // host: the newest set made
    u32 set_next = 0;                      // guest: the first set not received
    Pad mine[kRing];                       // this peer's published pads
    u32 mine_u[kRing];
    u32 mine_last = 0;                     // the newest published
    u32 mine_acked = 0;                    // guest: the host has all of ours below this
    Pad local = {};                        // the frame end's sample
    uint64_t hashes[kRing];
    u32 hash_u[kRing];
    // the join
    bool join_prepared = false;            // host: a snapshot asked of the module, not yet sent
    int join_slot = 0;
    bool guest_ready_restore = false, guest_restored = false;
    std::string dir;                       // this run's co-op folder
    std::string guest_save, guest_snap, guest_settings;
    u32 guest_start = 0;
    bool desync = false;
    bool relay_only = false;               // HULK_COOP_RELAY_ONLY=1 (tests): only relayed candidates
    u32 hashes_ok = 0;
    std::thread signal_thread, pump_thread;
};
State* S;

// ------------------------------------------------------------------------------------------------ sending
void raw_send(Peer* p, const std::vector<uint8_t>& d) {
    if (p->agent && (juice_get_state(p->agent) == JUICE_STATE_CONNECTED || juice_get_state(p->agent) == JUICE_STATE_COMPLETED))
        juice_send(p->agent, (const char*)d.data(), d.size());
}
// (with S->mu held)
void send_pkt(Peer* p, const std::vector<uint8_t>& d) {
    if (!S->shim.on) return raw_send(p, d);
    if (S->shim.rnd() * 100 < S->shim.loss) return;
    double due = now_ms() + S->shim.delay + S->shim.jitter * S->shim.rnd();
    S->delayed.push({due, p, d});
}
std::vector<uint8_t> pkt(uint8_t type) { return {kMagic, type}; }

// ------------------------------------------------------------------------------------------------ libjuice callbacks
// libjuice calls these on its own thread with its registry lock held, and its own calls (juice_send, ...) take that
// lock: so a callback never takes S->mu (a thread holding S->mu may be calling libjuice). It only queues the event;
// drain() handles the queue under S->mu (the pump thread every millisecond, and the main thread while it waits).
struct Ev {
    int kind;                  // 0 a datagram, 1 a state, 2 a candidate, 3 gathering done
    Peer* p;
    int st;
    std::string d;
};
std::mutex g_io;
std::vector<Ev> g_in;
void queue_ev(Ev&& e) {
    {
        std::lock_guard<std::mutex> lk(g_io);
        g_in.push_back(std::move(e));
    }
    S->cv.notify_all();
}
void on_state(juice_agent_t*, juice_state_t st, void* user) { queue_ev({1, (Peer*)user, (int)st, {}}); }
void on_candidate(juice_agent_t*, const char* sdp, void* user) { queue_ev({2, (Peer*)user, 0, sdp}); }
void on_gathering_done(juice_agent_t*, void* user) { queue_ev({3, (Peer*)user, 0, {}}); }
void on_recv(juice_agent_t*, const char* data, size_t size, void* user) {
    queue_ev({0, (Peer*)user, 0, std::string(data, size)});
}
void handle(Peer* p, const uint8_t* d, size_t n);
// (S->mu held)
void drain() {
    std::vector<Ev> evs;
    {
        std::lock_guard<std::mutex> lk(g_io);
        evs.swap(g_in);
    }
    for (Ev& e : evs) {
        Peer* p = e.p;
        if (p->dead) continue;
        if (e.kind == 0) {
            handle(p, (const uint8_t*)e.d.data(), e.d.size());
        } else if (e.kind == 1) {
            juice_state_t st = (juice_state_t)e.st;
            LOG(1, "slot %d: ICE %s", p->slot, juice_state_to_string(st));
            if ((st == JUICE_STATE_CONNECTED || st == JUICE_STATE_COMPLETED) && p->st == P_CONNECTING) {
                p->st = P_CONNECTED;
                p->last_recv = now_ms();
                char local[256] = "", remote[256] = "";
                juice_get_selected_candidates(p->agent, local, sizeof local, remote, sizeof remote);
                SAY("connected to %s (%s)", S->role == R_HOST ? ("player " + std::to_string(p->slot + 1)).c_str() : "the host",
                    strstr(local, "relay") || strstr(remote, "relay") ? "through the TURN relay" : "direct");
                LOG(1, "selected %s <-> %s", local, remote);
            }
            if (st == JUICE_STATE_FAILED) p->ice_failed = true;
        } else if (e.kind == 2) {
            if (!S->relay_only || strstr(e.d.c_str(), "typ relay")) p->cands_out.push_back(e.d);
        } else {
            p->done_local = true;
        }
    }
}

Peer* new_peer(int slot, int gen) {
    Peer* p = new Peer();
    p->slot = slot, p->gen = gen;
    for (u32 i = 0; i < kRing; i++) p->in_u[i] = ~0u;
    juice_config_t c;
    memset(&c, 0, sizeof c);
    c.concurrency_mode = JUICE_CONCURRENCY_MODE_POLL;
    if (!S->stun_host.empty()) c.stun_server_host = S->stun_host.c_str(), c.stun_server_port = (uint16_t)S->stun_port;
    c.turn_servers = S->turn.empty() ? nullptr : S->turn.data();
    c.turn_servers_count = (int)S->turn.size();
    c.cb_state_changed = on_state;
    c.cb_candidate = on_candidate;
    c.cb_gathering_done = on_gathering_done;
    c.cb_recv = on_recv;
    c.user_ptr = p;
    p->agent = juice_create(&c);
    char buf[4096];                 // (taken before gathering: later it lists the candidates, which trickle anyway)
    if (p->agent && juice_get_local_description(p->agent, buf, sizeof buf) == 0) p->desc = buf;
    p->last_recv = now_ms();
    return p;
}

// ------------------------------------------------------------------------------------------------ the join's state
std::string build_id() { return HULK_BUILD_ID; }
uint64_t g_xbe_hash;
uint64_t xbe_hash() {           // the game's data identity: the XBE (the snapshot's ranges check the build itself)
    if (g_xbe_hash) return g_xbe_hash;
    const char* p = getenv("HULK_XBE");
    std::string path = p && *p ? p : std::string(getenv("HULK_DATA_DIR") ? getenv("HULK_DATA_DIR") : ".") + "/default.xbe";
    uint64_t h = 0xcbf29ce484222325ull;
    int fd = hdisc_open(path.c_str());          // (run/disc.c: a folder, an .iso, a disc pack, Android's fd:N)
    if (fd >= 0) {
        std::vector<uint8_t> x(hdisc_size(fd));
        if (hdisc_pread(fd, x.data(), x.size(), 0) == (int64_t)x.size())
            for (uint8_t b : x) h = (h ^ b) * 0x100000001b3ull;
        hdisc_close(fd);
    } else {
        SAY("cannot read %s: the game's identity is unknown (joins will be refused)", path.c_str());
    }
    return g_xbe_hash = h | 1;
}
// the renderer class: frames are counted by presents, which the pddi front end (every real renderer) and the game's
// own d3d layer (HULK_GFX_RENDERER=null) make at different points of a load
uint8_t renderer_class() {
    const char* r = getenv("HULK_GFX_RENDERER");
    return r && !strcmp(r, "null") ? 0 : 1;
}
std::string save_dir() {
    const char* d = getenv("HULK_SAVE_DIR");
    return d && *d ? d : "build/wasm/save";
}

// host: the guest's package (under S->mu: no; it reads files, the caller holds nothing)
bool make_package(const std::string& snap_path, u32 start, const std::string& settings, std::vector<uint8_t>& out) {
    std::vector<uint8_t> raw, snap;
    raw.insert(raw.end(), {'H', 'K', 'J', '1'});
    put32(raw, 1);
    put32(raw, start);
    put32(raw, S->delay);
    put32(raw, S->flags);
    put32(raw, S->hash_every);
    put32(raw, (u32)settings.size());
    raw.insert(raw.end(), settings.begin(), settings.end());
    std::vector<std::string> files;
    list_files(save_dir(), files);
    std::vector<std::pair<std::string, std::vector<uint8_t>>> keep;
    size_t total = 0;
    for (auto& f : files) {
        if (f == "port_settings.txt") continue;
        std::vector<uint8_t> b;
        if (!read_file(save_dir() + "/" + f, b)) continue;
        total += b.size();
        if (total > (64u << 20)) break;
        keep.emplace_back(f, std::move(b));
    }
    put32(raw, (u32)keep.size());
    for (auto& kv : keep) {
        raw.push_back((uint8_t)kv.first.size());
        raw.push_back((uint8_t)(kv.first.size() >> 8));
        raw.insert(raw.end(), kv.first.begin(), kv.first.end());
        put32(raw, (u32)kv.second.size());
        raw.insert(raw.end(), kv.second.begin(), kv.second.end());
    }
    if (!read_file(snap_path, snap)) return false;
    put32(raw, (u32)snap.size());
    raw.insert(raw.end(), snap.begin(), snap.end());
    double t0 = now_ms();
    std::vector<uint8_t> z;
    out.clear();
    if (z_compress(raw.data(), raw.size(), z, 1)) {
        out.insert(out.end(), {'H', 'K', 'Z', '1'});
        put32(out, (u32)raw.size());
        out.insert(out.end(), z.begin(), z.end());
    } else {
        out.insert(out.end(), {'H', 'K', 'R', '1'});
        put32(out, (u32)raw.size());
        out.insert(out.end(), raw.begin(), raw.end());
    }
    SAY("join state: %.1f MB (snapshot %.1f MB, %zu save files), %.1f MB to send (%s, %.0f ms)", raw.size() / 1048576.0,
        snap.size() / 1048576.0, keep.size(), out.size() / 1048576.0, out[2] == 'Z' ? "zlib" : "uncompressed",
        now_ms() - t0);
    return true;
}
// guest: unpack into this run's folder
bool open_package(const std::vector<uint8_t>& in) {
    if (in.size() < 8) return false;
    std::vector<uint8_t> raw(get32(in.data() + 4));
    if (!memcmp(in.data(), "HKZ1", 4)) {
        if (!z_uncompress(in.data() + 8, in.size() - 8, raw.data(), raw.size())) return false;
    } else if (!memcmp(in.data(), "HKR1", 4) && in.size() - 8 == raw.size()) {
        memcpy(raw.data(), in.data() + 8, raw.size());
    } else return false;
    const uint8_t* p = raw.data();
    const uint8_t* e = p + raw.size();
    auto need = [&](size_t k) { return (size_t)(e - p) >= k; };
    if (!need(28) || memcmp(p, "HKJ1", 4) || get32(p + 4) != 1) return false;
    S->guest_start = get32(p + 8);
    S->delay = get32(p + 12);
    S->flags = get32(p + 16);
    S->hash_every = get32(p + 20);
    u32 sl = get32(p + 24);
    p += 28;
    if (!need(sl)) return false;
    S->guest_settings.assign((const char*)p, sl);
    p += sl;
    if (!need(4)) return false;
    u32 nf = get32(p);
    p += 4;
    S->guest_save = S->dir + "/save";
    remove_tree(S->guest_save);
    make_dirs(S->guest_save);
    for (u32 i = 0; i < nf; i++) {
        if (!need(2)) return false;
        size_t ln = p[0] | p[1] << 8;
        p += 2;
        if (!need(ln + 4)) return false;
        std::string name((const char*)p, ln);
        p += ln;
        u32 sz = get32(p);
        p += 4;
        if (!need(sz) || name.find("..") != std::string::npos || name[0] == '/') return false;
        write_file(S->guest_save + "/" + name, p, sz);
        p += sz;
    }
    if (!need(4)) return false;
    u32 ss = get32(p);
    p += 4;
    if (!need(ss)) return false;
    S->guest_snap = S->dir + "/join.snap";
    return write_file(S->guest_snap, p, ss);
}

// ------------------------------------------------------------------------------------------------ the protocol
void send_set_packets(Peer* g, bool force);
void send_inputs(Peer* h, bool force);

void handle(Peer* p, const uint8_t* d, size_t n) {
    if (n < 2 || d[0] != kMagic) return;
    p->last_recv = now_ms();
    const uint8_t t = d[1];
    const uint8_t* q = d + 2;
    n -= 2;
    if (t == T_PING && n >= 8) {
        auto r = pkt(T_PONG);
        r.insert(r.end(), q, q + 8);
        send_pkt(p, r);
        return;
    }
    if (t == T_PONG && n >= 8) {
        double t0;
        memcpy(&t0, q, 8);
        double r = now_ms() - t0;
        p->rtt = p->rtt < 0 ? r : p->rtt * 0.8 + r * 0.2;
        return;
    }
    if (t == T_BYE) {
        LOG(0 + (S->role == R_HOST ? 0 : 0), "slot %d said goodbye", p->slot);
        p->st = P_GONE;
        return;
    }
    if (S->role == R_HOST) {
        if (t == T_HELLO && n >= 4 + 8 + 48 + 1 && p->st == P_CONNECTED) {
            u32 proto = get32(q);
            uint64_t xh = get64(q + 4);
            char bid[49];
            memcpy(bid, q + 12, 48);
            bid[48] = 0;
            std::string why;
            if (proto != kProto) why = "another co-op protocol";
            else if (build_id() != bid) why = std::string("another build of the app (host ") + build_id() + ", guest " + bid + ")";
            else if (xh != xbe_hash()) why = "another copy of the game (the XBE differs)";
            else if (q[60] != renderer_class()) why = "a headless game and one with a renderer cannot play together";
            auto r = pkt(T_WELCOME);
            r.push_back(why.empty() ? 1 : 0);
            r.insert(r.end(), why.begin(), why.end());
            send_pkt(p, r);
            if (!why.empty()) {
                SAY("slot %d refused: %s", p->slot, why.c_str());
                p->st = P_GONE;
                return;
            }
            SAY("player %d says hello: joining", p->slot + 1);
            p->st = P_WANT_JOIN;
            p->hello_at = now_ms();
            return;
        }
        if (t == T_SNAPACK && n >= 8 + 32 && p->st == P_SENDING) {
            Transfer& x = p->xfer;
            if (get32(q) != x.id) return;
            u32 cum = std::min(get32(q + 4), x.nchunks);
            u32 newly = 0;
            auto ack = [&](u32 c) {
                if (x.acked[c]) return;
                x.acked[c] = 1, newly++;
                if (x.sent_at[c] != 0 && x.in_flight) x.in_flight--;
            };
            for (u32 c = x.cum; c < cum; c++) ack(c);
            x.cum = std::max(x.cum, cum);
            for (u32 b = 0; b < 256; b++)
                if (q[8 + b / 8] >> (b % 8) & 1) {
                    u32 c = cum + 1 + b;
                    if (c < x.nchunks) ack(c);
                }
            if (x.cum >= x.nchunks && !x.done) {
                x.done = true;
                double ms = now_ms() - x.started;
                SAY("join state sent to slot %d: %.1f MB in %.1f s (%.2f MB/s, rtt %.0f ms)", p->slot,
                    x.total / 1048576.0, ms / 1000, x.total / 1048576.0 / (ms / 1000), p->rtt);
                p->st = P_SESSION;
                x.data.clear();
                x.data.shrink_to_fit();
            }
            return;
        }
        if (t == T_INPUT && n >= 9 && (p->st == P_SESSION || p->st == P_SENDING)) {
            u32 set_next = get32(q), first = get32(q + 4), k = q[8];
            if (n < 9 + 18 * k) return;
            if (set_next > p->set_next) p->set_next = set_next;
            for (u32 i = 0; i < k; i++) {
                u32 u = first + i;
                if (u < p->start + S->delay) continue;
                memcpy(p->in[u % kRing].b, q + 9 + 18 * i, 18);
                p->in_u[u % kRing] = u;
            }
            while (p->in_u[p->in_next % kRing] == p->in_next) p->in_next++;
            return;
        }
        if (t == T_HASH && n >= 12) {
            u32 u = get32(q);
            uint64_t h = get64(q + 4);
            if (S->hash_u[u % kRing] != u) return;          // (ours not taken yet, or long gone)
            if (S->hashes[u % kRing] == h) {
                S->hashes_ok++;
                LOG(1, "frame %u: slot %d's state hash agrees", u, p->slot);
                if (S->hashes_ok % 50 == 1) SAY("state hashes agree (%u checks; frame %u)", S->hashes_ok, u);
                return;
            }
            SAY("DESYNC with slot %d at frame %u (host %016llx, guest %016llx): the guest leaves the session", p->slot, u,
                (unsigned long long)S->hashes[u % kRing], (unsigned long long)h);
            auto r = pkt(T_DESYNC);
            put32(r, u);
            send_pkt(p, r);
            S->desync = true;
            if (!p->left) p->left = true, p->left_at = S->last_final + 1;
            return;
        }
        return;
    }
    // a guest
    if (t == T_WELCOME && n >= 1) {
        if (!q[0]) {
            SAY("the host refused: %.*s", (int)n - 1, (const char*)q + 1);
            p->st = P_GONE;
        } else if (p->st == P_CONNECTED) {
            p->st = P_WANT_JOIN;
            SAY("the host accepted: its game is on the way");
        }
        return;
    }
    if (t == T_SNAP && n >= 12) {
        Transfer& x = p->xfer;
        u32 id = get32(q), total = get32(q + 4), off = get32(q + 8);
        if (x.id != id) {
            if (x.done) return;
            x = Transfer();
            x.id = id, x.total = total, x.nchunks = (u32)((total + kChunk - 1) / kChunk);
            x.data.resize(total);
            x.acked.assign(x.nchunks, 0);
            x.started = now_ms();
            p->st = P_SENDING;
        }
        if (x.done || off % kChunk || off >= x.total) return;
        u32 c = off / kChunk;
        size_t len = std::min<size_t>(n - 12, x.total - off);
        if (!x.acked[c]) {
            memcpy(x.data.data() + off, q + 12, len);
            x.acked[c] = 1;
            x.got++;
            while (x.cum < x.nchunks && x.acked[x.cum]) x.cum++;
        }
        if (++x.since_ack >= 4 || x.cum == x.nchunks) {
            auto r = pkt(T_SNAPACK);
            put32(r, x.id);
            put32(r, x.cum);
            uint8_t bits[32] = {};
            for (u32 b = 0; b < 256; b++)
                if (x.cum + 1 + b < x.nchunks && x.acked[x.cum + 1 + b]) bits[b / 8] |= 1 << (b % 8);
            r.insert(r.end(), bits, bits + 32);
            send_pkt(p, r);
            x.since_ack = 0;
            x.last_ack = now_ms();
        }
        if (x.cum == x.nchunks && !x.done) {
            x.done = true;
            double ms = now_ms() - x.started;
            SAY("the host's game arrived: %.1f MB in %.1f s (%.2f MB/s)", x.total / 1048576.0, ms / 1000,
                x.total / 1048576.0 / (ms / 1000));
            if (open_package(x.data)) S->guest_ready_restore = true;
            else SAY("the host's game could not be unpacked");
            x.data.clear();
            x.data.shrink_to_fit();
        }
        return;
    }
    if (t == T_SET && n >= 9) {
        u32 in_next = get32(q), first = get32(q + 4), k = q[8];
        if (n < 9 + 55 * k) return;
        if (in_next > S->mine_acked) S->mine_acked = in_next;
        for (u32 i = 0; i < k; i++) {
            const uint8_t* r = q + 9 + 55 * i;
            SetRec& s = S->sets[(first + i) % kRing];
            s.u = first + i;
            s.mask = r[0];
            for (int j = 0; j < 3; j++) memcpy(s.pads[j].b, r + 1 + 18 * j, 18);
        }
        return;
    }
    if (t == T_DESYNC && n >= 4) {
        SAY("DESYNC reported by the host at frame %u: this game leaves the session", get32(q));
        S->desync = true;
        p->st = P_GONE;
        return;
    }
}

// host: the sets a guest lacks, from its acknowledgement on (at most 18 a datagram)
void send_set_packets(Peer* g, bool force) {
    if (g->st != P_SESSION && g->st != P_SENDING) return;
    u32 from = std::max(g->set_next, g->start);
    if (from > S->last_final || !S->session) {
        if (!force) return;
    }
    double now = now_ms();
    if (!force && now - g->last_set_send < 15) return;
    g->last_set_send = now;
    auto r = pkt(T_SET);
    put32(r, g->in_next);
    put32(r, from);
    u32 k = 0;
    std::vector<uint8_t> body;
    for (u32 u = from; S->session && u <= S->last_final && k < 18; u++, k++) {
        const SetRec& s = S->sets[u % kRing];
        if (s.u != u) break;
        body.push_back((uint8_t)s.mask);
        for (int j = 0; j < 3; j++) body.insert(body.end(), s.pads[j].b, s.pads[j].b + 18);
    }
    r.push_back((uint8_t)k);
    r.insert(r.end(), body.begin(), body.end());
    send_pkt(g, r);
}
// guest: our pads the host lacks (at most 32 a datagram), with the acknowledgement of its sets
void send_inputs(Peer* h, bool force) {
    static double last;
    double now = now_ms();
    if (!force && now - last < 15) return;
    last = now;
    if (S->set_next < S->guest_start) S->set_next = S->guest_start;   // (a later guest's first set)
    while (S->sets[S->set_next % kRing].u == S->set_next) S->set_next++;
    u32 set_next = S->set_next;
    u32 from = std::max(S->mine_acked, S->guest_start + S->delay);
    auto r = pkt(T_INPUT);
    put32(r, set_next);
    put32(r, from);
    u32 k = 0;
    std::vector<uint8_t> body;
    for (u32 u = from; u <= S->mine_last && k < 32; u++, k++) {
        if (S->mine_u[u % kRing] != u) break;
        body.insert(body.end(), S->mine[u % kRing].b, S->mine[u % kRing].b + 18);
    }
    r.push_back((uint8_t)k);
    r.insert(r.end(), body.begin(), body.end());
    send_pkt(h, r);
}

// host: the join's state, paced (with S->mu). A rate, not a window: datagrams leave at `rate` bytes a millisecond,
// at most two round trips' worth unacknowledged; each round trip the rate rises 25% while under 3% of the chunks were
// lost, and falls 25% past 10% (random loss on a relay is not congestion: halving on every loss crawled at 0.1 MB/s
// through 3% loss). A chunk unacknowledged after max(2.5 round trips, 150 ms) is sent again.
void pump_transfer(Peer* p) {
    Transfer& x = p->xfer;
    if (p->st != P_SENDING || x.done) return;
    double now = now_ms(), rtt = p->rtt > 0 ? p->rtt : 100.0, rto = std::max(150.0, 2.5 * rtt);
    if (!x.last_tick) x.last_tick = x.epoch = now;
    while (!x.inflight.empty()) {
        u32 c = x.inflight.front();
        if (x.acked[c] || x.sent_at[c] == 0) { x.inflight.pop_front(); continue; }
        if (now - x.sent_at[c] <= rto) break;
        x.inflight.pop_front();
        x.sent_at[c] = 0;
        x.retx.push_back(c);
        if (x.in_flight) x.in_flight--;
        x.epoch_lost++;
    }
    if (now - x.epoch >= std::max(rtt, 100.0)) {
        if (x.epoch_sent >= 16) {
            double loss = (double)x.epoch_lost / x.epoch_sent;
            if (loss > 0.10) x.rate *= 0.75;
            else if (loss < 0.03) x.rate *= 1.25;
            x.rate = std::min(std::max(x.rate, 50.0), 40000.0);
            LOG(2, "transfer to slot %d: %.2f MB/s, loss %.1f%%, %u/%u acknowledged", p->slot, x.rate / 1000,
                100 * loss, x.cum, x.nchunks);
        }
        x.epoch = now, x.epoch_sent = x.epoch_lost = 0;
    }
    x.credit = std::min(x.credit + x.rate * (now - x.last_tick), x.rate * 4 + kChunk);
    x.last_tick = now;
    double cap = std::max(64.0, 2 * x.rate * rtt / kChunk);
    auto send_chunk = [&](u32 c) {
        auto r = pkt(T_SNAP);
        put32(r, x.id);
        put32(r, x.total);
        put32(r, c * (u32)kChunk);
        size_t len = std::min<size_t>(kChunk, x.total - c * kChunk);
        r.insert(r.end(), x.data.begin() + c * kChunk, x.data.begin() + c * kChunk + len);
        send_pkt(p, r);
        x.sent_at[c] = now;
        x.inflight.push_back(c);
        x.in_flight++, x.epoch_sent++;
        x.credit -= (double)len;
    };
    while (x.credit >= kChunk && x.in_flight < cap) {
        if (!x.retx.empty()) {
            u32 c = x.retx.front();
            x.retx.pop_front();
            if (!x.acked[c] && x.sent_at[c] == 0) send_chunk(c);
        } else if (x.next_new < x.nchunks) {
            send_chunk(x.next_new++);
        } else break;
    }
}

// the pump thread: delayed datagrams (the shim), pings, resends, transfers, timeouts
void pump_main() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        std::lock_guard<std::mutex> lk(S->mu);
        if (S->quitting) break;
        drain();
        double now = now_ms();
        while (!S->delayed.empty() && S->delayed.top().due <= now) {    // (jitter reorders them)
            raw_send(S->delayed.top().p, S->delayed.top().d);
            S->delayed.pop();
        }
        for (int k = 0; k <= kMaxGuests; k++) {
            Peer* p = S->peers[k];
            if (!p || p->st == P_GONE || p->st == P_CONNECTING) continue;
            if (now - p->last_ping > 250) {
                auto r = pkt(T_PING);
                r.resize(10);
                memcpy(r.data() + 2, &now, 8);
                send_pkt(p, r);
                p->last_ping = now;
            }
            if (now - p->last_recv > kPeerTimeoutMs) {
                SAY("slot %d is silent: gone", S->role == R_HOST ? p->slot : 0);
                p->st = P_GONE;
                S->cv.notify_all();
                continue;
            }
            if (S->role == R_HOST) {
                if (p->st == P_SENDING) pump_transfer(p);
                send_set_packets(p, false);
            } else {
                if (p->st == P_CONNECTED) {              // hello until the host answers
                    static double last_hello;
                    if (now - last_hello > 300) {
                        auto r = pkt(T_HELLO);
                        put32(r, kProto);
                        put64(r, xbe_hash());
                        char bid[48] = {};
                        snprintf(bid, sizeof bid, "%s", build_id().c_str());
                        r.insert(r.end(), bid, bid + 48);
                        r.push_back(renderer_class());
                        send_pkt(p, r);
                        last_hello = now;
                    }
                }
                if (S->session) send_inputs(p, false);
            }
        }
        S->cv.notify_all();
    }
}

// ------------------------------------------------------------------------------------------------ signalling
void fail(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
std::string room_url(const char* tail = "") { return S->worker + "/rooms/" + S->code + tail; }
bool fetch_ice() {
    HttpReply r = http("POST", S->worker + "/ice", "{}", "");
    Json j;
    if (r.status != 200 && r.status != 429 && r.status != 502) {
        SAY("the lobby server did not answer /ice (%d %s): host candidates only", r.status, r.err.c_str());
        return false;
    }
    if (!json_parse(r.body, j)) return false;
    const Json& list = j["iceServers"];
    for (size_t i = 0; i < list.a.size(); i++) {
        const Json& s = list[i];
        const Json& urls = s["urls"];
        std::vector<std::string> us;
        if (urls.kind == Json::STR) us.push_back(urls.s);
        for (auto& u : urls.a) us.push_back(u.s);
        for (auto& u : us) {
            bool turn = !u.compare(0, 5, "turn:");
            if (!turn && u.compare(0, 5, "stun:")) continue;
            std::string hp = u.substr(5);
            hp = hp.substr(0, hp.find('?'));
            size_t c = hp.rfind(':');
            std::string host = c == std::string::npos ? hp : hp.substr(0, c);
            int port = c == std::string::npos ? 3478 : atoi(hp.c_str() + c + 1);
            if (turn) {
                if (S->turn.size() >= 4) continue;
                S->turn_str.push_back(host);
                S->turn_str.push_back(s["username"].s);
                S->turn_str.push_back(s["credential"].s);
            } else if (S->stun_host.empty()) {
                S->stun_host = host, S->stun_port = port;
            }
            if (turn) {
                juice_turn_server_t t;
                t.port = (uint16_t)port;
                S->turn.push_back(t);
            }
        }
    }
    // (turn_str can reallocate while it grows: point into it once it is complete)
    for (size_t i = 0; i < S->turn.size(); i++) {
        S->turn[i].host = S->turn_str[3 * i].c_str();
        S->turn[i].username = S->turn_str[3 * i + 1].c_str();
        S->turn[i].password = S->turn_str[3 * i + 2].c_str();
    }
    SAY("ICE: %s STUN, %zu TURN relay%s%s", S->stun_host.empty() ? "no" : S->stun_host.c_str(), S->turn.size(),
        S->turn.size() == 1 ? "" : "s", j["turn"].b ? "" : " (the server has no TURN key)");
    return true;
}
// post what this side of PEER has that the Worker lacks (S->mu not held)
void post_side(Peer* p) {
    std::string desc;
    std::vector<std::string> cands;
    bool done = false;
    {
        std::lock_guard<std::mutex> lk(S->mu);
        if (!p->desc_posted) desc = p->desc;
        size_t take = std::min<size_t>(p->cands_out.size(), 8);
        cands.assign(p->cands_out.begin(), p->cands_out.begin() + take);
        done = p->done_local && !p->done_posted && take == p->cands_out.size();
    }
    if (desc.empty() && cands.empty() && !done) return;
    std::string b = "{";
    if (S->role == R_HOST) b += "\"to\":" + std::to_string(p->slot) + ",\"gen\":" + std::to_string(p->gen) + ",";
    if (!desc.empty()) b += "\"description\":" + json_quote(desc) + ",";
    if (!cands.empty()) {
        b += "\"candidates\":[";
        for (size_t i = 0; i < cands.size(); i++) b += (i ? "," : "") + json_quote(cands[i]);
        b += "],";
    }
    if (done) b += "\"gatheringDone\":true,";
    b.back() = '}';
    HttpReply r = http("POST", room_url("/signal"), b, S->token);
    std::lock_guard<std::mutex> lk(S->mu);
    if (r.status == 200) {
        if (!desc.empty()) p->desc_posted = true;
        p->cands_out.erase(p->cands_out.begin(), p->cands_out.begin() + (long)cands.size());
        if (done) p->done_posted = true;
    } else {
        LOG(1, "signal post: %d %s %s", r.status, r.err.c_str(), r.body.c_str());
        if (r.status == 409 && S->role == R_HOST) p->st = P_GONE;   // (that guest has left)
    }
}
// apply the other side's description and candidates (S->mu held)
void apply_remote(Peer* p, const Json& side) {
    if (!p->remote_desc && side["description"].kind == Json::STR) {
        juice_set_remote_description(p->agent, side["description"].s.c_str());
        p->remote_desc = true;
        juice_gather_candidates(p->agent);
    }
    if (!p->remote_desc) return;
    const Json& c = side["candidates"];
    for (; p->remote_cands < c.a.size(); p->remote_cands++)
        if (!S->relay_only || strstr(c.a[p->remote_cands].s.c_str(), "typ relay"))
            juice_add_remote_candidate(p->agent, c.a[p->remote_cands].s.c_str());
    if (side["gatheringDone"].b && !p->remote_done) {
        juice_set_remote_gathering_done(p->agent);
        p->remote_done = true;
    }
}

void signal_host() {
    std::string body = "{\"settings\":{\"build\":" + json_quote(build_id()) + ",\"proto\":" + std::to_string(kProto) + "}}";
    HttpReply r = http("POST", S->worker + "/rooms", body, "");
    Json j;
    if (r.status != 201 || !json_parse(r.body, j)) {
        fail("could not make a room (%s)", r.status ? r.body.c_str() : r.err.c_str());
        return;
    }
    {
        std::lock_guard<std::mutex> lk(S->mu);
        if (S->stopping) return;
        S->code = j["code"].s, S->token = j["token"].s;
        S->status = ST_HOSTING;
    }
    SAY("hosting room %s (up to %d players)", S->code.c_str(), j["maxPlayers"].i());
    const char* cf = getenv("HULK_COOP_CODE_FILE");
    if (cf && *cf) {
        std::string tmp = std::string(cf) + ".tmp";
        write_file(tmp, (const uint8_t*)S->code.data(), S->code.size());
        rename(tmp.c_str(), cf);
    }
    double next_poll = 0;
    while (true) {
        bool connecting = false;
        {
            std::lock_guard<std::mutex> lk(S->mu);
            if (S->quitting || S->stopping) break;
            for (int k = 1; k <= kMaxGuests; k++)
                if (S->peers[k] && S->peers[k]->st == P_CONNECTING) connecting = true;
        }
        for (int k = 1; k <= kMaxGuests; k++)
            if (S->peers[k] && S->peers[k]->st != P_GONE) post_side(S->peers[k]);
        if (now_ms() >= next_poll) {
            HttpReply pr = http("GET", room_url(), "", S->token);
            next_poll = now_ms() + (connecting ? 700 : 6000);
            Json pj;
            if (pr.status == 200 && json_parse(pr.body, pj)) {
                std::lock_guard<std::mutex> lk(S->mu);
                for (auto& g : pj["guests"].a) {
                    int slot = g["slot"].i(), gen = g["gen"].i();
                    if (slot < 1 || slot > kMaxGuests) continue;
                    Peer*& p = S->peers[slot];
                    if (!p || (p->gen != gen && (p->st == P_GONE || p->st == P_CONNECTING))) {
                        if (p && p->agent) juice_destroy(p->agent);   // (a stale slot: the guest left before)
                        delete p;
                        p = new_peer(slot, gen);
                        SAY("a guest is joining (slot %d)", slot);
                        next_poll = now_ms() + 300;
                    }
                    if (p->gen == gen) apply_remote(p, g);
                }
            } else if (pr.status == 404) {
                SAY("the room has expired");
                break;
            } else if (pr.status) {
                LOG(1, "poll: %d %s", pr.status, pr.body.c_str());
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

void signal_guest(std::string code) {
    if (!code.empty() && code[0] == '@') {               // tests: the code from the host's file, once it is there
        std::vector<uint8_t> c;
        for (int i = 0; i < 1200 && !read_file(code.substr(1), c); i++) std::this_thread::sleep_for(std::chrono::milliseconds(100));
        code.assign(c.begin(), c.end());
    }
    std::string c;
    for (char ch : code)
        if (isalnum((unsigned char)ch)) c += (char)toupper((unsigned char)ch);   // ("1234 5678")
    S->code = code = c;
    HttpReply r;
    Json j;
    for (int tries = 0; tries < 3; tries++) {       // (a lost answer or a busy server: try again, briefly)
        r = http("POST", room_url("/join"), "{}", "");
        if (r.status == 200 || r.status == 409 || S->stopping) break;
        LOG(0, "join %s: %d %s%s", code.c_str(), r.status, r.body.c_str(), r.err.c_str());
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    if (r.status != 200 || !json_parse(r.body, j)) {
        fail("could not join %s (%s)", code.c_str(), r.status == 404 ? "no such room" : r.status == 409 ? "the room is full"
                                                     : r.status ? r.body.c_str() : r.err.c_str());
        return;
    }
    S->token = j["token"].s;
    S->my_slot = j["slot"].i(), S->my_gen = j["gen"].i();
    SAY("joined room %s as player %d", code.c_str(), S->my_slot + 1);
    Peer* p;
    {
        std::lock_guard<std::mutex> lk(S->mu);
        p = S->peers[0] = new_peer(0, S->my_gen);
        p->slot = S->my_slot;
    }
    double give_up = now_ms() + 60000;
    while (true) {
        {
            std::lock_guard<std::mutex> lk(S->mu);
            if (S->quitting || S->stopping || p->st == P_GONE) break;
            if (p->st != P_CONNECTING && p->done_posted) break;   // (connected: the Worker's part is done)
            if (now_ms() > give_up || p->ice_failed) {
                fail("could not reach the host (%s)", p->ice_failed ? "no network path" : "timed out");
                p->st = P_GONE;
                break;
            }
        }
        post_side(p);
        HttpReply pr = http("GET", room_url(), "", S->token);
        Json pj;
        if (pr.status == 200 && json_parse(pr.body, pj)) {
            std::lock_guard<std::mutex> lk(S->mu);
            apply_remote(p, pj["peer"]);
        } else if (pr.status == 404 || pr.status == 403) {
            SAY("the room is gone (%d %s)", pr.status, pr.body.c_str());
            std::lock_guard<std::mutex> lk(S->mu);
            p->st = P_GONE;
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

// ------------------------------------------------------------------------------------------------ start-up
juice_server_t* g_relay;
void start_relay() {               // tests: a local TURN relay (libjuice's server), credentials hulk/hulk
    int port = env_int("HULK_COOP_RELAY", 0);
    if (!port) return;
    static juice_server_credentials_t cred = {"hulk", "hulk", 0};
    juice_server_config_t c;
    memset(&c, 0, sizeof c);
    c.credentials = &cred;
    c.credentials_count = 1;
    c.max_allocations = 16;
    c.port = (uint16_t)port;
    c.bind_address = "127.0.0.1";
    c.realm = "hulk";
    g_relay = juice_server_create(&c);
    SAY("a local TURN relay on port %d%s", port, g_relay ? "" : ": FAILED");
}

void parse_shim() {
    const char* s = getenv("HULK_COOP_SHIM");
    if (!s || !*s) return;
    S->shim.on = true;
    for (const char* p = s; p && *p;) {
        if (!strncmp(p, "seed=", 5)) S->shim.s = strtoull(p + 5, nullptr, 10) * 2654435761ull + 1;
        else if (!strncmp(p, "delay=", 6)) S->shim.delay = atof(p + 6);
        else if (!strncmp(p, "jitter=", 7)) S->shim.jitter = atof(p + 7);
        else if (!strncmp(p, "loss=", 5)) S->shim.loss = atof(p + 5);
        p = strchr(p, ',');
        if (p) p++;
    }
    SAY("impairment: %.0f ms + up to %.0f ms jitter, %.1f%% loss (seeded)", S->shim.delay, S->shim.jitter, S->shim.loss);
}

void fail(const char* fmt, ...) {          // (S->mu held or not: only the status words)
    char b[200];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(b, sizeof b, fmt, ap);
    va_end(ap);
    SAY("%s", b);
    S->why = b;
    S->status = ST_FAILED;
}

extern "C" const char* hulk_app_default_dir(void);     // start.cpp
std::string worker_url() {
    const char* w = getenv("HULK_NET_WORKER");
    std::string u = w && *w ? w : "";
    if (u.empty()) {                       // <app dir>/coop.txt: the lobby server's URL on its first line
        const char* a = getenv("HULK_APP_DIR");
        std::string dir = a && *a ? a : hulk_app_default_dir();
        std::vector<uint8_t> t;
        if (!dir.empty() && read_file(dir + "/coop.txt", t)) {
            u.assign(t.begin(), t.end());
            u = u.substr(0, u.find_first_of("\r\n"));
        }
    }
    while (!u.empty() && (u.back() == '/' || u.back() == ' ')) u.pop_back();
    return u;
}

// once: the pump thread, the folder, the knobs
void start_infra() {
    if (S->started) return;
    S->started = true;
    S->dir = temp_root() + "/hulk-coop-" + std::to_string(getpid());
    make_dirs(S->dir);
    S->hash_every = (u32)env_int("HULK_COOP_HASH_EVERY", 60);
    S->flags = 0;
    S->relay_only = env_int("HULK_COOP_RELAY_ONLY", 0) != 0;
    parse_shim();
    start_relay();
    juice_set_log_handler([](juice_log_level_t, const char* m) { fprintf(stderr, "hulk: co-op: libjuice: %s\n", m); });
    juice_set_log_level(env_int("HULK_COOP_LOG", 0) >= 3 ? JUICE_LOG_LEVEL_DEBUG : JUICE_LOG_LEVEL_WARN);
    S->pump_thread = std::thread(pump_main);
}

// (S->mu held) this run's attempt ends: the peers are dropped, the session with them
void drop_all() {
    for (int k = 0; k <= kMaxGuests; k++) {
        Peer* p = S->peers[k];
        if (!p) continue;
        if (p->st != P_GONE && p->st != P_CONNECTING) raw_send(p, pkt(T_BYE));
        p->dead = true;
        if (p->agent) juice_destroy(p->agent);
        p->agent = nullptr;
        S->peers[k] = nullptr;          // (the Peer itself stays: queued events may still name it)
    }
    S->session = false;
    S->join_prepared = false;
    S->guest_ready_restore = S->guest_restored = false;
    S->set_next = S->mine_acked = S->mine_last = S->last_final = 0;
    for (u32 i = 0; i < kRing; i++) S->mine_u[i] = S->hash_u[i] = ~0u, S->sets[i].u = ~0u;
}

// a lobby attempt: host a room, or join CODE (refused while the last attempt's thread is still on its way out)
bool begin(Role role, std::string code) {
    start_infra();
    if (!S->signal_done) {
        SAY("busy: the last co-op attempt is still ending");
        return false;
    }
    if (S->signal_thread.joinable()) S->signal_thread.join();
    std::string url = worker_url();
    std::lock_guard<std::mutex> lk(S->mu);
    drop_all();
    S->role = role;
    S->code.clear(), S->token.clear(), S->why.clear();
    S->stopping = false;
    S->desync = false;
    S->worker = url;
    if (S->worker.empty()) {
        fail("no lobby server: set HULK_NET_WORKER or put its URL in coop.txt in the app folder");
        return false;
    }
    S->status = role == R_HOST ? ST_WORKING : ST_JOINING;
    S->turn.clear(), S->turn_str.clear(), S->stun_host.clear();
    S->signal_done = false;
    S->signal_thread = std::thread([role, code] {
        fetch_ice();
        if (role == R_HOST) signal_host();
        else signal_guest(code);
        S->signal_done = true;
    });
    return true;
}

// the player turned co-op off (or the host did, for everyone): leave the room or end it
void stop() {
    LOG(1, "stop (role %d)", S ? (int)S->role : -1);
    if (!S->started) return;
    std::string code, token;
    Role role;
    {
        std::lock_guard<std::mutex> lk(S->mu);
        if (S->role == R_NONE) return;
        SAY("co-op off: %s", S->role == R_HOST ? "the room ends" : "leaving the room");
        drop_all();
        S->stopping = true;
        code = S->code, token = S->token, role = S->role;
        S->role = R_NONE;
        S->status = ST_IDLE;
    }
    if (!code.empty() && !token.empty()) {
        std::string url = S->worker + "/rooms/" + code;
        std::thread([url, token, role] {
            if (role == R_HOST) http("DELETE", url, "", token, 3000);
            else http("POST", url + "/leave", "{}", token, 3000);
        }).detach();
    }
}

void init_once() {
    if (S) return;
    S = new State();
    for (u32 i = 0; i < kRing; i++) S->mine_u[i] = S->hash_u[i] = ~0u;
    g_log = env_int("HULK_COOP_LOG", 0);
    const char* j = getenv("HULK_COOP_JOIN");
    if (j && *j) begin(R_GUEST, j);
    else if (env_int("HULK_COOP_HOST", 0)) begin(R_HOST, "");
}

// ------------------------------------------------------------------------------------------------ the lockstep
// host (S->mu held): the guests in the set for update U
u32 host_mask(u32 u) {
    u32 m = 1;
    for (int k = 1; k <= kMaxGuests; k++) {
        Peer* p = S->peers[k];
        if (!p || !(p->st == P_SENDING || p->st == P_SESSION || p->left)) continue;
        if (p->start == 0 || u < p->start) continue;
        if (p->left && u >= p->left_at) continue;
        m |= 1u << k;
    }
    return m;
}
bool publish_mine(u32 u) {
    for (u32 v = u; v <= u + S->delay; v++)
        if (S->mine_u[v % kRing] != v) {
            S->mine[v % kRing] = S->local;
            S->mine_u[v % kRing] = v;
            S->mine_last = std::max(S->mine_last, v);
        }
    return true;
}

int host_update(u32 u, uint8_t* out) {
    std::unique_lock<std::mutex> lk(S->mu);
    if (!S->session) return 0;
    publish_mine(u);
    drain();
    double t0 = now_ms();
    while (true) {
        u32 mask = host_mask(u);
        bool missing = false;
        for (int k = 1; k <= kMaxGuests; k++) {
            if (!(mask & (1u << k))) continue;
            Peer* p = S->peers[k];
            if (p->st == P_GONE && !p->left) {           // gone while we waited: out from this update on
                p->left = true;
                p->left_at = u;
                SAY("player %d left at frame %u", k + 1, u);
                missing = true;
                break;
            }
            if (u < p->start + S->delay) continue;      // (its first updates: the neutral pad)
            if (p->in_u[u % kRing] != u) missing = true;
        }
        if (!missing) {
            SetRec& s = S->sets[u % kRing];
            s.u = u;
            s.mask = mask;
            s.pads[0] = S->mine[u % kRing];
            for (int k = 1; k <= kMaxGuests; k++) {
                Peer* p = S->peers[k];
                s.pads[k] = !(mask & (1u << k)) || u < p->start + S->delay ? kNeutral : p->in[u % kRing];
            }
            S->last_final = u;
            for (int k = 1; k <= kMaxGuests; k++)
                if (S->peers[k] && (mask & (1u << k))) send_set_packets(S->peers[k], true);
            if (mask == 1) {
                // nobody left in the session: back to playing alone (a later guest starts a new session)
                bool any = false;
                for (int k = 1; k <= kMaxGuests; k++)
                    if (S->peers[k] && (S->peers[k]->st == P_SESSION || S->peers[k]->st == P_SENDING) && !S->peers[k]->left)
                        any = true;
                if (!any) {
                    SAY("every guest has left: playing on alone from frame %u", u);
                    S->session = false;
                    return 0;
                }
            }
            double waited = now_ms() - t0;
            if (waited > 50) LOG(1, "frame %u waited %.0f ms for the guests' pads", u, waited);
            out[0] = (uint8_t)mask;
            for (int k = 0; k < 3; k++) memcpy(out + 16 + 20 * k, s.pads[k].b, 18);
            return 1;
        }
        S->cv.wait_for(lk, std::chrono::milliseconds(2));
        drain();
    }
}

int guest_update(u32 u, uint8_t* out) {
    std::unique_lock<std::mutex> lk(S->mu);
    if (!S->session) return 0;
    Peer* h = S->peers[0];
    publish_mine(u);
    send_inputs(h, true);
    double t0 = now_ms();
    while (S->sets[u % kRing].u != u) {
        if (!h || h->st == P_GONE || S->desync) {
            SAY("the host has gone: playing on alone from frame %u (nothing this game saves is kept)", u);
            S->session = false;
            S->status = ST_FAILED;
            S->why = S->desync ? "the games went out of step" : "the host has left";
            return 0;
        }
        S->cv.wait_for(lk, std::chrono::milliseconds(2));
        drain();
        if (now_ms() - t0 > 200) send_inputs(h, false);
    }
    double waited = now_ms() - t0;
    if (waited > 50) LOG(1, "frame %u waited %.0f ms for the host's set", u, waited);
    const SetRec& s = S->sets[u % kRing];
    out[0] = (uint8_t)s.mask;
    for (int k = 0; k < 3; k++) memcpy(out + 16 + 20 * k, s.pads[k].b, 18);
    return 1;
}

}  // namespace

// ------------------------------------------------------------------------------------------------ the imports
// (netplay.c's coop_set: mask, flags, hash_every, spare (u32 each), then 3 x 20 bytes of pads)
u32 w2c_hulk_net_frame(struct w2c_hulk*, u32 local18, u32 update) {
    init_once();
    (void)update;
    std::lock_guard<std::mutex> lk(S->mu);
    if (!S->started) return 0;
    memcpy(S->local.b, M(local18), 18);
    if (S->role == R_HOST && !S->join_prepared) {
        for (int k = 1; k <= kMaxGuests; k++) {
            Peer* p = S->peers[k];
            if (p && p->st == P_WANT_JOIN && (p->rtt > 0 || now_ms() - p->hello_at > 2000)) {   // (the delay needs a round trip)
                p->st = P_PREPARING;
                S->join_prepared = true;
                S->join_slot = k;
                return 1;
            }
        }
    }
    if (S->role == R_GUEST && S->guest_ready_restore && !S->guest_restored) return 2;
    return 0;
}

u32 w2c_hulk_net_host_snap(struct w2c_hulk*, u32 path, u32 cap) {
    std::lock_guard<std::mutex> lk(S->mu);
    std::string p = S->dir + "/host-join.snap";
    if (p.size() + 1 > cap || !S->peers[S->join_slot]) return 0;
    memcpy(M(path), p.c_str(), p.size() + 1);
    return (u32)S->join_slot;       // (the joining guest's slot: the module's first set names it)
}

void w2c_hulk_net_host_ready(struct w2c_hulk*, u32 ok, u32 next_update, u32 settings, u32 pad18) {
    std::string snap, set = (const char*)M(settings);
    Peer* p;
    {
        std::lock_guard<std::mutex> lk(S->mu);
        S->join_prepared = false;
        p = S->peers[S->join_slot];
        if (!ok || !p || p->st != P_PREPARING) {
            if (p) p->st = P_GONE;
            return;
        }
        u32 start = next_update;
        if (!S->session) {                        // the first guest: a new session from frame F+1, whose set is
            int d = env_int("HULK_COOP_DELAY", 0);  // the pads in effect now (the module made it its first)
            if (d <= 0) d = p->rtt > 0 ? (int)(p->rtt / 16.7) + 2 : 3;    // (frames: up to 60 a second)
            S->delay = (u32)std::min(std::max(d, 2), 12);
            S->session = true;
            memcpy(S->local.b, M(pad18), 18);
            for (u32 v = next_update; v < next_update + S->delay; v++) {
                S->mine[v % kRing] = S->local;
                S->mine_u[v % kRing] = v;
            }
            S->mine_last = next_update + S->delay - 1;
            SetRec& s0 = S->sets[start % kRing];
            s0.u = start;
            s0.mask = 1u | 1u << S->join_slot;
            s0.pads[0] = S->local;
            s0.pads[1] = s0.pads[2] = kNeutral;
            S->last_final = start;
            SAY("a session from frame %u: %u frames of input delay (rtt %.0f ms)", start, S->delay, p->rtt);
        } else {
            start = S->last_final + 1;            // (a later guest: from the first set not yet made)
        }
        next_update = start;
        p->start = start;
        p->in_next = start + S->delay;
        p->set_next = start;
        snap = S->dir + "/host-join.snap";
    }
    std::vector<uint8_t> pkg;
    bool made = make_package(snap, next_update, set, pkg);   // (the files are read without the lock)
    std::lock_guard<std::mutex> lk(S->mu);
    if (!made) {
        p->st = P_GONE;
        return;
    }
    Transfer& x = p->xfer;
    x = Transfer();
    static u32 ids = 0x1000;
    x.id = ++ids;
    x.total = (u32)pkg.size();
    x.nchunks = (u32)((pkg.size() + kChunk - 1) / kChunk);
    x.data = std::move(pkg);
    x.acked.assign(x.nchunks, 0);
    x.sent_at.assign(x.nchunks, 0);
    x.started = now_ms();
    p->st = P_SENDING;
    SAY("player %d joins at frame %u", p->slot + 1, next_update);
}

u32 w2c_hulk_net_guest_snap(struct w2c_hulk*, u32 path, u32 cap, u32 save, u32 cap2, u32 settings, u32 cap3) {
    std::lock_guard<std::mutex> lk(S->mu);
    if (S->guest_snap.size() + 1 > cap || S->guest_save.size() + 1 > cap2 || S->guest_settings.size() + 1 > cap3) return 0;
    memcpy(M(path), S->guest_snap.c_str(), S->guest_snap.size() + 1);
    memcpy(M(save), S->guest_save.c_str(), S->guest_save.size() + 1);
    memcpy(M(settings), S->guest_settings.c_str(), S->guest_settings.size() + 1);
    return (u32)S->my_slot;     // (the guest's Hulk: its local view)
}

void w2c_hulk_net_guest_ready(struct w2c_hulk*, u32 ok, u32 next_update) {
    std::lock_guard<std::mutex> lk(S->mu);
    S->guest_restored = true;
    if (!ok || next_update > S->guest_start) {
        SAY("the host's game did not restore (frame %u, start %u): leaving", next_update, S->guest_start);
        if (S->peers[0]) S->peers[0]->st = P_GONE;
        return;
    }
    S->session = true;
    S->status = ST_IN;
    S->mine_acked = S->guest_start + S->delay;
    S->mine_last = S->guest_start + S->delay - 1;
    S->set_next = next_update + 1;              // (frame F+1's set is in the restored state; the first asked is F+2)
    SAY("in the host's game from frame %u (input delay %u frames)", S->guest_start, S->delay);
    remove_tree(S->guest_snap);
}

u32 w2c_hulk_net_update(struct w2c_hulk*, u32 update, u32 out) {
    init_once();
    if (!S->started) return 0;
    uint8_t* o = M(out);
    uint8_t buf[16 + 60] = {};
    int r = S->role == R_HOST ? host_update(update, buf) : guest_update(update, buf);
    if (!r) return 0;
    u32 mask = buf[0], flags, every;
    {
        std::lock_guard<std::mutex> lk(S->mu);
        flags = S->flags, every = S->hash_every;
    }
    memcpy(o, &mask, 4);
    memcpy(o + 4, &flags, 4);
    memcpy(o + 8, &every, 4);
    memset(o + 12, 0, 4);
    memcpy(o + 16, buf + 16, 60);
    return 1;
}

void w2c_hulk_net_hash(struct w2c_hulk*, u32 update, u64 hash) {
    std::lock_guard<std::mutex> lk(S->mu);
    S->hashes[update % kRing] = hash;
    S->hash_u[update % kRing] = update;
    LOG(2, "frame %u state hash %016llx", update, (unsigned long long)hash);
    if (S->role == R_GUEST && S->peers[0]) {
        auto r = pkt(T_HASH);
        put32(r, update);
        put64(r, hash);
        send_pkt(S->peers[0], r);
    }
}

// the menu's Online Co-op row (gfx/netplay.c): 0 off, 1 host a game, 2 join CODE. A peer of a session gets the host's
// presses too (its menus follow pad 0): a guest ignores "host" and "join" while it is in a game, and "off" leaves.
void w2c_hulk_net_menu(struct w2c_hulk*, u32 what, u32 code) {
    init_once();
    std::string c = code ? (const char*)M(code) : "";
    bool busy;
    {
        std::lock_guard<std::mutex> lk(S->mu);
        busy = S->role != R_NONE && S->status != ST_FAILED;
    }
    if (what == 0) stop();
    else if (busy) SAY("co-op: already %s", S->role == R_HOST ? "hosting" : "joining or in a game");
    else begin(what == 1 ? R_HOST : R_GUEST, c);
}
// the status line: kind (ST_*), and into BUF the room's code or why it failed
u32 w2c_hulk_net_status(struct w2c_hulk*, u32 buf, u32 cap) {
    init_once();
    std::lock_guard<std::mutex> lk(S->mu);
    const std::string& t = S->status == ST_FAILED ? S->why : S->code;
    if (cap) {
        size_t n = std::min<size_t>(t.size(), cap - 1);
        memcpy(M(buf), t.data(), n);
        M(buf)[n] = 0;
    }
    return (u32)S->status;
}

// the app quits (start.cpp hulk_app_quit): the guests get the last sets, everyone a goodbye; a guest's folder goes
extern "C" void hulk_coop_quit(void) {
    if (!S || !S->started) return;
    LOG(1, "the app quits (role %d)", (int)S->role);
    {
        std::unique_lock<std::mutex> lk(S->mu);
        double until = now_ms() + 1500;
        while (S->role == R_HOST && now_ms() < until) {          // the sets the guests still lack
            bool behind = false;
            for (int k = 1; k <= kMaxGuests; k++) {
                Peer* p = S->peers[k];
                if (p && p->st == P_SESSION && !p->left && p->set_next <= S->last_final) behind = true;
            }
            if (!behind) break;
            S->cv.wait_for(lk, std::chrono::milliseconds(5));
        }
        for (int k = 0; k <= kMaxGuests; k++)
            if (S->peers[k]) raw_send(S->peers[k], pkt(T_BYE));
        if (S->hashes_ok || S->desync)
            SAY("%u state hash checks agreed%s", S->hashes_ok, S->desync ? "; a DESYNC was seen" : "");
        S->quitting = true;
    }
    if (S->role == R_HOST && !S->code.empty() && !S->token.empty())
        http("DELETE", room_url(), "", S->token, 2000);
    else if (S->role == R_GUEST && !S->code.empty() && !S->token.empty())
        http("POST", room_url("/leave"), "{}", S->token, 2000);
    if (!S->dir.empty()) remove_tree(S->dir);
    if (S->pump_thread.joinable()) S->pump_thread.join();
    if (S->signal_thread.joinable()) S->signal_thread.detach();
}
