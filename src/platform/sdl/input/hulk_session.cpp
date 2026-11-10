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
    const char* role = SDL_getenv("HULK_NET");
    if (role && SDL_strcmp(role, "send") == 0)
        g_hs.role = 1;
    else if (role && SDL_strcmp(role, "recv") == 0)
        g_hs.role = 2;
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
                hs_log("net: role %s, port %u, peer %s, lead %u, redundancy %u, hash every %u", g_hs.role == 1 ? "send" : "recv",
                       port, peer, g_hs.lead, g_hs.redundancy, g_hs.hash_every);
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
    return g_hs.role != 0;
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
    if (g_hs.role == 0 || g_hs.failed)
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
    if (g_hs.role == 0)
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

static int ws_read(void* self, unsigned port, HulkPadState* out)
{
    int ret = g_hs_inner->read(g_hs_inner->self, port, out);
    if (port >= HULK_INPUT_PORTS)
        return ret;
    unsigned idx = g_hs.reads++;
    if (g_hs.role == 2)
        return hs_recv_read(idx, port, out);
#if HS_CONTROL_PORT
    if (g_ctl.ovr[port].on) {
        *out = g_ctl.ovr[port].s;
        ret = 1;
    }
#endif
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
    if (g_hs.role == 0)
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
