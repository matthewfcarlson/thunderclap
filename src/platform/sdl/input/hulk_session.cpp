// Live session mode: lockstep input streaming, state-hash exchange and the debug control port (hulk_session.h,
// docs/multiplayer.md "M0" and "Control port"). Included by input/hulk_input.cpp (one translation unit with the
// input backend). No C++ dynamic initializers: plain static data.
//
// Wire format (little endian, one UDP datagram, at most HS_MTU bytes):
//   header 32: u32 magic "HNT1", u8 role (1 send, 2 recv), u8 nhash, u16 nframes, u32 frame (the sender's latest
//              session frame), u32 ack (recv: frame records received contiguously from 0; send: 0), u32 t_send (ms,
//              the sender's clock), u32 t_echo (the last t_send seen from the peer), u32 echo_hold (ms since then),
//              u32 0
//   nhash x 8: u32 frame, u32 state hash
//   nframes x: u32 seq, u32 read_begin, u32 read_end, u32 nchanges | 0x10000 when the record ends at a session frame,
//              u32 that frame's call number (else 0xffffffff), then nchanges x 24: u32 read index, u8 port, u8 result,
//              18 bytes HulkPadState (buttons, analog[8], thumb[4])
// A record is a run of pad reads, [read_begin, read_end), with the reads whose result differs from the previous read of
// the same port. A record ends at each session frame, or earlier once it holds HS_REC_CHANGES changes (a loading screen
// can poll hundreds of thousands of times in one frame: play3's auto-START taps change the pad every 8 polls). Every
// send re-sends the records the peer has not acknowledged (up to HULK_NET_REDUNDANCY, oldest first, as many datagrams
// as they need), so a lost packet costs no round trip.
#include "hulk_session.h"

#include <SDL3/SDL.h>

#if defined(_WIN32)
// Winsock through SDL_LoadObject: the Wine build's image links no ws2_32 import library
typedef size_t hs_sock;
#define HS_BAD_SOCK ((hs_sock)~(size_t)0)
#define HS_API __stdcall
struct hs_addr {
    unsigned short family;
    unsigned short port;        // network order
    unsigned int addr;          // network order
    char zero[8];
};
static struct {
    int tried, ok;
    int(HS_API* WSAStartup)(unsigned short, void*);
    hs_sock(HS_API* socket)(int, int, int);
    int(HS_API* bind)(hs_sock, const void*, int);
    int(HS_API* sendto)(hs_sock, const char*, int, int, const void*, int);
    int(HS_API* recvfrom)(hs_sock, char*, int, int, void*, int*);
    int(HS_API* ioctlsocket)(hs_sock, long, unsigned long*);
} g_ws;
static int hs_net_init(void)
{
    if (g_ws.tried)
        return g_ws.ok;
    g_ws.tried = 1;
    SDL_SharedObject* so = SDL_LoadObject("ws2_32.dll");
    if (!so)
        return 0;
    *(SDL_FunctionPointer*)&g_ws.WSAStartup = SDL_LoadFunction(so, "WSAStartup");
    *(SDL_FunctionPointer*)&g_ws.socket = SDL_LoadFunction(so, "socket");
    *(SDL_FunctionPointer*)&g_ws.bind = SDL_LoadFunction(so, "bind");
    *(SDL_FunctionPointer*)&g_ws.sendto = SDL_LoadFunction(so, "sendto");
    *(SDL_FunctionPointer*)&g_ws.recvfrom = SDL_LoadFunction(so, "recvfrom");
    *(SDL_FunctionPointer*)&g_ws.ioctlsocket = SDL_LoadFunction(so, "ioctlsocket");
    if (!g_ws.WSAStartup || !g_ws.socket || !g_ws.bind || !g_ws.sendto || !g_ws.recvfrom || !g_ws.ioctlsocket)
        return 0;
    static unsigned char wsadata[512];
    if (g_ws.WSAStartup(0x0202, wsadata) != 0)
        return 0;
    g_ws.ok = 1;
    return 1;
}
static hs_sock hs_udp(unsigned int addr_be, unsigned short port)
{
    if (!hs_net_init())
        return HS_BAD_SOCK;
    hs_sock s = g_ws.socket(2 /* AF_INET */, 2 /* SOCK_DGRAM */, 17 /* IPPROTO_UDP */);
    if (s == HS_BAD_SOCK)
        return s;
    hs_addr a;
    SDL_zero(a);
    a.family = 2;
    a.port = SDL_Swap16BE(port);
    a.addr = addr_be;
    unsigned long nb = 1;
    if (g_ws.bind(s, &a, sizeof(a)) != 0 || g_ws.ioctlsocket(s, (long)0x8004667eu /* FIONBIO */, &nb) != 0)
        return HS_BAD_SOCK;
    return s;
}
static int hs_send(hs_sock s, const void* p, int n, const hs_addr* to)
{
    return g_ws.sendto(s, (const char*)p, n, 0, to, sizeof(*to));
}
static int hs_recv(hs_sock s, void* p, int n, hs_addr* from)
{
    int fl = sizeof(*from);
    return g_ws.recvfrom(s, (char*)p, n, 0, from, &fl);
}
static void hs_make_addr(hs_addr* a, unsigned int addr_be, unsigned short port)
{
    SDL_zerop(a);
    a->family = 2;
    a->port = SDL_Swap16BE(port);
    a->addr = addr_be;
}
#else
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
typedef int hs_sock;
#define HS_BAD_SOCK (-1)
typedef struct sockaddr_in hs_addr;
static hs_sock hs_udp(unsigned int addr_be, unsigned short port)
{
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (s < 0)
        return HS_BAD_SOCK;
    struct sockaddr_in a;
    SDL_zero(a);
    a.sin_family = AF_INET;
    a.sin_port = htons(port);
    a.sin_addr.s_addr = addr_be;
    if (bind(s, (struct sockaddr*)&a, sizeof(a)) != 0 || fcntl(s, F_SETFL, fcntl(s, F_GETFL, 0) | O_NONBLOCK) != 0) {
        close(s);
        return HS_BAD_SOCK;
    }
    return s;
}
static int hs_send(hs_sock s, const void* p, int n, const hs_addr* to)
{
    return (int)sendto(s, p, (size_t)n, 0, (const struct sockaddr*)to, sizeof(*to));
}
static int hs_recv(hs_sock s, void* p, int n, hs_addr* from)
{
    socklen_t fl = sizeof(*from);
    return (int)recvfrom(s, p, (size_t)n, 0, (struct sockaddr*)from, &fl);
}
static void hs_make_addr(hs_addr* a, unsigned int addr_be, unsigned short port)
{
    SDL_zerop(a);
    a->sin_family = AF_INET;
    a->sin_port = htons(port);
    a->sin_addr.s_addr = addr_be;
}
#endif

// the control port exists only in development builds (never with NDEBUG or HULK_RELEASE)
#if !defined(NDEBUG) && !defined(HULK_RELEASE)
#define HS_CONTROL_PORT 1
#else
#define HS_CONTROL_PORT 0
#endif

// "A.B.C.D" -> network-order address; 1 on success
static int hs_parse_ip(const char* s, unsigned int* out, const char** end)
{
    unsigned char b[4];
    for (int i = 0; i < 4; i++) {
        if (*s < '0' || *s > '9')
            return 0;
        unsigned v = 0;
        while (*s >= '0' && *s <= '9')
            v = v * 10 + (unsigned)(*s++ - '0');
        if (v > 255 || (i < 3 && *s++ != '.'))
            return 0;
        b[i] = (unsigned char)v;
    }
    SDL_memcpy(out, b, 4);
    if (end)
        *end = s;
    return 1;
}

static unsigned hs_env_u(const char* name, unsigned dflt)
{
    const char* v = SDL_getenv(name);
    return v && *v ? (unsigned)SDL_strtoul(v, 0, 10) : dflt;
}

#define HS_MAGIC 0x31544e48u     // "HNT1"
#define HS_MTU 1200
#define HS_LOG_EVERY 300
#define HS_REC_CHANGES 40      // a record closes early at this many changes (20 + 40 * 24 bytes fit one datagram)

struct HsChange {
    unsigned idx;
    unsigned char port, ret;
    HulkPadState s;
};
struct HsFrame {                 // send: the records made here; recv: the records received
    unsigned read_begin, read_end;
    unsigned chg_begin, nchg;    // send: index into g_hs.chg; recv: nchg entries at chg_p
    HsChange* chg_p;
    int have;
    unsigned call;               // the session frame call that closed it (0xffffffff: closed mid-frame, full)
};
struct HsHash {
    unsigned own, remote;
    unsigned char have_own, have_remote, compared;
};

static struct {
    int init, role;              // role 0 none, 1 send, 2 recv
    int failed;
    hs_sock sock;
    hs_addr peer;
    unsigned lead, redundancy, hash_every, timeout_ms;
    SDL_IOStream* log;
    // frame records
    HsFrame* fr;
    unsigned nfr, frcap;         // send: closed records; recv: allocated slots
    HsChange* chg;               // send: all changes in order
    unsigned nchg, chgcap;
    unsigned reads;              // pad reads so far (both roles count the same way)
    unsigned open_begin, open_chg;
    HulkPadState last[HULK_INPUT_PORTS];
    unsigned char last_ret[HULK_INPUT_PORTS], last_have[HULK_INPUT_PORTS];
    // recv cursor
    unsigned next_seq;           // first record not yet received (all before it are)
    unsigned cur_seq, cur_j;     // the next change to apply
    HulkPadState cur[HULK_INPUT_PORTS];
    unsigned char cur_ret[HULK_INPUT_PORTS];
    // peer
    unsigned peer_frame, peer_ack;
    int peer_seen;
    Uint64 peer_last_ms, start_ms;
    unsigned peer_tsend;         // the peer's t_send of its last packet, and when it came
    Uint64 peer_tsend_at;
    // hashes
    HsHash* h;
    unsigned nh;
    unsigned* call_end;          // recv: the sender's read count + 1 at each session frame call (0: not known yet)
    unsigned ncall;
    unsigned hash_ok, hash_bad, first_bad_frame;
    // time and stats
    unsigned frame, frames_seen;
    Uint64 last_send_ms;
    Uint64 stall_ns, stall_win_ns, stall_max_ns, frame_stall_ns;
    unsigned stalled_frames, stalled_win;
    unsigned pkts_out, pkts_in, bytes_out;
    unsigned rtt_last, rtt_min, rtt_max, rtt_n;
    Uint64 rtt_sum;
    int lead_min, lead_max;
    Uint64 last_frame_ns, gap_max_ns, gap_win_max_ns;  // wall time between session frames: what a player sees
    unsigned hitches, hitches_win;                     // gaps over 50 ms (a 30 fps frame is 33.3)
    // mp3: the latency probe's OR override (hulk_session_pad_or)
    int probe;
    int or_on[HULK_INPUT_PORTS];
    HulkPadState or_s[HULK_INPUT_PORTS];
    unsigned or_reads;
} g_hs;

#if HS_CONTROL_PORT
static struct {
    int on;
    hs_sock sock;
    int paused;
    unsigned step_left;
    struct {
        int on;
        unsigned frames_left;    // 0: until "pad P off"
        HulkPadState s;
    } ovr[HULK_INPUT_PORTS];
    unsigned last_hash_frame, last_hash;
} g_ctl;
#endif

static const HulkInputSource* g_hs_inner;

static void hs_log(const char* fmt, ...) SDL_PRINTF_VARARG_FUNC(1);
static void hs_log(const char* fmt, ...)
{
    char line[512];
    va_list ap;
    va_start(ap, fmt);
    SDL_vsnprintf(line, sizeof(line), fmt, ap);
    va_end(ap);
    SDL_Log("%s", line);
    if (g_hs.log) {
        char t[560];
        int n = SDL_snprintf(t, sizeof(t), "[%8llu ms] %s\n", (unsigned long long)(SDL_GetTicks() - g_hs.start_ms), line);
        SDL_WriteIO(g_hs.log, t, (size_t)n);
        SDL_FlushIO(g_hs.log);
    }
}

static void* hs_grow(void* p, unsigned* cap, unsigned need, unsigned size)
{
    if (need <= *cap)
        return p;
    unsigned c = *cap ? *cap : 256;
    while (c < need)
        c *= 2;
    void* q = SDL_realloc(p, (size_t)c * size);
    if (!q)
        return 0;
    SDL_memset((char*)q + (size_t)*cap * size, 0, (size_t)(c - *cap) * size);
    *cap = c;
    return q;
}

static void hs_init(void)
{
    if (g_hs.init)
        return;
    g_hs.init = 1;
    g_hs.sock = HS_BAD_SOCK;
    g_hs.start_ms = SDL_GetTicks();
    g_hs.first_bad_frame = 0xffffffffu;
    g_hs.rtt_min = 0xffffffffu;
    g_hs.probe = SDL_getenv("HULK_LAT_PROBE") != 0;
    const char* role = SDL_getenv("HULK_NET");
    if (role && SDL_strcmp(role, "send") == 0)
        g_hs.role = 1;
    else if (role && SDL_strcmp(role, "recv") == 0)
        g_hs.role = 2;
    else if (role && SDL_strcmp(role, "rb") == 0)
        g_hs.role = 3;
    g_hs.lead = hs_env_u("HULK_NET_LEAD", 8);
    g_hs.redundancy = hs_env_u("HULK_NET_REDUNDANCY", 32);
    g_hs.hash_every = hs_env_u("HULK_NET_HASH_EVERY", 30);
    g_hs.timeout_ms = hs_env_u("HULK_NET_TIMEOUT", 600) * 1000u;
    if (g_hs.redundancy < 1)
        g_hs.redundancy = 1;
    const char* lp = SDL_getenv("HULK_NET_LOG");
    if (g_hs.role && lp && *lp)
        g_hs.log = SDL_IOFromFile(lp, "ab");
    if (g_hs.role) {
        unsigned port = hs_env_u("HULK_NET_BIND", 0);
        const char* peer = SDL_getenv("HULK_NET_PEER");
        unsigned int ip = 0;
        const char* e = 0;
        if (!peer || !hs_parse_ip(peer, &ip, &e) || *e != ':') {
            hs_log("net: HULK_NET_PEER must be A.B.C.D:PORT; session off");
            g_hs.role = 0;
        } else {
            hs_make_addr(&g_hs.peer, ip, (unsigned short)SDL_strtoul(e + 1, 0, 10));
            g_hs.sock = hs_udp(0, (unsigned short)port);
            if (g_hs.sock == HS_BAD_SOCK) {
                hs_log("net: cannot bind UDP port %u; session off", port);
                g_hs.role = 0;
            } else
                hs_log("net: role %s, port %u, peer %s, lead %u, redundancy %u, hash every %u",
                       g_hs.role == 1 ? "send" : g_hs.role == 2 ? "recv" : "rb", port, peer, g_hs.lead, g_hs.redundancy,
                       g_hs.hash_every);
        }
    }
#if HS_CONTROL_PORT
    unsigned cport = hs_env_u("HULK_CTL_PORT", 0);
    if (cport) {
        unsigned int lo;
        hs_parse_ip("127.0.0.1", &lo, 0);
        g_ctl.sock = hs_udp(lo, (unsigned short)cport);
        g_ctl.on = g_ctl.sock != HS_BAD_SOCK;
        SDL_Log("control port: %s 127.0.0.1:%u", g_ctl.on ? "listening on" : "cannot bind", cport);
        if (g_ctl.on && SDL_getenv("HULK_CTL_PAUSED"))
            g_ctl.paused = 1;
    }
#endif
}

int hulk_session_active(void)
{
    hs_init();
#if HS_CONTROL_PORT
    if (g_ctl.on)
        return 1;
#endif
    return g_hs.role != 0 || g_hs.probe;
}

void hulk_session_pad_or(unsigned port, const HulkPadState* s)
{
    if (port >= HULK_INPUT_PORTS)
        return;
    g_hs.or_on[port] = s != 0;
    if (s)
        g_hs.or_s[port] = *s;
}

unsigned hulk_session_pad_or_reads(void)
{
    return g_hs.or_reads;
}

unsigned hulk_session_hash_interval(void)
{
    hs_init();
    return g_hs.hash_every;
}

// ---------------------------------------------------------------------------------------------
// hashes
static HsHash* hs_hash_slot(unsigned frame)
{
    if (!g_hs.hash_every || frame % g_hs.hash_every)
        return 0;
    unsigned i = frame / g_hs.hash_every;
    unsigned cap = g_hs.nh;
    HsHash* h = (HsHash*)hs_grow(g_hs.h, &cap, i + 1, sizeof(HsHash));
    if (!h)
        return 0;
    g_hs.h = h;
    g_hs.nh = cap;
    return &h[i];
}

static void hs_hash_check(unsigned frame, HsHash* h)
{
    if (!h->have_own || !h->have_remote || h->compared)
        return;
    h->compared = 1;
    int ok = h->own == h->remote;
    if (ok)
        g_hs.hash_ok++;
    else {
        if (!g_hs.hash_bad++)
            g_hs.first_bad_frame = frame;
    }
    // every comparison goes to the log file; SDL_Log gets the first 16 and every divergence
    hs_log("net hash frame %u local %08x remote %08x %s", frame, h->own, h->remote, ok ? "ok" : "DIVERGED");
}

// ---------------------------------------------------------------------------------------------
// packets
static void hs_put32(unsigned char* p, unsigned v)
{
    p[0] = (unsigned char)v;
    p[1] = (unsigned char)(v >> 8);
    p[2] = (unsigned char)(v >> 16);
    p[3] = (unsigned char)(v >> 24);
}
static unsigned hs_get32(const unsigned char* p)
{
    return p[0] | (unsigned)p[1] << 8 | (unsigned)p[2] << 16 | (unsigned)p[3] << 24;
}
static void hs_put_pad(unsigned char* p, const HulkPadState* s)
{
    p[0] = (unsigned char)s->buttons;
    p[1] = (unsigned char)(s->buttons >> 8);
    SDL_memcpy(p + 2, s->analog, 8);
    for (int i = 0; i < 4; i++) {
        p[10 + 2 * i] = (unsigned char)s->thumb[i];
        p[11 + 2 * i] = (unsigned char)((unsigned short)s->thumb[i] >> 8);
    }
}
static void hs_get_pad(const unsigned char* p, HulkPadState* s)
{
    s->buttons = (unsigned short)(p[0] | p[1] << 8);
    SDL_memcpy(s->analog, p + 2, 8);
    for (int i = 0; i < 4; i++)
        s->thumb[i] = (short)(unsigned short)(p[10 + 2 * i] | p[11 + 2 * i] << 8);
}

// one datagram: the header, the last four own hashes, then records [*seq, end) while they fit; returns the next record
static unsigned hs_send_one(unsigned seq, unsigned end, Uint64 now)
{
    unsigned char b[HS_MTU];
    unsigned n = 32;
    unsigned nhash = 0;
    if (g_hs.hash_every && g_hs.h) {
        unsigned last = g_hs.frame / g_hs.hash_every;
        for (unsigned k = 0; k < 4 && k <= last; k++) {
            unsigned i = last - k;
            if (i < g_hs.nh && g_hs.h[i].have_own) {
                hs_put32(b + n, i * g_hs.hash_every);
                hs_put32(b + n + 4, g_hs.h[i].own);
                n += 8;
                nhash++;
            }
        }
    }
    unsigned nframes = 0;
    for (; seq < end; seq++) {
        const HsFrame& f = g_hs.fr[seq];
        unsigned need = 20 + 24 * f.nchg;          // a record never exceeds HS_REC_CHANGES changes, so it always fits
        if (n + need > HS_MTU)
            break;
        hs_put32(b + n, seq);
        hs_put32(b + n + 4, f.read_begin);
        hs_put32(b + n + 8, f.read_end);
        hs_put32(b + n + 12, f.nchg | (f.call != 0xffffffffu ? 0x10000u : 0));
        hs_put32(b + n + 16, f.call);
        n += 20;
        for (unsigned j = 0; j < f.nchg; j++) {
            const HsChange& c = g_hs.chg[f.chg_begin + j];
            hs_put32(b + n, c.idx);
            b[n + 4] = c.port;
            b[n + 5] = c.ret;
            hs_put_pad(b + n + 6, &c.s);
            n += 24;
        }
        nframes++;
    }
    hs_put32(b, HS_MAGIC);
    b[4] = (unsigned char)g_hs.role;
    b[5] = (unsigned char)nhash;
    b[6] = (unsigned char)nframes;
    b[7] = (unsigned char)(nframes >> 8);
    hs_put32(b + 8, g_hs.frame);
    hs_put32(b + 12, g_hs.role == 2 ? g_hs.next_seq : 0);
    hs_put32(b + 16, (unsigned)now);
    hs_put32(b + 20, g_hs.peer_tsend);
    hs_put32(b + 24, g_hs.peer_tsend_at ? (unsigned)(now - g_hs.peer_tsend_at) : 0);
    hs_put32(b + 28, 0);
    if (hs_send(g_hs.sock, b, (int)n, &g_hs.peer) > 0) {
        g_hs.pkts_out++;
        g_hs.bytes_out += n;
    }
    return seq;
}

// every unacknowledged record (at most HULK_NET_REDUNDANCY of them) in as many datagrams as they need
static void hs_send_packet(void)
{
    if (g_hs.role == 0 || g_hs.role == 3 || g_hs.failed)
        return;
    Uint64 now = SDL_GetTicks();
    unsigned from = 0, end = 0;
    if (g_hs.role == 1 && g_hs.nfr) {
        from = g_hs.peer_ack;
        end = g_hs.nfr;
        if (end - from > g_hs.redundancy && end > g_hs.redundancy)
            end = from + g_hs.redundancy;                 // the oldest unacknowledged first: B needs them in order
    }
    do
        from = hs_send_one(from, end, now);
    while (from < end);
    g_hs.last_send_ms = now;
}

static void hs_recv_frame(unsigned seq, unsigned rb, unsigned re, unsigned nchg, unsigned call, const unsigned char* p)
{
    unsigned cap = g_hs.frcap;
    HsFrame* fr = (HsFrame*)hs_grow(g_hs.fr, &cap, seq + 1, sizeof(HsFrame));
    if (!fr)
        return;
    g_hs.fr = fr;
    g_hs.frcap = cap;
    if (fr[seq].have)
        return;
    HsFrame& f = fr[seq];
    f.read_begin = rb;
    f.read_end = re;
    f.nchg = nchg;
    f.call = call;
    f.chg_p = 0;
    if (call != 0xffffffffu) {                   // the sender's read count at its call CALL (the read-count check)
        unsigned cap2 = g_hs.ncall;
        unsigned* ce = (unsigned*)hs_grow(g_hs.call_end, &cap2, call + 1, sizeof(unsigned));
        if (ce) {
            g_hs.call_end = ce;
            g_hs.ncall = cap2;
            ce[call] = re + 1;                    // +1: 0 means unknown
        }
    }
    if (nchg) {
        f.chg_p = (HsChange*)SDL_malloc(nchg * sizeof(HsChange));
        if (!f.chg_p)
            return;
        for (unsigned j = 0; j < nchg; j++, p += 24) {
            f.chg_p[j].idx = hs_get32(p);
            f.chg_p[j].port = p[4];
            f.chg_p[j].ret = p[5];
            hs_get_pad(p + 6, &f.chg_p[j].s);
        }
    }
    f.have = 1;
    while (g_hs.next_seq < g_hs.frcap && g_hs.fr[g_hs.next_seq].have)
        g_hs.next_seq++;
}

static void hs_pump(void)
{
    if (g_hs.role == 0 || g_hs.role == 3)
        return;
    unsigned char b[2048];
    hs_addr from;
    for (;;) {
        int n = hs_recv(g_hs.sock, b, sizeof(b), &from);
        if (n < 32)
            break;
        if (hs_get32(b) != HS_MAGIC || b[4] == g_hs.role)
            continue;
        Uint64 now = SDL_GetTicks();
        g_hs.pkts_in++;
        g_hs.peer_seen = 1;
        g_hs.peer_last_ms = now;
        unsigned pf = hs_get32(b + 8);
        if (pf > g_hs.peer_frame)
            g_hs.peer_frame = pf;
        unsigned ack = hs_get32(b + 12);
        if (ack > g_hs.peer_ack)
            g_hs.peer_ack = ack;
        g_hs.peer_tsend = hs_get32(b + 16);
        g_hs.peer_tsend_at = now;
        unsigned echo = hs_get32(b + 20), hold = hs_get32(b + 24);
        if (echo) {
            unsigned rtt = (unsigned)now - echo - hold;
            if (rtt < 60000) {
                g_hs.rtt_last = rtt;
                g_hs.rtt_sum += rtt;
                g_hs.rtt_n++;
                if (rtt < g_hs.rtt_min)
                    g_hs.rtt_min = rtt;
                if (rtt > g_hs.rtt_max)
                    g_hs.rtt_max = rtt;
            }
        }
        unsigned nhash = b[5], nframes = b[6] | (unsigned)b[7] << 8;
        const unsigned char* p = b + 32;
        const unsigned char* end = b + n;
        for (unsigned k = 0; k < nhash && p + 8 <= end; k++, p += 8) {
            unsigned fno = hs_get32(p);
            HsHash* h = hs_hash_slot(fno);
            if (h && !h->have_remote) {
                h->remote = hs_get32(p + 4);
                h->have_remote = 1;
                hs_hash_check(fno, h);
            }
        }
        if (g_hs.role == 2)
            for (unsigned k = 0; k < nframes && p + 20 <= end; k++) {
                unsigned seq = hs_get32(p), rb = hs_get32(p + 4), re = hs_get32(p + 8), nc = hs_get32(p + 12) & 0xffff;
                unsigned call = hs_get32(p + 16);
                if (p + 20 + 24 * nc > end)
                    break;
                hs_recv_frame(seq, rb, re, nc, call, p + 20);
                p += 20 + 24 * nc;
            }
    }
}

static int hs_timed_out(void)
{
    Uint64 now = SDL_GetTicks();
    Uint64 since = g_hs.peer_seen ? g_hs.peer_last_ms : g_hs.start_ms;
    if (now - since > g_hs.timeout_ms) {
        hs_log("net: no packet from the peer for %u s at frame %u: session failed, continuing alone",
               g_hs.timeout_ms / 1000, g_hs.frame);
        g_hs.failed = 1;
        return 1;
    }
    return 0;
}

#if HS_CONTROL_PORT
static void ctl_pump(void);
#endif

// one wait step: pump, resend every 10 ms, sleep a little
static void hs_wait_step(void)
{
    hs_pump();
#if HS_CONTROL_PORT
    ctl_pump();
#endif
    if (SDL_GetTicks() - g_hs.last_send_ms >= 10)
        hs_send_packet();
    SDL_DelayNS(250000);
}

// ---------------------------------------------------------------------------------------------
// the control port (debug builds): one text command per datagram, one reply datagram
//   frame                  -> "frame F"
//   hash                   -> "hash F H" (the last session hash and its frame)
//   pause | resume         -> "ok": pause stops before the next frame starts
//   step N                 -> "ok": run N frames, then pause
//   pad P off              -> "ok": stop overriding port P
//   pad P BUTTONS LX LY RX RY [A B X Y BLACK WHITE LT RT] [for N]   (hex buttons word, decimal rest)
//                          -> "ok": port P reads this state (for N frames, or until "pad P off")
//   net                    -> the session counters
//   snapshot | restore     -> "ERR unsupported" (designed in docs/multiplayer.md, not built)
#if HS_CONTROL_PORT
static void ctl_reply(const hs_addr* to, const char* s)
{
    hs_send(g_ctl.sock, s, (int)SDL_strlen(s), to);
}
static void ctl_pump(void)
{
    if (!g_ctl.on)
        return;
    char b[512];
    hs_addr from;
    for (;;) {
        int n = hs_recv(g_ctl.sock, b, sizeof(b) - 1, &from);
        if (n <= 0)
            break;
        b[n] = 0;
        while (n && (b[n - 1] == '\n' || b[n - 1] == '\r' || b[n - 1] == ' '))
            b[--n] = 0;
        char r[256];
        if (!SDL_strcmp(b, "frame"))
            SDL_snprintf(r, sizeof(r), "frame %u", g_hs.frame);
        else if (!SDL_strcmp(b, "hash"))
            SDL_snprintf(r, sizeof(r), "hash %u %08x", g_ctl.last_hash_frame, g_ctl.last_hash);
        else if (!SDL_strcmp(b, "pause")) {
            g_ctl.paused = 1;
            g_ctl.step_left = 0;
            SDL_snprintf(r, sizeof(r), "ok");
        } else if (!SDL_strcmp(b, "resume")) {
            g_ctl.paused = 0;
            SDL_snprintf(r, sizeof(r), "ok");
        } else if (!SDL_strncmp(b, "step", 4)) {
            unsigned k = (unsigned)SDL_strtoul(b + 4, 0, 10);
            g_ctl.paused = 1;
            g_ctl.step_left = k ? k : 1;
            SDL_snprintf(r, sizeof(r), "ok");
        } else if (!SDL_strncmp(b, "pad ", 4)) {
            char* p = b + 4;
            unsigned port = (unsigned)SDL_strtoul(p, &p, 10);
            while (*p == ' ')
                p++;
            if (port >= HULK_INPUT_PORTS)
                SDL_snprintf(r, sizeof(r), "ERR port");
            else if (!SDL_strcmp(p, "off")) {
                g_ctl.ovr[port].on = 0;
                SDL_snprintf(r, sizeof(r), "ok");
            } else {
                HulkPadState s;
                SDL_zero(s);
                s.buttons = (unsigned short)SDL_strtoul(p, &p, 16);
                for (int i = 0; i < 4; i++)
                    s.thumb[i] = (short)SDL_strtol(p, &p, 10);
                unsigned frames = 0;
                for (int i = 0; i < 8; i++) {
                    while (*p == ' ')
                        p++;
                    if (!*p || *p == 'f')
                        break;
                    s.analog[i] = (unsigned char)SDL_strtoul(p, &p, 10);
                }
                while (*p == ' ')
                    p++;
                if (!SDL_strncmp(p, "for", 3))
                    frames = (unsigned)SDL_strtoul(p + 3, 0, 10);
                g_ctl.ovr[port].s = s;
                g_ctl.ovr[port].frames_left = frames;
                g_ctl.ovr[port].on = 1;
                SDL_snprintf(r, sizeof(r), "ok");
            }
        } else if (!SDL_strcmp(b, "net"))
            SDL_snprintf(r, sizeof(r), "net role %d frame %u peer %u reads %u hashes ok %u bad %u stall_ms %llu",
                         g_hs.role, g_hs.frame, g_hs.peer_frame, g_hs.reads, g_hs.hash_ok, g_hs.hash_bad,
                         (unsigned long long)(g_hs.stall_ns / 1000000));
        else if (!SDL_strcmp(b, "snapshot") || !SDL_strcmp(b, "restore"))
            SDL_snprintf(r, sizeof(r), "ERR unsupported");
        else
            SDL_snprintf(r, sizeof(r), "ERR unknown command");
        ctl_reply(&from, r);
    }
}
#endif

// ---------------------------------------------------------------------------------------------
// the input source wrapper
static void hs_close_record(int boundary)
{
    if (g_hs.role != 1)
        return;
    unsigned cap = g_hs.frcap;
    HsFrame* fr = (HsFrame*)hs_grow(g_hs.fr, &cap, g_hs.nfr + 1, sizeof(HsFrame));
    if (!fr)
        return;
    g_hs.fr = fr;
    g_hs.frcap = cap;
    HsFrame& f = fr[g_hs.nfr++];
    f.read_begin = g_hs.open_begin;
    f.read_end = g_hs.reads;
    f.chg_begin = g_hs.open_chg;
    f.nchg = g_hs.nchg - g_hs.open_chg;
    f.have = 1;
    f.call = boundary ? g_hs.frames_seen - 1 : 0xffffffffu;
    g_hs.open_begin = g_hs.reads;
    g_hs.open_chg = g_hs.nchg;
}

static void ws_update(void* self) { g_hs_inner->update(g_hs_inner->self); }
static unsigned ws_connected(void* self) { return g_hs_inner->connected(g_hs_inner->self); }
static unsigned ws_generation(void* self, unsigned port) { return g_hs_inner->generation(g_hs_inner->self, port); }
static void ws_rumble(void* self, unsigned port, unsigned short l, unsigned short r)
{
    g_hs_inner->rumble(g_hs_inner->self, port, l, r);
}
static int ws_read_init(void* self, unsigned port, HulkPadState* out)
{
    return g_hs_inner->read_init ? g_hs_inner->read_init(g_hs_inner->self, port, out)
                                 : g_hs_inner->read(g_hs_inner->self, port, out);
}

// recv: the state of read IDX (waits for the record that covers it)
static int hs_recv_read(unsigned idx, unsigned port, HulkPadState* out)
{
    Uint64 t0 = 0;
    int logged = 0;
    for (;;) {
        if (g_hs.failed)
            break;
        if (g_hs.next_seq && g_hs.fr[g_hs.next_seq - 1].read_end > idx)
            break;
        if (!t0)
            t0 = SDL_GetTicksNS();
        else if (!logged && SDL_GetTicksNS() - t0 > 5000000000ull) {
            logged = 1;
            hs_log("net: frame %u: read %u (port %u, thread %llu) has waited 5 s; records 0..%u received, they cover reads "
                   "< %u; peer frame %u", g_hs.frame, idx, port, (unsigned long long)SDL_GetCurrentThreadID(),
                   g_hs.next_seq, g_hs.next_seq ? g_hs.fr[g_hs.next_seq - 1].read_end : 0, g_hs.peer_frame);
        }
        if (hs_timed_out())
            break;
        hs_wait_step();
    }
    if (t0)
        g_hs.frame_stall_ns += SDL_GetTicksNS() - t0;
    if (g_hs.failed) {
        SDL_zerop(out);
        return 0;
    }
    // apply every change up to IDX
    while (g_hs.cur_seq < g_hs.next_seq) {
        HsFrame& f = g_hs.fr[g_hs.cur_seq];
        if (g_hs.cur_j < f.nchg) {
            const HsChange& c = f.chg_p[g_hs.cur_j];
            if (c.idx > idx)
                break;
            if (c.port < HULK_INPUT_PORTS) {
                g_hs.cur[c.port] = c.s;
                g_hs.cur_ret[c.port] = c.ret;
            }
            if (c.idx == idx && c.port != port && !g_hs.hash_bad) {
                hs_log("net: read %u is of port %u here, of port %u on the sender: the read streams differ", idx, port,
                       c.port);
                g_hs.hash_bad++;
                g_hs.first_bad_frame = g_hs.frame;
            }
            g_hs.cur_j++;
            continue;
        }
        if (f.read_end > idx + 1)
            break;                                   // IDX is inside this record; its later changes wait
        g_hs.cur_seq++;
        g_hs.cur_j = 0;
    }
    *out = g_hs.cur[port];
    return g_hs.cur_ret[port];
}

static int rb_read(unsigned port, int ret, HulkPadState* out);
static int ws_read(void* self, unsigned port, HulkPadState* out)
{
    int ret = g_hs_inner->read(g_hs_inner->self, port, out);
    if (port >= HULK_INPUT_PORTS)
        return ret;
    if (g_hs.role == 3)
        return rb_read(port, ret, out);
    unsigned idx = g_hs.reads++;
    if (g_hs.role == 2)
        return hs_recv_read(idx, port, out);
#if HS_CONTROL_PORT
    if (g_ctl.ovr[port].on) {
        *out = g_ctl.ovr[port].s;
        ret = 1;
    }
#endif
    if (g_hs.or_on[port]) {
        const HulkPadState& o = g_hs.or_s[port];
        out->buttons |= o.buttons;
        for (int i = 0; i < 8; i++)
            out->analog[i] |= o.analog[i];
        for (int i = 0; i < 4; i++)
            if (o.thumb[i])
                out->thumb[i] = o.thumb[i];
        g_hs.or_reads++;
    }
    if (g_hs.role == 1) {
        if (!g_hs.last_have[port] || g_hs.last_ret[port] != (unsigned char)ret ||
            SDL_memcmp(&g_hs.last[port], out, sizeof(*out)) != 0) {
            unsigned cap = g_hs.chgcap;
            HsChange* c = (HsChange*)hs_grow(g_hs.chg, &cap, g_hs.nchg + 1, sizeof(HsChange));
            if (c) {
                g_hs.chg = c;
                g_hs.chgcap = cap;
                c[g_hs.nchg].idx = idx;
                c[g_hs.nchg].port = (unsigned char)port;
                c[g_hs.nchg].ret = (unsigned char)ret;
                c[g_hs.nchg].s = *out;
                g_hs.nchg++;
                if (g_hs.nchg - g_hs.open_chg >= HS_REC_CHANGES)
                    hs_close_record(0);         // the reads so far, ending after this one
            }
            g_hs.last[port] = *out;
            g_hs.last_ret[port] = (unsigned char)ret;
            g_hs.last_have[port] = 1;
        }
    }
    return ret;
}

static HulkInputSource g_hs_wrap = {"session", 0, ws_update, ws_connected, ws_generation, ws_read, ws_rumble, ws_read_init};

const HulkInputSource* hulk_session_wrap(const HulkInputSource* inner)
{
    if (!inner || !hulk_session_active())
        return inner;
    g_hs_inner = inner;
    return &g_hs_wrap;
}

// ---------------------------------------------------------------------------------------------
// per frame
static void hs_stats(int final)
{
    unsigned avg = g_hs.rtt_n ? (unsigned)(g_hs.rtt_sum / g_hs.rtt_n) : 0;
    hs_log("net stats frame %u: stall %llu ms total (%u frames), window %llu ms (%u frames), worst %llu ms; hitches >50 ms "
           "%u total, %u window, worst gap %llu ms (window %llu); rtt last %u min %u avg %u max %u ms; lead %d..%d; "
           "pkts out %u in %u, %u bytes out; hashes ok %u bad %u; reads %u%s",
           g_hs.frame, (unsigned long long)(g_hs.stall_ns / 1000000), g_hs.stalled_frames,
           (unsigned long long)(g_hs.stall_win_ns / 1000000), g_hs.stalled_win, (unsigned long long)(g_hs.stall_max_ns / 1000000),
           g_hs.hitches, g_hs.hitches_win, (unsigned long long)(g_hs.gap_max_ns / 1000000),
           (unsigned long long)(g_hs.gap_win_max_ns / 1000000),
           g_hs.rtt_last, g_hs.rtt_n ? g_hs.rtt_min : 0, avg, g_hs.rtt_max, g_hs.lead_min, g_hs.lead_max, g_hs.pkts_out,
           g_hs.pkts_in, g_hs.bytes_out, g_hs.hash_ok, g_hs.hash_bad, g_hs.reads, final ? " (final)" : "");
    g_hs.stall_win_ns = 0;
    g_hs.stalled_win = 0;
    g_hs.hitches_win = 0;
    g_hs.gap_win_max_ns = 0;
    g_hs.lead_min = g_hs.lead_max = 0;
}

void hulk_session_frame(unsigned frame, int have_hash, unsigned hash)
{
    hs_init();
    g_hs.frame = frame;
    g_hs.frames_seen++;
#if HS_CONTROL_PORT
    if (have_hash) {
        g_ctl.last_hash_frame = frame;
        g_ctl.last_hash = hash;
    }
    for (int p = 0; p < HULK_INPUT_PORTS; p++)
        if (g_ctl.ovr[p].on && g_ctl.ovr[p].frames_left && !--g_ctl.ovr[p].frames_left)
            g_ctl.ovr[p].on = 0;
    ctl_pump();
    if (g_ctl.on && g_ctl.paused) {
        // paused: wait before this frame starts until "resume" or "step N" (N frames run, starting with this one)
        while (g_ctl.paused && !g_ctl.step_left) {
            ctl_pump();
            if (g_hs.role)
                hs_pump();
            SDL_DelayNS(1000000);
        }
        if (g_ctl.step_left)
            g_ctl.step_left--;
    }
#endif
    if (g_hs.role == 0 || g_hs.role == 3)
        return;
    if (have_hash) {
        HsHash* h = hs_hash_slot(frame);
        if (h) {
            h->own = hash;
            h->have_own = 1;
            hs_hash_check(frame, h);
        }
    }
    hs_close_record(1);
    hs_pump();
    // recv: this is call number frames_seen - 1; the sender's record of the same number ends where its reads stood at
    // its own call: the read counts must agree (a difference means the two read streams no longer line up)
    if (g_hs.role == 2) {
        unsigned c = g_hs.frames_seen - 1;
        static unsigned logged_mismatch;
        if (c < g_hs.ncall && g_hs.call_end[c] && g_hs.call_end[c] - 1 != g_hs.reads && logged_mismatch < 8) {
            logged_mismatch++;
            hs_log("net: frame %u (call %u): %u pad reads here, %u on the sender", frame, c, g_hs.reads, g_hs.call_end[c] - 1);
        }
    }
    hs_send_packet();
    // send: the lockstep gate (A may not run more than LEAD frames ahead of the last frame B reported)
    if (g_hs.role == 1 && !g_hs.failed) {
        Uint64 t0 = 0;
        int logged = 0;
        while (!g_hs.failed && (!g_hs.peer_seen || g_hs.peer_frame + g_hs.lead < frame)) {
            if (!t0)
                t0 = SDL_GetTicksNS();
            else if (!logged && SDL_GetTicksNS() - t0 > 5000000000ull) {
                logged = 1;
                hs_log("net: frame %u (reads %u, thread %llu) has waited 5 s for the peer; peer frame %u, peer ack %u of %u "
                       "records", frame, g_hs.reads, (unsigned long long)SDL_GetCurrentThreadID(), g_hs.peer_frame,
                       g_hs.peer_ack, g_hs.nfr);
            }
            if (hs_timed_out())
                break;
            hs_wait_step();
        }
        if (t0)
            g_hs.frame_stall_ns += SDL_GetTicksNS() - t0;
    }
    int lead = (int)(frame - g_hs.peer_frame);
    if (g_hs.frames_seen == 1 || lead < g_hs.lead_min)
        g_hs.lead_min = lead;
    if (g_hs.frames_seen == 1 || lead > g_hs.lead_max)
        g_hs.lead_max = lead;
    // a frame "stalled" when the session made it wait more than 2 ms (B's waits for inputs are attributed to the frame
    // whose reads waited, A's gate to the frame it delayed)
    if (g_hs.frame_stall_ns) {
        g_hs.stall_ns += g_hs.frame_stall_ns;
        g_hs.stall_win_ns += g_hs.frame_stall_ns;
        if (g_hs.frame_stall_ns > g_hs.stall_max_ns)
            g_hs.stall_max_ns = g_hs.frame_stall_ns;
        if (g_hs.frame_stall_ns > 2000000) {
            g_hs.stalled_frames++;
            g_hs.stalled_win++;
        }
        g_hs.frame_stall_ns = 0;
    }
    Uint64 now = SDL_GetTicksNS();
    if (g_hs.last_frame_ns) {
        Uint64 gap = now - g_hs.last_frame_ns;
        if (gap > g_hs.gap_max_ns)
            g_hs.gap_max_ns = gap;
        if (gap > g_hs.gap_win_max_ns)
            g_hs.gap_win_max_ns = gap;
        if (gap > 50000000) {
            g_hs.hitches++;
            g_hs.hitches_win++;
        }
    }
    g_hs.last_frame_ns = now;
    if (frame % HS_LOG_EVERY == 0)
        hs_stats(0);
}

// ---------------------------------------------------------------------------------------------
// mp3: the rollback session (HULK_NET=rb, hulk_session.h). Inputs are keyed by frame: frame F's input is what the
// reads between GameClock::Update's entry of F and of F+1 return. A frame's input for one player is a list of
// changes (read k within the frame, state) applied over the previous frame's last state; player 1 changes only at
// read 0, player 0 (a recording's polls) at any read up to kRbReads - 1. From read kRbReads on (a loading screen
// polling inside one frame) both instances return their own input source's read: the recording's auto-START rule
// gives the same taps on both (it depends on the read count only), and without that rule the last merged state.
//
// Wire format "HRB1" (little endian, one datagram, at most kRbMtu bytes):
//   header 40: u32 magic, u8 player, u8 nhash, u16 nframes, u32 frame (the sender's newest simulated frame), u32 ack
//              (the receiver's next missing frame of the sender's player), u32 t_send, u32 t_echo, u32 echo_hold,
//              u32 local_through (the sender's player has input up to here, exclusive), u32 0, u32 0
//   nhash x 12: u32 frame, u32 small hash, u32 big hash (final frames only)
//   nframes x:  u32 frame, u8 nchg, then nchg x 19: u8 read, 18 bytes HulkPadState
enum { kRbReads = 61, kRbMtu = 1400, kRbMaxSlots = 64, kRbHashKeep = 4 };

struct RbChg {
    unsigned char k;
    HulkPadState s;
};
struct RbFrame {
    unsigned char have, nchg;
    unsigned off;                // into the player's change pool
    HulkPadState fin;            // the state after the frame's last change (valid once have and the frames before)
};
struct RbPlayer {
    RbFrame* f;
    unsigned fcap;
    RbChg* pool;
    unsigned npool, poolcap;
    unsigned through;            // frames [0, through) are complete and decoded in order
};
static struct {
    int init, me;                // me: this instance's player (0 or 1)
    unsigned window, delay, slots, p1_from;
    unsigned rng;                // player 1's generator
    unsigned hold, hold_left;
    HulkPadState gen;
    RbPlayer pl[2];
    // per frame of the remote player: what the last simulation used for it
    unsigned char* used_pred;
    HulkPadState* pred;
    unsigned char* reads;        // reads made in the frame's last simulation (capped at kRbReads)
    unsigned predcap;
    unsigned cur, k;             // the frame being simulated and the next read in it
    unsigned max_sim;            // the newest frame simulated so far (+1; 0: none)
    unsigned pending;            // the earliest frame whose prediction was wrong (0xffffffff: none)
    int resim;
    unsigned resim_to;
    Uint64 resim_t0;
    unsigned slot_frame[kRbMaxSlots];
    // hashes (every hash_every frames): ours as computed by each frame's last simulation, the peer's as received
    unsigned* hs_small;
    unsigned* hs_big;
    unsigned char* hs_have;      // 1 ours, 2 final, 4 remote, 8 compared
    unsigned* hr_small;
    unsigned* hr_big;
    unsigned hcap, final_through;
    // peer
    unsigned peer_frame, peer_ack, peer_through;
    Uint64 peer_seen_ms;
    unsigned peer_tsend;
    Uint64 peer_tsend_at, last_send_ms;
    // stats
    unsigned rollbacks, resim_frames, predicted, mispredicted, stalls, cant;
    Uint64 resim_ns, stall_ns, save_ns, restore_ns, hash_ns;
    unsigned save_n, restore_n, hash_n;
    unsigned depth[kRbMaxSlots];
    unsigned hash_ok, hash_bad, big_bad, first_bad;
    double adv;                  // smoothed frame advantage over the peer
    unsigned throttled;
    unsigned fps;                // the session's own pacing (HULK_NET_RB_FPS; run with HULK_FPS_CAP=0): new frames
    Uint64 deadline_ns;          // only, so a resimulation runs at full speed
    Uint64 last_fresh_ns, gap_max_ns;
    unsigned hitches;            // gaps over 50 ms between new frames
    unsigned fibers_seen, barriers;
    Uint64 barrier_ns;
} g_rb;

int hulk_session_rb_active(void)
{
    hs_init();
    return g_hs.role == 3;
}

int hulk_session_rb_resimulating(void)
{
    return g_rb.resim;
}

static void* rb_grow(void* p, unsigned* cap, unsigned need, unsigned size)
{
    return hs_grow(p, cap, need, size);
}

static RbFrame* rb_frame(RbPlayer* p, unsigned f)
{
    unsigned cap = p->fcap;
    RbFrame* q = (RbFrame*)rb_grow(p->f, &cap, f + 1, sizeof(RbFrame));
    if (!q)
        return 0;
    p->f = q;
    p->fcap = cap;
    return &q[f];
}

static int rb_add_chg(RbPlayer* p, unsigned k, const HulkPadState* s)
{
    unsigned cap = p->poolcap;
    RbChg* q = (RbChg*)rb_grow(p->pool, &cap, p->npool + 1, sizeof(RbChg));
    if (!q)
        return 0;
    p->pool = q;
    p->poolcap = cap;
    q[p->npool].k = (unsigned char)k;
    q[p->npool].s = *s;
    p->npool++;
    return 1;
}

static void rb_init(void)
{
    if (g_rb.init)
        return;
    g_rb.init = 1;
    g_rb.me = (int)hs_env_u("HULK_NET_RB_PLAYER", 0) ? 1 : 0;
    g_rb.window = hs_env_u("HULK_NET_RB_WINDOW", 8);
    g_rb.delay = hs_env_u("HULK_NET_RB_DELAY", 0);
    g_rb.p1_from = hs_env_u("HULK_NET_RB_P1_FROM", 12000);
    g_rb.fps = hs_env_u("HULK_NET_RB_FPS", 30);
    g_rb.rng = hs_env_u("HULK_NET_RB_SEED", 12345) | 1;
    g_rb.pending = 0xffffffffu;
    g_rb.first_bad = 0xffffffffu;
    if (g_rb.window < 1)
        g_rb.window = 1;
    // the local player's first DELAY frames: no input (the frames its delayed input never reaches)
    RbPlayer* me = &g_rb.pl[g_rb.me];
    for (unsigned f = 0; f < g_rb.delay; f++) {
        RbFrame* r = rb_frame(me, f);
        if (r) {
            r->have = 1;
            r->off = me->npool;
        }
    }
    me->through = g_rb.delay;
    hs_log("rb: player %d, window %u, input delay %u, player 1 from frame %u", g_rb.me, g_rb.window, g_rb.delay,
           g_rb.p1_from);
}

// the player's state at read K of frame F (complete frames); BASE: the state before the frame
static HulkPadState rb_state_at(const RbPlayer* p, unsigned f, unsigned k)
{
    HulkPadState s;
    if (f)
        s = p->f[f - 1].fin;
    else
        SDL_zero(s);
    const RbFrame& r = p->f[f];
    for (unsigned j = 0; j < r.nchg; j++) {
        if (p->pool[r.off + j].k > k)
            break;
        s = p->pool[r.off + j].s;
    }
    return s;
}

static void rb_merge(const HulkPadState* a, const HulkPadState* b, HulkPadState* out)
{
    out->buttons = (unsigned short)(a->buttons | b->buttons);
    for (int i = 0; i < 8; i++)
        out->analog[i] = a->analog[i] > b->analog[i] ? a->analog[i] : b->analog[i];
    int sa = a->thumb[0] || a->thumb[1], ra = a->thumb[2] || a->thumb[3];
    out->thumb[0] = sa ? a->thumb[0] : b->thumb[0];
    out->thumb[1] = sa ? a->thumb[1] : b->thumb[1];
    out->thumb[2] = ra ? a->thumb[2] : b->thumb[2];
    out->thumb[3] = ra ? a->thumb[3] : b->thumb[3];
}

// a complete remote frame arrived in order: its final state, and whether the simulation predicted it wrong
static void rb_remote_complete(unsigned f)
{
    RbPlayer* p = &g_rb.pl[!g_rb.me];
    RbFrame* r = &p->f[f];
    r->fin = rb_state_at(p, f, 255);
    if (f >= g_rb.max_sim || f >= g_rb.predcap || !g_rb.used_pred[f])
        return;
    // the reads the last simulation of F made (0..n-1): each must have seen the predicted state
    unsigned n = g_rb.reads[f], j = 0;
    HulkPadState s;
    if (f)
        s = p->f[f - 1].fin;
    else
        SDL_zero(s);
    while (j < r->nchg && p->pool[r->off + j].k == 0)
        s = p->pool[r->off + j++].s;
    int bad = n && SDL_memcmp(&s, &g_rb.pred[f], sizeof(s)) != 0;
    for (; j < r->nchg && !bad; j++) {
        if (p->pool[r->off + j].k >= n)
            break;
        bad = SDL_memcmp(&p->pool[r->off + j].s, &g_rb.pred[f], sizeof(s)) != 0;
    }
    if (bad) {
        g_rb.mispredicted++;
        if (f < g_rb.pending)
            g_rb.pending = f;
    }
    g_rb.used_pred[f] = 0;
}

static void rb_send(void);
static void rb_pump(void)
{
    unsigned char b[2048];
    hs_addr from;
    RbPlayer* p = &g_rb.pl[!g_rb.me];
    for (;;) {
        int n = hs_recv(g_hs.sock, b, sizeof(b), &from);
        if (n < 40)
            break;
        if (hs_get32(b) != 0x31425248u /* "HRB1" */ || b[4] == (unsigned char)g_rb.me)
            continue;
        Uint64 now = SDL_GetTicks();
        g_hs.pkts_in++;
        g_rb.peer_seen_ms = now;
        g_hs.peer_seen = 1;
        g_hs.peer_last_ms = now;
        unsigned pf = hs_get32(b + 8);
        if (pf > g_rb.peer_frame)
            g_rb.peer_frame = pf;
        unsigned ack = hs_get32(b + 12);
        if (ack > g_rb.peer_ack)
            g_rb.peer_ack = ack;
        g_rb.peer_tsend = hs_get32(b + 16);
        g_rb.peer_tsend_at = now;
        unsigned echo = hs_get32(b + 20), hold = hs_get32(b + 24);
        if (echo) {
            unsigned rtt = (unsigned)now - echo - hold;
            if (rtt < 60000) {
                g_hs.rtt_last = rtt;
                g_hs.rtt_sum += rtt;
                g_hs.rtt_n++;
                if (rtt < g_hs.rtt_min)
                    g_hs.rtt_min = rtt;
                if (rtt > g_hs.rtt_max)
                    g_hs.rtt_max = rtt;
            }
        }
        unsigned nhash = b[5], nframes = b[6] | (unsigned)b[7] << 8;
        const unsigned char* q = b + 40;
        const unsigned char* end = b + n;
        for (unsigned i = 0; i < nhash && q + 12 <= end; i++, q += 12) {
            unsigned fr = hs_get32(q);
            if (!g_hs.hash_every || fr % g_hs.hash_every)
                continue;
            unsigned j = fr / g_hs.hash_every, cap = g_rb.hcap;
            unsigned* a = (unsigned*)rb_grow(g_rb.hr_small, &cap, j + 1, 4);
            if (!a)
                continue;
            g_rb.hr_small = a;
            cap = g_rb.hcap;
            a = (unsigned*)rb_grow(g_rb.hr_big, &cap, j + 1, 4);
            if (!a)
                continue;
            g_rb.hr_big = a;
            cap = g_rb.hcap;
            a = (unsigned*)rb_grow(g_rb.hs_small, &cap, j + 1, 4);
            if (!a)
                continue;
            g_rb.hs_small = a;
            cap = g_rb.hcap;
            a = (unsigned*)rb_grow(g_rb.hs_big, &cap, j + 1, 4);
            if (!a)
                continue;
            g_rb.hs_big = a;
            cap = g_rb.hcap;
            unsigned char* h = (unsigned char*)rb_grow(g_rb.hs_have, &cap, j + 1, 1);
            if (!h)
                continue;
            g_rb.hs_have = h;
            g_rb.hcap = cap;
            if (!(h[j] & 4)) {
                h[j] |= 4;
                g_rb.hr_small[j] = hs_get32(q + 4);
                g_rb.hr_big[j] = hs_get32(q + 8);
            }
        }
        for (unsigned i = 0; i < nframes && q + 5 <= end; i++) {
            unsigned fr = hs_get32(q), nc = q[4];
            if (q + 5 + 19 * nc > end)
                break;
            RbFrame* r = rb_frame(p, fr);
            if (r && !r->have) {
                r->off = p->npool;
                r->nchg = 0;
                for (unsigned j = 0; j < nc; j++) {
                    HulkPadState s;
                    hs_get_pad(q + 5 + 19 * j + 1, &s);
                    if (rb_add_chg(p, q[5 + 19 * j], &s))
                        r->nchg++;
                }
                r->have = 1;
            }
            q += 5 + 19 * nc;
        }
        while (p->through < p->fcap && p->f[p->through].have)
            rb_remote_complete(p->through++);
    }
}

// my player's frames the peer has not acknowledged (at most HULK_NET_REDUNDANCY), and the last final hashes
static void rb_send(void)
{
    Uint64 now = SDL_GetTicks();
    RbPlayer* me = &g_rb.pl[g_rb.me];
    RbPlayer* re = &g_rb.pl[!g_rb.me];
    unsigned from = g_rb.peer_ack, end = me->through;
    if (end > from + g_hs.redundancy)
        end = from + g_hs.redundancy;
    do {
        unsigned char b[kRbMtu];
        unsigned n = 40, nhash = 0, nframes = 0;
        if (g_hs.hash_every && g_rb.hs_have) {
            unsigned last = g_rb.final_through / g_hs.hash_every;
            for (unsigned k = 0; k < kRbHashKeep && k <= last; k++) {
                unsigned j = last - k;
                if (j < g_rb.hcap && (g_rb.hs_have[j] & 2)) {
                    hs_put32(b + n, j * g_hs.hash_every);
                    hs_put32(b + n + 4, g_rb.hs_small[j]);
                    hs_put32(b + n + 8, g_rb.hs_big[j]);
                    n += 12;
                    nhash++;
                }
            }
        }
        for (; from < end; from++) {
            const RbFrame& r = me->f[from];
            if (n + 5 + 19 * r.nchg > kRbMtu)
                break;
            hs_put32(b + n, from);
            b[n + 4] = r.nchg;
            n += 5;
            for (unsigned j = 0; j < r.nchg; j++) {
                b[n] = me->pool[r.off + j].k;
                hs_put_pad(b + n + 1, &me->pool[r.off + j].s);
                n += 19;
            }
            nframes++;
        }
        hs_put32(b, 0x31425248u);
        b[4] = (unsigned char)g_rb.me;
        b[5] = (unsigned char)nhash;
        b[6] = (unsigned char)nframes;
        b[7] = (unsigned char)(nframes >> 8);
        hs_put32(b + 8, g_rb.max_sim);
        hs_put32(b + 12, re->through);
        hs_put32(b + 16, (unsigned)now);
        hs_put32(b + 20, g_rb.peer_tsend);
        hs_put32(b + 24, g_rb.peer_tsend_at ? (unsigned)(now - g_rb.peer_tsend_at) : 0);
        hs_put32(b + 28, me->through);
        hs_put32(b + 32, 0);
        hs_put32(b + 36, 0);
        if (hs_send(g_hs.sock, b, (int)n, &g_hs.peer) > 0) {
            g_hs.pkts_out++;
            g_hs.bytes_out += n;
        }
    } while (from < end);
    g_rb.last_send_ms = now;
}

// player 1's input for frame F: a seeded random walk (holds of 2-20 frames; idle, a face button, a stick direction)
static void rb_gen_p1(unsigned f, HulkPadState* s)
{
    if (f < g_rb.p1_from) {
        SDL_zerop(s);
        return;
    }
    if (!g_rb.hold_left) {
        unsigned r = g_rb.rng = g_rb.rng * 1664525u + 1013904223u;
        g_rb.hold_left = 2 + (r >> 8) % 19;
        SDL_zero(g_rb.gen);
        unsigned what = (r >> 16) % 10;
        static const short dir[8][2] = {{32767, 0}, {23170, 23170}, {0, 32767}, {-23170, 23170},
                                        {-32767, 0}, {-23170, -23170}, {0, -32767}, {23170, -23170}};
        if (what >= 4 && what <= 7)
            g_rb.gen.analog[what - 4] = 255;                     // A, B, X, Y
        else if (what >= 8) {
            unsigned d = (r >> 24) & 7;
            g_rb.gen.thumb[0] = dir[d][0];
            g_rb.gen.thumb[1] = dir[d][1];
            if (what == 9)
                g_rb.gen.analog[0] = 255;                        // a jump while moving
        }
    }
    g_rb.hold_left--;
    *s = g_rb.gen;
}

static int rb_read(unsigned port, int ret, HulkPadState* out)
{
    if (port != 0)
        return ret;
    rb_init();
    if (!g_rb.max_sim) {                 // before the first frame: an idle pad on both instances
        SDL_zerop(out);
        return 1;
    }
    unsigned f = g_rb.cur, k = g_rb.k++;
    if (k >= kRbReads) {
        HulkReplayInfo ri;
        if (hulk_replay_info(&ri) && ri.autostart)
            return ret;                  // the recording's auto-START rule (the same on both instances)
        k = kRbReads - 1;
    }
    if (f < g_rb.predcap && k < kRbReads && g_rb.reads[f] < k + 1)
        g_rb.reads[f] = (unsigned char)(k + 1);
    RbPlayer* me = &g_rb.pl[g_rb.me];
    RbPlayer* re = &g_rb.pl[!g_rb.me];
    // my player 0 on its first simulation of a frame: the input source's read is this frame's input (DELAY frames on)
    if (g_rb.me == 0 && f + 1 == g_rb.max_sim && !g_rb.resim) {
        unsigned t = f + g_rb.delay;
        RbFrame* r = rb_frame(me, t);
        if (r && k < kRbReads) {
            if (k == 0) {
                r->off = me->npool;
                r->nchg = 0;
                r->have = 0;
            }
            HulkPadState prev;
            if (r->nchg)
                prev = me->pool[r->off + r->nchg - 1].s;
            else if (t)
                prev = me->f[t - 1].fin;
            else
                SDL_zero(prev);
            if (SDL_memcmp(&prev, out, sizeof(prev)) && rb_add_chg(me, k, out))
                r->nchg++;
        }
    }
    HulkPadState mine, theirs, merged;
    mine = f < me->fcap && me->f[f].have ? rb_state_at(me, f, k) : (f && f - 1 < me->fcap ? me->f[f - 1].fin : HulkPadState());
    if (g_rb.me == 0 && f + 1 == g_rb.max_sim && !g_rb.resim && !g_rb.delay)
        mine = *out;                     // (the frame being recorded: its state so far)
    if (f < re->through)
        theirs = rb_state_at(re, f, k);
    else if (f < g_rb.predcap)
        theirs = g_rb.pred[f];
    else
        SDL_zero(theirs);
    rb_merge(g_rb.me == 0 ? &mine : &theirs, g_rb.me == 0 ? &theirs : &mine, &merged);
    *out = merged;
    return 1;
}

static void rb_close_local(unsigned f)
{
    // my player 0's frame F (input for F + DELAY) is complete at the start of F + 1
    RbPlayer* me = &g_rb.pl[g_rb.me];
    unsigned t = f + g_rb.delay;
    RbFrame* r = rb_frame(me, t);
    if (!r)
        return;
    if (g_rb.k == 0 && !r->have) {       // no read at all in the frame: no change
        r->off = me->npool;
        r->nchg = 0;
    }
    r->have = 1;
    r->fin = rb_state_at(me, t, 255);
    me->through = t + 1;
}

static void rb_stats(int final)
{
    unsigned avg = g_hs.rtt_n ? (unsigned)(g_hs.rtt_sum / g_hs.rtt_n) : 0;
    hs_log("rb stats frame %u: rollbacks %u, resimulated %u frames (%llu us total, %llu us per frame), predicted %u frames, "
           "mispredicted %u, cannot-rollback %u, stalls %u (%llu ms), save %llu us avg (%u), restore %llu us avg (%u), "
           "hash %llu us avg (%u), hashes ok %u bad %u (big hash bad %u, first bad %d), rtt avg %u max %u ms, "
           "advantage %.2f, throttled %u, hitches>50ms %u, worst gap %llu ms, fiber barriers %u (%llu ms), pkts out %u in %u%s",
           g_rb.max_sim, g_rb.rollbacks, g_rb.resim_frames, (unsigned long long)(g_rb.resim_ns / 1000),
           (unsigned long long)(g_rb.resim_frames ? g_rb.resim_ns / 1000 / g_rb.resim_frames : 0), g_rb.predicted,
           g_rb.mispredicted, g_rb.cant, g_rb.stalls, (unsigned long long)(g_rb.stall_ns / 1000000),
           (unsigned long long)(g_rb.save_n ? g_rb.save_ns / 1000 / g_rb.save_n : 0), g_rb.save_n,
           (unsigned long long)(g_rb.restore_n ? g_rb.restore_ns / 1000 / g_rb.restore_n : 0), g_rb.restore_n,
           (unsigned long long)(g_rb.hash_n ? g_rb.hash_ns / 1000 / g_rb.hash_n : 0), g_rb.hash_n, g_rb.hash_ok,
           g_rb.hash_bad, g_rb.big_bad, (int)g_rb.first_bad, avg, g_hs.rtt_max, g_rb.adv, g_rb.throttled, g_rb.hitches,
           (unsigned long long)(g_rb.gap_max_ns / 1000000), g_rb.barriers, (unsigned long long)(g_rb.barrier_ns / 1000000),
           g_hs.pkts_out,
           g_hs.pkts_in, final ? " (final)" : "");
    for (unsigned d = 0; d < kRbMaxSlots; d++)
        if (g_rb.depth[d])
            hs_log("rb depth %u: %u", d, g_rb.depth[d]);
}

// hashes: frame F's hashes are final once every input before F is known (and was used: no rollback pending)
static void rb_hash_final(void)
{
    if (!g_hs.hash_every || g_rb.resim || g_rb.pending != 0xffffffffu)
        return;
    unsigned upto = g_rb.pl[!g_rb.me].through;   // frames < upto have their real remote input
    if (upto > g_rb.max_sim)
        upto = g_rb.max_sim;
    // frame F's state depends on frames < F: final for F <= upto
    for (unsigned F = (g_rb.final_through / g_hs.hash_every + 1) * g_hs.hash_every; F <= upto; F += g_hs.hash_every) {
        unsigned j = F / g_hs.hash_every;
        if (j >= g_rb.hcap || !(g_rb.hs_have[j] & 1))
            break;
        g_rb.hs_have[j] |= 2;
        g_rb.final_through = F;
    }
    for (unsigned j = 0; j < g_rb.hcap; j++) {
        unsigned char& h = g_rb.hs_have[j];
        if ((h & 6) != 6 || (h & 8))
            continue;
        h |= 8;
        int ok = g_rb.hs_small[j] == g_rb.hr_small[j];
        int big = g_rb.hs_big[j] == g_rb.hr_big[j];
        if (ok)
            g_rb.hash_ok++;
        else {
            g_rb.hash_bad++;
            if (g_rb.first_bad == 0xffffffffu)
                g_rb.first_bad = j * g_hs.hash_every;
        }
        if (!big)
            g_rb.big_bad++;
        hs_log("net hash frame %u local %08x remote %08x %s big %08x %08x %s", j * g_hs.hash_every, g_rb.hs_small[j],
               g_rb.hr_small[j], ok ? "ok" : "DIVERGED", g_rb.hs_big[j], g_rb.hr_big[j], big ? "same" : "DIFFERS");
    }
}

unsigned hulk_session_rb_frame(unsigned F, const HulkSnapOps* ops)
{
    rb_init();
    if (g_hs.failed)
        return F;
    RbPlayer* re = &g_rb.pl[!g_rb.me];
    unsigned slots = ops->slots < kRbMaxSlots ? ops->slots : kRbMaxSlots;
    if (g_rb.window + 2 > slots)
        g_rb.window = slots - 2;
    // the frame that just ended (F - 1) on its first simulation: my player 0's input for it is complete
    if (F && F == g_rb.max_sim && !g_rb.resim && g_rb.me == 0)
        rb_close_local(F - 1);
    if (g_rb.resim && F == g_rb.resim_to) {
        g_rb.resim = 0;
        g_rb.resim_ns += SDL_GetTicksNS() - g_rb.resim_t0;
    }
    if (!g_rb.resim) {
        rb_pump();
        if (g_rb.pending != 0xffffffffu) {
            unsigned m = g_rb.pending;
            g_rb.pending = 0xffffffffu;
            if (m < F) {
                Uint64 t = SDL_GetTicksNS();
                if (F - m < slots && g_rb.slot_frame[m % slots] == m && ops->restore(m % slots, m)) {
                    g_rb.restore_ns += SDL_GetTicksNS() - t;
                    g_rb.restore_n++;
                    g_rb.rollbacks++;
                    g_rb.depth[F - m < kRbMaxSlots ? F - m : kRbMaxSlots - 1]++;
                    g_rb.resim_frames += F - m;
                    g_rb.resim = 1;
                    g_rb.resim_to = F;
                    g_rb.resim_t0 = t;
                    F = m;
                } else {
                    g_rb.cant++;
                    hs_log("rb: frame %u: cannot roll back to frame %u (no snapshot): the instances will part", F, m);
                }
            }
        }
    }
    int fresh = F >= g_rb.max_sim;
    // a fiber ran or a drive request was posted in the frame that just ended: no rollback can cross it, so before going on every input
    // up to here must be known (and any wrong prediction fixed now, while a restore still can)
    if (fresh && !g_rb.resim && ops->fibers) {
        unsigned fb = ops->fibers();
        if (fb != g_rb.fibers_seen) {
            g_rb.fibers_seen = fb;
            Uint64 t0 = SDL_GetTicksNS();
            g_rb.barriers++;
            while (!g_hs.failed && re->through < F) {
                rb_pump();
                if (SDL_GetTicks() - g_rb.last_send_ms >= 10)
                    rb_send();
                if (hs_timed_out())
                    break;
                SDL_DelayNS(250000);
            }
            g_rb.barrier_ns += SDL_GetTicksNS() - t0;
            if (g_rb.pending != 0xffffffffu && g_rb.pending < F) {
                g_rb.cant++;
                hs_log("rb: frame %u: a misprediction at frame %u lies before a fiber run or a drive post: no rollback possible",
                       F, g_rb.pending);
                g_rb.pending = 0xffffffffu;
            }
        }
    }
    if (fresh && !g_rb.resim) {
        // the prediction window: wait while the peer's input is more than WINDOW frames behind
        Uint64 t0 = 0;
        while (!g_hs.failed && F >= re->through + g_rb.window) {
            if (!t0)
                t0 = SDL_GetTicksNS();
            rb_pump();
            if (SDL_GetTicks() - g_rb.last_send_ms >= 10)
                rb_send();
            if (hs_timed_out())
                break;
            SDL_DelayNS(250000);
        }
        if (t0) {
            g_rb.stalls++;
            g_rb.stall_ns += SDL_GetTicksNS() - t0;
        }
        if (g_rb.pending != 0xffffffffu && g_rb.pending < F) {
            // inputs that arrived while waiting proved a prediction wrong: roll back at once
            unsigned m = g_rb.pending;
            g_rb.pending = 0xffffffffu;
            Uint64 t = SDL_GetTicksNS();
            if (F - m < slots && g_rb.slot_frame[m % slots] == m && ops->restore(m % slots, m)) {
                g_rb.restore_ns += SDL_GetTicksNS() - t;
                g_rb.restore_n++;
                g_rb.rollbacks++;
                g_rb.depth[F - m < kRbMaxSlots ? F - m : kRbMaxSlots - 1]++;
                g_rb.resim_frames += F - m;
                g_rb.resim = 1;
                g_rb.resim_to = F;
                g_rb.resim_t0 = t;
                F = m;
                fresh = 0;
            } else
                g_rb.cant++;
        }
        // the session's pacing: one new frame per 1/fps s (a frame that is late resets the deadline: no catching up)
        if (fresh && g_rb.fps) {
            Uint64 period = 1000000000ull / g_rb.fps, now = SDL_GetTicksNS();
            if (!g_rb.deadline_ns || now > g_rb.deadline_ns + 2 * period)
                g_rb.deadline_ns = now;
            g_rb.deadline_ns += period;
            if (now < g_rb.deadline_ns)
                SDL_DelayPrecise(g_rb.deadline_ns - now);
            now = SDL_GetTicksNS();
            if (g_rb.last_fresh_ns) {
                Uint64 gap = now - g_rb.last_fresh_ns;
                if (gap > g_rb.gap_max_ns)
                    g_rb.gap_max_ns = gap;
                if (gap > 50000000ull)
                    g_rb.hitches++;
            }
            g_rb.last_fresh_ns = now;
        }
        // frame advantage (GGPO's time sync): ahead of the peer by more than a frame on average: give a quarter frame
        if (fresh && g_rb.peer_tsend_at) {
            double remote = g_rb.peer_frame + (double)(SDL_GetTicks() - g_rb.peer_tsend_at + g_hs.rtt_last / 2) / 33.333;
            g_rb.adv = g_rb.adv * 0.95 + ((double)F - remote) * 0.05;
            if (g_rb.adv > 1.0) {
                g_rb.throttled++;
                SDL_DelayNS(8000000);
            }
        }
    }
    // the snapshot of F's start (every simulation of F: a later rollback may need it)
    Uint64 t = SDL_GetTicksNS();
    if (ops->save(F % slots, F))
        g_rb.slot_frame[F % slots] = F;
    g_rb.save_ns += SDL_GetTicksNS() - t;
    g_rb.save_n++;
    // F's inputs: the remote player's real input, or the prediction (the last state known)
    unsigned cap = g_rb.predcap;
    void* a = rb_grow(g_rb.pred, &cap, F + 1, sizeof(HulkPadState));
    if (a) {
        g_rb.pred = (HulkPadState*)a;
        cap = g_rb.predcap;
        a = rb_grow(g_rb.used_pred, &cap, F + 1, 1);
        if (a) {
            g_rb.used_pred = (unsigned char*)a;
            cap = g_rb.predcap;
            a = rb_grow(g_rb.reads, &cap, F + 1, 1);
            if (a) {
                g_rb.reads = (unsigned char*)a;
                g_rb.predcap = cap;
            }
        }
    }
    if (F < g_rb.predcap) {
        g_rb.reads[F] = 0;
        if (F < re->through)
            g_rb.used_pred[F] = 0;
        else {
            if (re->through)
                g_rb.pred[F] = re->f[re->through - 1].fin;
            else
                SDL_zero(g_rb.pred[F]);
            if (!g_rb.used_pred[F] && fresh)
                g_rb.predicted++;
            g_rb.used_pred[F] = 1;
        }
    }
    // my player 1's input for F + DELAY (first simulation only)
    if (g_rb.me == 1 && fresh && !g_rb.resim) {
        RbPlayer* me = &g_rb.pl[1];
        unsigned tf = F + g_rb.delay;
        RbFrame* r = rb_frame(me, tf);
        if (r && !r->have) {
            HulkPadState s, prev;
            rb_gen_p1(tf, &s);
            if (tf)
                prev = me->f[tf - 1].fin;
            else
                SDL_zero(prev);
            r->off = me->npool;
            r->nchg = 0;
            if (SDL_memcmp(&s, &prev, sizeof(s)) && rb_add_chg(me, 0, &s))
                r->nchg = 1;
            r->fin = s;
            r->have = 1;
            me->through = tf + 1;
        }
    }
    g_rb.cur = F;
    g_rb.k = 0;
    if (fresh)
        g_rb.max_sim = F + 1;
    // the hashes of F's start (recomputed by every simulation of F)
    if (g_hs.hash_every && F % g_hs.hash_every == 0) {
        unsigned j = F / g_hs.hash_every, hc = g_rb.hcap;
        int okg = 1;
        unsigned* p1 = (unsigned*)rb_grow(g_rb.hs_small, &hc, j + 1, 4);
        okg &= p1 != 0;
        if (p1)
            g_rb.hs_small = p1;
        hc = g_rb.hcap;
        unsigned* p2 = (unsigned*)rb_grow(g_rb.hs_big, &hc, j + 1, 4);
        okg &= p2 != 0;
        if (p2)
            g_rb.hs_big = p2;
        hc = g_rb.hcap;
        unsigned* p3 = (unsigned*)rb_grow(g_rb.hr_small, &hc, j + 1, 4);
        okg &= p3 != 0;
        if (p3)
            g_rb.hr_small = p3;
        hc = g_rb.hcap;
        unsigned* p4 = (unsigned*)rb_grow(g_rb.hr_big, &hc, j + 1, 4);
        okg &= p4 != 0;
        if (p4)
            g_rb.hr_big = p4;
        hc = g_rb.hcap;
        unsigned char* p5 = (unsigned char*)rb_grow(g_rb.hs_have, &hc, j + 1, 1);
        okg &= p5 != 0;
        if (p5)
            g_rb.hs_have = p5;
        if (okg) {
            g_rb.hcap = hc;
            Uint64 th = SDL_GetTicksNS();
            g_rb.hs_small[j] = ops->hash_small(F);
            g_rb.hs_big[j] = ops->hash_big();
            g_rb.hash_ns += SDL_GetTicksNS() - th;
            g_rb.hash_n++;
            g_rb.hs_have[j] |= 1;
        }
    }
    if (!g_rb.resim) {
        rb_hash_final();
        rb_send();
        if (F % HS_LOG_EVERY == 0 && fresh)
            rb_stats(0);
    }
    return F;
}
