// Native replay: a hybrid recording as an input source, and checkpoint hashing. See hulk_replay.h and
// docs/native-replay.md. Included by input/hulk_input.cpp (one translation unit with the input backend).
//
// No C++ dynamic initializers (the native image runs only the game's initializer table): plain static data.
#include "hulk_replay.h"

#include <SDL3/SDL.h>

// the recording's hybrid flag bits we look at (tools/patch_xbe.py HF; seq-rng and rng-log have no runtime bit
// there, the .hrp format gives them one)
enum { RF_AUTOSTART = 16, RF_POLLKEY = 64, RF_VPAD = 2048, RF_SEQ_RNG = 1 << 13, RF_RNG_LOG = 1 << 14 };

struct Entry {
    unsigned key;                // poll number or frame from which the state applies
    unsigned short buttons;
    unsigned char analog[8];
    short thumb[4];
};

struct Ckpt {
    unsigned frame, hash;
};

static struct {
    int open;
    char err[160];
    Entry* e;
    unsigned n, cap;
    Ckpt* ck;
    unsigned nck, ckcap;
    int frame_keyed, autostart;
    unsigned vpad_count, seed, tweaks, flags, ckpt_interval;
    // run state
    unsigned pos, polls, frame, last_frame, frozen;
    int press_start_ok;
    int frame_seen;              // hulk_replay_set_frame has been called (the auto-START rule needs the frame counter)
    unsigned rumbles;
} g_rp;

static void rp_free()
{
    SDL_free(g_rp.e);
    SDL_free(g_rp.ck);
    SDL_memset(&g_rp, 0, sizeof(g_rp));
    g_rp.press_start_ok = 1;
}

static int rp_fail(const char* why)
{
    SDL_snprintf(g_rp.err, sizeof(g_rp.err), "%s", why);
    g_rp.open = 0;
    return 0;
}

static bool rp_add(const Entry& v)
{
    if (g_rp.n == g_rp.cap) {
        unsigned cap = g_rp.cap ? g_rp.cap * 2 : 1024;
        Entry* e = (Entry*)SDL_realloc(g_rp.e, cap * sizeof(Entry));
        if (!e)
            return false;
        g_rp.e = e;
        g_rp.cap = cap;
    }
    g_rp.e[g_rp.n++] = v;
    return true;
}

static bool rp_add_ck(unsigned frame, unsigned hash)
{
    if (g_rp.nck == g_rp.ckcap) {
        unsigned cap = g_rp.ckcap ? g_rp.ckcap * 2 : 256;
        Ckpt* c = (Ckpt*)SDL_realloc(g_rp.ck, cap * sizeof(Ckpt));
        if (!c)
            return false;
        g_rp.ck = c;
        g_rp.ckcap = cap;
    }
    g_rp.ck[g_rp.nck].frame = frame;
    g_rp.ck[g_rp.nck].hash = hash;
    g_rp.nck++;
    return true;
}

// ---------------------------------------------------------------------------------------------
// JSON: just enough for the recording shapes (objects, arrays, integers, strings, true/false/null)
struct J {
    const char* p;
    const char* end;
    bool bad;
};

static void j_ws(J& j)
{
    while (j.p < j.end && (*j.p == ' ' || *j.p == '\n' || *j.p == '\t' || *j.p == '\r'))
        j.p++;
}

static bool j_eat(J& j, char c)
{
    j_ws(j);
    if (j.p < j.end && *j.p == c) {
        j.p++;
        return true;
    }
    return false;
}

static bool j_peek(J& j, char c)
{
    j_ws(j);
    return j.p < j.end && *j.p == c;
}

// an integer (a fraction or exponent is consumed and dropped: times in a timeline are not ours)
static bool j_int(J& j, long long* v)
{
    j_ws(j);
    const char* s = j.p;
    bool neg = false;
    if (j.p < j.end && (*j.p == '-' || *j.p == '+'))
        neg = *j.p++ == '-';
    long long x = 0;
    int digits = 0;
    while (j.p < j.end && *j.p >= '0' && *j.p <= '9') {
        x = x * 10 + (*j.p++ - '0');
        digits++;
    }
    if (!digits) {
        j.p = s;
        j.bad = true;
        return false;
    }
    while (j.p < j.end && (*j.p == '.' || *j.p == 'e' || *j.p == 'E' || *j.p == '-' || *j.p == '+' ||
                           (*j.p >= '0' && *j.p <= '9')))
        j.p++;
    *v = neg ? -x : x;
    return true;
}

static bool j_str(J& j, char* out, int cap)
{
    if (!j_eat(j, '"')) {
        j.bad = true;
        return false;
    }
    int n = 0;
    while (j.p < j.end && *j.p != '"') {
        char c = *j.p++;
        if (c == '\\' && j.p < j.end)
            c = *j.p++;
        if (out && n + 1 < cap)
            out[n++] = c;
    }
    if (out)
        out[n] = 0;
    if (j.p >= j.end) {
        j.bad = true;
        return false;
    }
    j.p++;
    return true;
}

static void j_skip(J& j)
{
    j_ws(j);
    if (j.p >= j.end) {
        j.bad = true;
        return;
    }
    char c = *j.p;
    if (c == '"') {
        j_str(j, 0, 0);
    } else if (c == '[' || c == '{') {
        char close = c == '[' ? ']' : '}';
        j.p++;
        if (j_eat(j, close))
            return;
        for (;;) {
            if (c == '{') {
                j_str(j, 0, 0);
                if (!j_eat(j, ':'))
                    j.bad = true;
            }
            j_skip(j);
            if (j.bad)
                return;
            if (j_eat(j, ','))
                continue;
            if (!j_eat(j, close))
                j.bad = true;
            return;
        }
    } else {
        while (j.p < j.end && *j.p != ',' && *j.p != ']' && *j.p != '}' && *j.p != ' ' && *j.p != '\n' &&
               *j.p != '\r' && *j.p != '\t')
            j.p++;
    }
}

// [n, n, ...] into out (at most cap values; the rest are skipped); returns how many were read
static int j_ints(J& j, long long* out, int cap)
{
    int n = 0;
    if (!j_eat(j, '[')) {
        j.bad = true;
        return 0;
    }
    if (j_eat(j, ']'))
        return 0;
    for (;;) {
        long long v = 0;
        if (!j_int(j, &v))
            return n;
        if (n < cap)
            out[n] = v;
        n++;
        if (j_eat(j, ','))
            continue;
        if (!j_eat(j, ']'))
            j.bad = true;
        return n < cap ? n : cap;
    }
}

// [key, buttons, [analog...], [thumbs...]]; the legacy files leave out trailing zeros of the lists
static bool j_entry(J& j)
{
    Entry e;
    SDL_memset(&e, 0, sizeof(e));
    if (!j_eat(j, '[')) {
        j.bad = true;
        return false;
    }
    long long v = 0;
    long long a[8] = {0}, t[4] = {0};
    if (!j_int(j, &v))
        return false;
    e.key = (unsigned)v;
    if (j_eat(j, ',')) {
        if (!j_int(j, &v))
            return false;
        e.buttons = (unsigned short)v;
        if (j_eat(j, ',')) {
            j_ints(j, a, 8);
            if (j_eat(j, ','))
                j_ints(j, t, 4);
        }
    }
    if (!j_eat(j, ']')) {
        j.bad = true;
        return false;
    }
    for (int i = 0; i < 8; i++)
        e.analog[i] = (unsigned char)a[i];
    for (int i = 0; i < 4; i++)
        e.thumb[i] = (short)t[i];
    return rp_add(e);
}

static bool j_entries(J& j)
{
    if (!j_eat(j, '[')) {
        j.bad = true;
        return false;
    }
    if (j_eat(j, ']'))
        return true;
    for (;;) {
        if (!j_entry(j))
            return false;
        if (j_eat(j, ','))
            continue;
        if (!j_eat(j, ']')) {
            j.bad = true;
            return false;
        }
        return true;
    }
}

// checkpoints: [[frame, hash], ...] or {"frame": hash, ...}
static bool j_ckpts(J& j)
{
    bool obj = j_peek(j, '{');
    if (!j_eat(j, obj ? '{' : '[')) {
        j.bad = true;
        return false;
    }
    if (j_eat(j, obj ? '}' : ']'))
        return true;
    for (;;) {
        long long f = 0, h = 0;
        if (obj) {
            char k[24];
            if (!j_str(j, k, sizeof(k)) || !j_eat(j, ':') || !j_int(j, &h))
                return false;
            f = SDL_strtoul(k, 0, 10);
        } else {
            long long v[2] = {0, 0};
            if (j_ints(j, v, 2) != 2)
                return false;
            f = v[0];
            h = v[1];
        }
        rp_add_ck((unsigned)f, (unsigned)h);
        if (j_eat(j, ','))
            continue;
        if (!j_eat(j, obj ? '}' : ']')) {
            j.bad = true;
            return false;
        }
        return true;
    }
}

static unsigned flag_bit(const char* s)
{
    static const struct { const char* n; unsigned b; } kFlags[] = {
        {"fixed-dt", 1}, {"replay", 2}, {"record", 4}, {"ckpt", 8}, {"autostart", 16}, {"wide", 32},
        {"pollkey", 64}, {"vclock", 128}, {"iosync", 256}, {"sound-rng", 512}, {"quant", 1024}, {"vpad", 2048},
        {"vdate", 4096}, {"seq-rng", RF_SEQ_RNG}, {"rng-log", RF_RNG_LOG},
    };
    for (unsigned i = 0; i < sizeof(kFlags) / sizeof(kFlags[0]); i++)
        if (SDL_strcmp(kFlags[i].n, s) == 0)
            return kFlags[i].b;
    return 0;
}

static unsigned tweak_bit(const char* s)
{
    return SDL_strcmp(s, "skip-intro") == 0 ? 1u : SDL_strcmp(s, "no-fmv") == 0 ? 2u : 0u;
}

static bool j_names(J& j, unsigned (*bit)(const char*), unsigned* acc)
{
    if (!j_eat(j, '[')) {
        j_skip(j);                     // (older files: a number or null)
        return !j.bad;
    }
    if (j_eat(j, ']'))
        return true;
    for (;;) {
        char s[32];
        if (j_peek(j, '"')) {
            if (!j_str(j, s, sizeof(s)))
                return false;
            *acc |= bit(s);
        } else {
            j_skip(j);
        }
        if (j_eat(j, ','))
            continue;
        if (!j_eat(j, ']')) {
            j.bad = true;
            return false;
        }
        return true;
    }
}

static int rp_parse_json(const char* data, unsigned long size)
{
    J j = {data, data + size, false};
    if (j_peek(j, '[')) {                          // tests/replays/*.json: the bare list, frame-keyed, auto-START
        if (!j_entries(j))
            return rp_fail("replay: bad entry list");
        g_rp.frame_keyed = 1;
        g_rp.autostart = 1;
        g_rp.flags = RF_AUTOSTART;
        return 1;
    }
    if (!j_eat(j, '{'))
        return rp_fail("replay: not a recording (JSON object or list expected)");
    bool pollkey = false, have_entries = false;
    if (!j_eat(j, '}')) {
        for (;;) {
            char key[32];
            long long v = 0;
            if (!j_str(j, key, sizeof(key)) || !j_eat(j, ':'))
                return rp_fail("replay: bad JSON");
            if (SDL_strcmp(key, "inputs") == 0) {
                if (!j_entries(j))
                    return rp_fail("replay: bad inputs");
                have_entries = true;
            } else if (SDL_strcmp(key, "checkpoints") == 0) {
                if (!j_ckpts(j))
                    return rp_fail("replay: bad checkpoints");
            } else if (SDL_strcmp(key, "flags") == 0) {
                if (!j_names(j, flag_bit, &g_rp.flags))
                    return rp_fail("replay: bad flags");
            } else if (SDL_strcmp(key, "tweaks") == 0) {
                if (!j_names(j, tweak_bit, &g_rp.tweaks))
                    return rp_fail("replay: bad tweaks");
            } else if (SDL_strcmp(key, "key") == 0) {
                char s[16];
                if (!j_str(j, s, sizeof(s)))
                    return rp_fail("replay: bad key");
                pollkey = SDL_strcmp(s, "polls") == 0;
            } else if (SDL_strcmp(key, "seed") == 0) {
                if (!j_int(j, &v))
                    return rp_fail("replay: bad seed");
                g_rp.seed = (unsigned)v;
            } else if (SDL_strcmp(key, "vpad_count") == 0) {
                if (!j_int(j, &v))
                    return rp_fail("replay: bad vpad_count");
                g_rp.vpad_count = (unsigned)v;
            } else {
                j_skip(j);
            }
            if (j.bad)
                return rp_fail("replay: bad JSON");
            if (j_eat(j, ','))
                continue;
            if (!j_eat(j, '}'))
                return rp_fail("replay: bad JSON (object not closed)");
            break;
        }
    }
    if (!have_entries)
        return rp_fail("replay: no inputs");
    g_rp.frame_keyed = !(pollkey || (g_rp.flags & RF_POLLKEY));
    g_rp.autostart = (g_rp.flags & RF_AUTOSTART) != 0;
    return 1;
}

// ---------------------------------------------------------------------------------------------
// .hrp (tools/replay_pack.py): little endian
//   0  "HRP1"   4  u16 version (1)   6  u16 key (0 polls, 1 frames)   8  u32 vpad_count   12 u32 flags
//   16 u32 ckpt_interval   20 u32 seed   24 u32 tweaks   28 u32 entries   32 u32 checkpoints
//   36 entries x 24: u32 key, u16 buttons, u8 analog[8], s16 thumb[4], u16 0     then checkpoints x 8: u32 frame, u32 hash
static unsigned rd32(const unsigned char* p)
{
    return p[0] | (p[1] << 8) | (p[2] << 16) | ((unsigned)p[3] << 24);
}

static unsigned rd16(const unsigned char* p)
{
    return p[0] | (p[1] << 8);
}

static int rp_parse_hrp(const unsigned char* d, unsigned long size)
{
    if (size < 36 || rd16(d + 4) != 1)
        return rp_fail("replay: bad .hrp header");
    g_rp.frame_keyed = rd16(d + 6) == 1;
    g_rp.vpad_count = rd32(d + 8);
    g_rp.flags = rd32(d + 12);
    g_rp.ckpt_interval = rd32(d + 16);
    g_rp.seed = rd32(d + 20);
    g_rp.tweaks = rd32(d + 24);
    unsigned long n = rd32(d + 28), nc = rd32(d + 32);
    if (size < 36 + n * 24 + nc * 8)
        return rp_fail("replay: truncated .hrp");
    g_rp.autostart = (g_rp.flags & RF_AUTOSTART) != 0;
    const unsigned char* p = d + 36;
    for (unsigned long i = 0; i < n; i++, p += 24) {
        Entry e;
        e.key = rd32(p);
        e.buttons = (unsigned short)rd16(p + 4);
        for (int k = 0; k < 8; k++)
            e.analog[k] = p[6 + k];
        for (int k = 0; k < 4; k++)
            e.thumb[k] = (short)rd16(p + 14 + 2 * k);
        if (!rp_add(e))
            return rp_fail("replay: out of memory");
    }
    for (unsigned long i = 0; i < nc; i++, p += 8)
        rp_add_ck(rd32(p), rd32(p + 4));
    return 1;
}

// ---------------------------------------------------------------------------------------------
int hulk_replay_open_memory(const void* data, unsigned long size)
{
    rp_free();
    const unsigned char* d = (const unsigned char*)data;
    int ok;
    if (size >= 4 && d[0] == 'H' && d[1] == 'R' && d[2] == 'P' && d[3] == '1')
        ok = rp_parse_hrp(d, size);
    else
        ok = rp_parse_json((const char*)data, size);
    if (!ok) {
        char err[sizeof(g_rp.err)];
        SDL_memcpy(err, g_rp.err, sizeof(err));
        rp_free();
        SDL_memcpy(g_rp.err, err, sizeof(err));
        return 0;
    }
    if (g_rp.vpad_count == 0)
        g_rp.vpad_count = 1;
    if (g_rp.vpad_count > HULK_INPUT_PORTS)
        g_rp.vpad_count = HULK_INPUT_PORTS;
    if (!g_rp.ckpt_interval)
        g_rp.ckpt_interval = 30;
    g_rp.open = 1;
    g_rp.press_start_ok = 1;
    return 1;
}

int hulk_replay_open(const char* path)
{
    size_t size = 0;
    void* data = SDL_LoadFile(path, &size);
    if (!data) {
        rp_free();
        SDL_snprintf(g_rp.err, sizeof(g_rp.err), "replay: cannot read %s: %s", path, SDL_GetError());
        return 0;
    }
    int ok = hulk_replay_open_memory(data, size);
    SDL_free(data);
    return ok;
}

void hulk_replay_close(void)
{
    rp_free();
}

const char* hulk_replay_error(void)
{
    return g_rp.err;
}

int hulk_replay_info(HulkReplayInfo* o)
{
    if (!g_rp.open)
        return 0;
    o->frame_keyed = g_rp.frame_keyed;
    o->autostart = g_rp.autostart;
    o->vpad_count = g_rp.vpad_count;
    o->seed = g_rp.seed;
    o->tweaks = g_rp.tweaks;
    o->flags = g_rp.flags;
    o->ckpt_interval = g_rp.ckpt_interval;
    o->entries = g_rp.n;
    o->checkpoints = g_rp.nck;
    o->polls = g_rp.polls;
    o->pos = g_rp.pos;
    return 1;
}

void hulk_replay_set_frame(unsigned frame)
{
    g_rp.frame = frame;
    g_rp.frame_seen = 1;
}

void hulk_replay_set_press_start_ok(int ok)
{
    g_rp.press_start_ok = ok;
}

int hulk_replay_expected_hash(unsigned frame, unsigned* hash)
{
    unsigned lo = 0, hi = g_rp.nck;
    // checkpoints are in frame order in every recording; fall back to a scan if not
    while (lo < hi) {
        unsigned mid = (lo + hi) / 2;
        if (g_rp.ck[mid].frame < frame)
            lo = mid + 1;
        else
            hi = mid;
    }
    if (lo < g_rp.nck && g_rp.ck[lo].frame == frame) {
        *hash = g_rp.ck[lo].hash;
        return 1;
    }
    for (unsigned i = 0; i < g_rp.nck; i++)
        if (g_rp.ck[i].frame == frame) {
            *hash = g_rp.ck[i].hash;
            return 1;
        }
    return 0;
}

// ---------------------------------------------------------------------------------------------
// the input source: hybrid_xinput_get_state's replay branch
static void rs_update(void*) {}

static unsigned rs_connected(void*)
{
    return g_rp.open ? (1u << g_rp.vpad_count) - 1 : 0;
}

static unsigned rs_generation(void*, unsigned port)
{
    return g_rp.open && port < g_rp.vpad_count ? 1 : 0;
}

static void entry_to_state(const Entry* e, HulkPadState* s)
{
    SDL_memset(s, 0, sizeof(*s));
    if (!e)
        return;
    s->buttons = e->buttons;
    for (int i = 0; i < 8; i++)
        s->analog[i] = e->analog[i];
    for (int i = 0; i < 4; i++)
        s->thumb[i] = e->thumb[i];
}

static int rs_read(void*, unsigned port, HulkPadState* s)
{
    if (!g_rp.open || port >= g_rp.vpad_count)
        return 0;
    g_rp.polls++;                                         // one poll, whichever pad it is (the stream is shared)
    unsigned key = g_rp.frame_keyed ? g_rp.frame : g_rp.polls;
    unsigned pos = g_rp.pos;
    while (pos + 1 < g_rp.n && g_rp.e[pos + 1].key <= key)
        pos++;
    g_rp.pos = pos;
    const Entry* e = pos < g_rp.n && g_rp.e[pos].key <= key ? &g_rp.e[pos] : 0;
    entry_to_state(e, s);
    if (g_rp.frame != g_rp.last_frame) {
        g_rp.last_frame = g_rp.frame;
        g_rp.frozen = 0;
    } else if (++g_rp.frozen > 60 && g_rp.autostart && g_rp.frame_seen && g_rp.press_start_ok) {
        // the game loop is stalled (a loading screen): release everything, then tap START
        entry_to_state(0, s);
        if ((g_rp.frozen >> 3) & 1)
            s->buttons = HULK_PAD_START;
    }
    return 1;
}

// the pad-init reads (ControllerSystemXBox's constructor of a pad object reads the new pad 20 times): zeros,
// not polls (hybrid_xinput_get_state_init)
static int rs_read_init(void*, unsigned port, HulkPadState* s)
{
    if (!g_rp.open || port >= g_rp.vpad_count)
        return 0;
    entry_to_state(0, s);
    return 1;
}

static void rs_rumble(void*, unsigned, unsigned short, unsigned short)
{
    g_rp.rumbles++;
}

static const HulkInputSource kReplaySource = {"replay", 0, rs_update, rs_connected, rs_generation, rs_read, rs_rumble,
                                              rs_read_init};

const HulkInputSource* hulk_replay_source(void)
{
    return &kReplaySource;
}

// ---------------------------------------------------------------------------------------------
// checkpoints
unsigned hulk_fnv1a(unsigned h, const void* data, unsigned long n)
{
    const unsigned char* p = (const unsigned char*)data;
    for (unsigned long i = 0; i < n; i++)
        h = (h ^ p[i]) * 16777619u;
    return h;
}

unsigned hulk_ckpt_hash(unsigned frame, const HulkCkptState* s)
{
    unsigned char fb[4] = {(unsigned char)frame, (unsigned char)(frame >> 8), (unsigned char)(frame >> 16),
                           (unsigned char)(frame >> 24)};
    unsigned h = hulk_fnv1a(2166136261u, fb, 4);
    if (s->rng)
        h = hulk_fnv1a(h, s->rng, 8);
    if (s->boot_step)
        h = hulk_fnv1a(h, s->boot_step, 4);
    if (s->camera_ptr && *s->camera_ptr)
        h = hulk_fnv1a(h, (const unsigned char*)*s->camera_ptr + 0x4c, 12);
    if (s->clock) {
        unsigned char c[0x30];
        SDL_memcpy(c, (const unsigned char*)s->clock + 0x10, sizeof(c));
        if (s->clock_at_entry)
            SDL_memset(c + (0x28 - 0x10), 0, 16);        // step, scaledStep
        h = hulk_fnv1a(h, c, sizeof(c));
    }
    return h;
}

static struct {
    int inited;
    unsigned interval;
    HulkCkptStats st;
} g_ck;

static void ck_init()
{
    if (g_ck.inited)
        return;
    g_ck.inited = 1;
    g_ck.st.first_bad_frame = 0xffffffffu;
    const char* e = SDL_getenv("HULK_CKPT");
    if (!e || !*e || SDL_strcmp(e, "0") == 0 || SDL_strcmp(e, "off") == 0)
        return;
    unsigned v = (unsigned)SDL_strtoul(e, 0, 10);
    g_ck.interval = v > 1 ? v : 30;                      // "1" and "on": the hybrid default
    SDL_Log("ckpt: hashing every %u frames", g_ck.interval);
}

void hulk_ckpt_reset(unsigned interval)
{
    SDL_memset(&g_ck, 0, sizeof(g_ck));
    g_ck.inited = 1;
    g_ck.interval = interval;
    g_ck.st.first_bad_frame = 0xffffffffu;
}

void hulk_ckpt_stats(HulkCkptStats* out)
{
    ck_init();
    *out = g_ck.st;
}

int hulk_ckpt_update(const HulkCkptState* s)
{
    ck_init();
    unsigned f = g_ck.st.frame;
    int r = -1;
    if (g_ck.interval && f % g_ck.interval == 0) {
        unsigned h = hulk_ckpt_hash(f, s), want = 0;
        g_ck.st.checked++;
        g_ck.st.last_hash = h;
        if (!hulk_replay_expected_hash(f, &want)) {
            g_ck.st.unmatched++;
            r = 1;
        } else if (want == h) {
            g_ck.st.matched++;
            r = 1;
        } else {
            g_ck.st.mismatched++;
            if (g_ck.st.first_bad_frame == 0xffffffffu)
                g_ck.st.first_bad_frame = f;
            if (g_ck.st.mismatched <= 8)
                SDL_Log("ckpt: frame %u hash %08x, recording %08x: DIVERGED", f, h, want);
            r = 0;
        }
    }
    g_ck.st.frame = f + 1;
    hulk_replay_set_frame(f + 1);                        // the hybrid build counts the frame before the polls
    return r;
}
