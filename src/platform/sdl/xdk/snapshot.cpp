// Rollback snapshots of the simulation (docs/multiplayer.md section 16, mp3): an arena for the game's heap, whole-state
// snapshot and restore at GameClock::Update's entry, and the two in-process tests built on them. Off unless HULK_SNAP=1:
// without it every function here is a pass-through (the game's heap stays the host's C heap, nothing is hooked).
//
//   HULK_SNAP=1                  the arena: every game allocation (malloc/calloc/realloc/free 0x3479aa.., the XAPI heaps)
//                                comes from one reserved range with its allocator's state inside it, so a copy of the
//                                range is a copy of the heap, and the same sequence of calls gives the same addresses
//                                whatever happened before (a restored heap allocates exactly as it did the first time)
//   HULK_SNAP_ARENA_MB=N         the arena's reserved size (default 512)
//   HULK_SNAP_RANGES=FILE        the image's data to snapshot besides the arena (tools/rollback_test.py ranges writes it
//                                from the link map: the game's .data/.bss and the platform state the simulation reads)
//   HULK_RB_TEST=E:D[:A[:B]]     the restore test: at every frame F = 0 mod E in [A, B] take a snapshot, run D frames,
//                                hash the whole state, restore F, run the same D frames again (the replay's inputs are
//                                restored with it) and compare: one `rbtest` line per window
//   HULK_LAT_PROBE=E:K[:A[:B]]   the input-latency probe: at every frame F = 0 mod E in [A, B] run K frames once per
//                                test input (the input held from F on, ORed over the replay's), then once unchanged, and
//                                log for each input the first frame its effect shows (`latprobe` lines)
//
// The snapshot is taken at GameClock::Update's entry (hulk_native_frame, before the frame's update) on the main loop's
// call path only: a restore needs the same stack depth as the save (the frames above, CGame::Tick and the main loop,
// keep no state across that call: equivalent/0x00087630.cpp). Platform objects outside the snapshot (render resources,
// sound voices, files, events) are not restored; each test window lists the platform calls made inside it.
#include "imports.h"
#include "../crt/host_crt.h"

#if defined(HULK_NATIVE_SDL)
#include "../input/hulk_session.h"
#include "../audio/hulk_audio.h"
#endif

extern "C" int HULK_HOST_CDECL hulk_host_memcmp(const void* a, const void* b, hulk_u32 n);
extern "C" void HULK_CDECL hulk_native_log(const char* line);
extern "C" hulk_u32 hulk_native_frame_no;

// ---------------------------------------------------------------------------------------------------------------
// the arena
enum { kSnapQuarantine = 8192 };
struct SnapArena {               // at the arena's base: part of every snapshot
    hulk_u32 magic, top, last_size, serial;
    hulk_u32 bitmap[4];
    hulk_u32 bins[128];          // offset of the first free chunk of each size class (0: none)
    hulk_u32 live, live_bytes, allocs, frees, peak_top;
    hulk_u32 qhead, qn;          // the free quarantine (q): freed blocks wait here before they can be reused
    hulk_u32 q[kSnapQuarantine];
};
struct SnapChunk {               // 16-byte header in front of every block; payload 16-byte aligned
    hulk_u32 size;               // the chunk's bytes, header included; bit 0: in use
    hulk_u32 prev;               // the previous chunk's size (0: the first chunk)
    hulk_u32 req;                // in use: the size asked for (HeapSize / _msize); free: next free chunk
    hulk_u32 serial;             // in use: allocation number; free: previous free chunk
};
enum { kSnapFirst = 0x10000, kSnapCommitStep = 4u << 20 };

static int g_snap_on = -1;
static char* g_ab;               // arena base
static hulk_u32 g_areserve, g_acommit;
static volatile long g_alock;

static SnapArena* A() { return (SnapArena*)g_ab; }
static SnapChunk* C(hulk_u32 off) { return (SnapChunk*)(g_ab + off); }

static void snap_log(const char* fmt, ...);

static void arena_lock(void) {
    while (__sync_lock_test_and_set(&g_alock, 1))
        hulk_host_Sleep(0);
}
static void arena_unlock(void) { __sync_lock_release(&g_alock); }

static void arena_init(void) {
    const char* e = hulk_host_getenv("HULK_SNAP_ARENA_MB");
    hulk_u32 mb = 512;
    if (e && *e >= '1' && *e <= '9') {
        mb = 0;
        for (; *e >= '0' && *e <= '9'; e++)
            mb = mb * 10 + (hulk_u32)(*e - '0');
    }
    for (; mb >= 64; mb /= 2) {
        g_ab = (char*)hulk_host_VirtualAlloc(0, mb << 20, 0x2000 /* MEM_RESERVE */, 4 /* PAGE_READWRITE */);
        if (g_ab)
            break;
    }
    if (!g_ab || !hulk_host_VirtualAlloc(g_ab, kSnapCommitStep, 0x1000 /* MEM_COMMIT */, 4)) {
        g_snap_on = 0;
        return;
    }
    g_areserve = mb << 20;
    g_acommit = kSnapCommitStep;
    hulk_host_memset(g_ab, 0, kSnapFirst);
    A()->magic = 0x414e5253u;    // "SRNA"
    A()->top = A()->peak_top = kSnapFirst;
}

extern "C" void* HULK_CDECL hulk_snap_alloc(hulk_u32 size);
extern "C" void HULK_CDECL hulk_snap_free(void* p);
static int in_arena(const void* p);
#if defined(HULK_NATIVE_SDL)
static void* snap_valloc(unsigned n) { return hulk_snap_alloc(n); }
static void snap_vfree(void* p) { hulk_snap_free(p); }
static int snap_vowns(const void* p) { return in_arena(p); }
#endif
extern "C" int HULK_CDECL hulk_snap_on(void) {
    if (g_snap_on < 0) {
        const char* e = hulk_host_getenv("HULK_SNAP");
        g_snap_on = e && *e && *e != '0';
        if (g_snap_on)
            arena_init();
#if defined(HULK_NATIVE_SDL)
        if (g_snap_on)        // the sound voices (the game's buffer handles) live in the arena too
            hulk_audio_set_allocator(snap_valloc, snap_vfree, snap_vowns);
#endif
    }
    return g_snap_on;
}

static int bin_of(hulk_u32 sz) {
    if (sz < 1024)
        return (int)(sz >> 4);
    int lg = 31 - __builtin_clz(sz);
    int b = 64 + (lg - 10) * 4 + (int)((sz >> (lg - 2)) & 3);
    return b > 127 ? 127 : b;
}
static void bin_insert(hulk_u32 off) {
    int b = bin_of(C(off)->size);
    SnapChunk* c = C(off);
    c->req = A()->bins[b];
    c->serial = 0;
    if (c->req)
        C(c->req)->serial = off;
    A()->bins[b] = off;
    A()->bitmap[b >> 5] |= 1u << (b & 31);
}
static void bin_unlink(hulk_u32 off) {
    SnapChunk* c = C(off);
    int b = bin_of(c->size);
    if (c->serial)
        C(c->serial)->req = c->req;
    else
        A()->bins[b] = c->req;
    if (c->req)
        C(c->req)->serial = c->serial;
    if (!A()->bins[b])
        A()->bitmap[b >> 5] &= ~(1u << (b & 31));
}
static int arena_commit(hulk_u32 end) {
    if (end <= g_acommit)
        return 1;
    if (end > g_areserve)
        return 0;
    hulk_u32 want = (end + kSnapCommitStep - 1) & ~(kSnapCommitStep - 1);
    if (want > g_areserve)
        want = g_areserve;
    if (!hulk_host_VirtualAlloc(g_ab + g_acommit, want - g_acommit, 0x1000, 4))
        return 0;
    g_acommit = want;
    return 1;
}

// a chunk of NEED bytes (header included, multiple of 16): its offset, 0 when the arena is full
static hulk_u32 arena_take(hulk_u32 need) {
    SnapArena* a = A();
    int b = bin_of(need);
    hulk_u32 off = 0;
    for (hulk_u32 o = a->bins[b]; o; o = C(o)->req)       // first fit inside the request's own class
        if (C(o)->size >= need) {
            off = o;
            break;
        }
    for (int w = (b + 1) >> 5, first = 1; !off && w < 4; w++, first = 0) {   // else any larger class
        hulk_u32 m = a->bitmap[w];
        if (first)
            m &= (b + 1) & 31 ? ~((1u << ((b + 1) & 31)) - 1) : ~0u;
        if (m)
            off = a->bins[w * 32 + __builtin_ctz(m)];
    }
    if (off) {
        bin_unlink(off);
        hulk_u32 s = C(off)->size;
        if (s - need >= 32) {
            hulk_u32 r = off + need;
            C(r)->size = s - need;
            C(r)->prev = need;
            C(r + s - need)->prev = s - need;              // (a free chunk is never the last: it would be part of top)
            bin_insert(r);
            s = need;
        }
        C(off)->size = s | 1;
        return off;
    }
    if (!arena_commit(a->top + need))
        return 0;
    off = a->top;
    C(off)->size = need | 1;
    C(off)->prev = a->last_size;
    a->last_size = need;
    a->top += need;
    if (a->top > a->peak_top)
        a->peak_top = a->top;
    return off;
}

static void arena_give(hulk_u32 off) {
    SnapArena* a = A();
    hulk_u32 size = C(off)->size & ~1u;
    hulk_u32 n = off + size;
    if (n < a->top && !(C(n)->size & 1)) {
        bin_unlink(n);
        size += C(n)->size;
    }
    if (C(off)->prev) {
        hulk_u32 p = off - C(off)->prev;
        if (!(C(p)->size & 1)) {
            bin_unlink(p);
            size += C(p)->size;
            off = p;
        }
    }
    if (off + size == a->top) {
        a->top = off;
        a->last_size = C(off)->prev;
        return;
    }
    C(off)->size = size;
    C(off + size)->prev = size;
    bin_insert(off);
}

static int in_arena(const void* p) {
    return g_ab && (const char*)p >= g_ab + kSnapFirst && (const char*)p < g_ab + g_areserve;
}

extern "C" void* HULK_CDECL hulk_snap_alloc(hulk_u32 size) {
    hulk_u32 need = ((size ? size : 1) + 16 + 15) & ~15u;
    if (need < 32)
        need = 32;
    arena_lock();
    hulk_u32 off = arena_take(need);
    void* p = 0;
    if (off) {
        SnapChunk* c = C(off);
        c->req = size;
        c->serial = ++A()->serial;
        A()->live++;
        A()->live_bytes += need;
        A()->allocs++;
        p = (char*)c + 16;
        hulk_host_memset(p, 0, (c->size & ~1u) - 16);
    }
    arena_unlock();
    if (!p)
        snap_log("snap: the arena is full (%u MB reserved); allocation of %u bytes fails", g_areserve >> 20, size);
    return p;
}

extern "C" void HULK_CDECL hulk_snap_free(void* p) {
    if (!p)
        return;
    if (!in_arena(p)) {
        hulk_host_free(p);
        return;
    }
    arena_lock();
    hulk_u32 off = (hulk_u32)((char*)p - g_ab) - 16;
    SnapArena* a = A();
    a->live--;
    a->live_bytes -= C(off)->size & ~1u;
    a->frees++;
    // the block waits in the quarantine (its bytes untouched) and the oldest waiting one is given back: the game
    // reads some objects after freeing them (start-up's sequence event types: the host heap keeps their bytes
    // long enough, an allocator that reuses at once does not)
    if (a->qn == kSnapQuarantine) {
        arena_give(a->q[a->qhead]);
        a->q[a->qhead] = off;
        a->qhead = (a->qhead + 1) % kSnapQuarantine;
    } else
        a->q[(a->qhead + a->qn++) % kSnapQuarantine] = off;
    arena_unlock();
}

extern "C" hulk_u32 HULK_CDECL hulk_snap_size(const void* p) {
    if (!in_arena(p))
        return hulk_host__msize((void*)p);
    return ((const SnapChunk*)((const char*)p - 16))->req;
}

extern "C" void* HULK_CDECL hulk_snap_realloc(void* p, hulk_u32 size) {
    if (!p)
        return hulk_snap_alloc(size);
    if (!in_arena(p))
        return hulk_host_realloc(p, size);
    if (!size) {
        hulk_snap_free(p);
        return 0;
    }
    SnapChunk* c = (SnapChunk*)((char*)p - 16);
    hulk_u32 cap = (c->size & ~1u) - 16;
    if (size <= cap) {
        if (size > c->req)
            hulk_host_memset((char*)p + c->req, 0, size - c->req);
        c->req = size;
        return p;
    }
    void* q = hulk_snap_alloc(size);
    if (q) {
        hulk_host_memcpy(q, p, c->req);
        hulk_snap_free(p);
    }
    return q;
}

// ---------------------------------------------------------------------------------------------------------------
// the image's data (HULK_SNAP_RANGES)
struct SnapRange {
    char* p;
    hulk_u32 size, flags;        // flags: 1 snapshot, 2 state hash
};
static SnapRange* g_rng;
static hulk_u32 g_nrng, g_data_bytes, g_hash_bytes;
static int g_rng_loaded;

static hulk_u32 hexu(const char*& s) {
    while (*s == ' ')
        s++;
    hulk_u32 v = 0;
    for (;; s++) {
        char c = *s;
        if (c >= '0' && c <= '9')
            v = v * 16 + (hulk_u32)(c - '0');
        else if (c >= 'a' && c <= 'f')
            v = v * 16 + (hulk_u32)(c - 'a' + 10);
        else
            break;
    }
    return v;
}

// the file: "A <anchor va>" (the link-map address of hulk_native_frame_no), then "R <va> <size> <flags> <name>" lines,
// all hexadecimal
static void ranges_load(void) {
    if (g_rng_loaded)
        return;
    g_rng_loaded = 1;
    const char* path = hulk_host_getenv("HULK_SNAP_RANGES");
    hulk_host_file* f = path && *path ? hulk_host_fopen(path, "r") : 0;
    if (!f) {
        snap_log("snap: no ranges file (HULK_SNAP_RANGES): the snapshot covers the arena only");
        return;
    }
    char line[512];
    hulk_uptr delta = 0;
    hulk_u32 cap = 0;
    while (hulk_host_fgets(line, sizeof(line), f)) {
        const char* s = line + 1;
        if (line[0] == 'A') {
            delta = (hulk_uptr)&hulk_native_frame_no - hexu(s);
        } else if (line[0] == 'R') {
            hulk_u32 va = hexu(s), size = hexu(s), flags = hexu(s);
            if (!size)
                continue;
            if (g_nrng == cap) {
                cap = cap ? cap * 2 : 1024;
                g_rng = (SnapRange*)hulk_host_realloc(g_rng, cap * sizeof(SnapRange));
            }
            g_rng[g_nrng].p = (char*)(va + delta);
            g_rng[g_nrng].size = size;
            g_rng[g_nrng].flags = flags;
            g_nrng++;
            if (flags & 1)
                g_data_bytes += size;
            if (flags & 2)
                g_hash_bytes += size;
        }
    }
    hulk_host_fclose(f);
    snap_log("snap: %u ranges, %u bytes of image data in the snapshot, %u hashed (image delta %d); arena at %08x, %u MB",
             g_nrng, g_data_bytes, g_hash_bytes, (int)delta, (hulk_u32)(hulk_uptr)g_ab, g_areserve >> 20);
}

// ---------------------------------------------------------------------------------------------------------------
// snapshots
struct SnapSlot {
    unsigned char* buf;
    hulk_u32 cap, used, top, frame;
    hulk_uptr esp;
    int valid;
    hulk_u32 fibers;             // fiber switches so far when it was taken (snap_fibers)
    hulk_u32 posts;              // drive requests posted so far (hulk_io_post_count)
};
static hulk_u32 snap_fibers(void);
extern "C" hulk_u32 HULK_CDECL hulk_io_post_count(void);
// a restore is safe only when no fiber ran and no drive request was posted since the snapshot: the loader fiber and
// the drive thread keep state on their own stacks (host memory), which a restore cannot take back
static int barrier_crossed(const SnapSlot* s) {
    if (snap_fibers() != s->fibers)
        return 1;
    const char* e = hulk_host_getenv("HULK_SNAP_IO_BARRIER");
    return (!e || *e != '0') && hulk_io_post_count() != s->posts ? 2 : 0;
}

static unsigned long long snap_now_us(void) {
    unsigned long long c = 0, f = 1;
    hulk_host_QueryPerformanceCounter(&c);
    hulk_host_QueryPerformanceFrequency(&f);
    return c / f * 1000000ull + c % f * 1000000ull / f;
}

static void snap_log(const char* fmt, ...) {
    char line[600];
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    hulk_host__vsnprintf(line, sizeof(line), fmt, (char*)ap);
    __builtin_va_end(ap);
    line[sizeof(line) - 1] = 0;
    hulk_native_log(line);
}

static void audio_hold(int on) {
#if defined(HULK_NATIVE_SDL)
    hulk_audio_lock_state(on);
#else
    (void)on;
#endif
}
// the mixer's voice list and clock, after the image data in a slot (the voices are arena blocks)
static hulk_u32 audio_bytes(void) {
#if defined(HULK_NATIVE_SDL)
    return (hulk_audio_state_size() + 15) & ~15u;
#else
    return 0;
#endif
}
static void audio_copy(void* buf, int restore) {
#if defined(HULK_NATIVE_SDL)
    hulk_audio_state_copy(buf, restore);
#else
    (void)buf;
    (void)restore;
#endif
}

static int slot_save(SnapSlot* s, hulk_u32 frame, hulk_uptr esp) {
    hulk_u32 top = A()->top;
    hulk_u32 need = g_data_bytes + audio_bytes() + top;
    if (need > s->cap) {
        hulk_u32 cap = need + (8u << 20);
        unsigned char* b = (unsigned char*)hulk_host_realloc(s->buf, cap);
        if (!b) {
            snap_log("snap: no memory for a snapshot of %u bytes", need);
            s->valid = 0;
            return 0;
        }
        s->buf = b;
        s->cap = cap;
    }
    unsigned char* o = s->buf;
    audio_hold(1);
    for (hulk_u32 i = 0; i < g_nrng; i++)
        if (g_rng[i].flags & 1) {
            hulk_host_memcpy(o, g_rng[i].p, g_rng[i].size);
            o += g_rng[i].size;
        }
    audio_copy(o, 0);
    o += audio_bytes();
    arena_lock();
    hulk_host_memcpy(o, g_ab, top);
    arena_unlock();
    audio_hold(0);
    s->used = need;
    s->top = top;
    s->frame = frame;
    s->esp = esp;
    s->valid = 1;
    s->fibers = snap_fibers();
    s->posts = hulk_io_post_count();
    return 1;
}

static void slot_restore(const SnapSlot* s) {
    const unsigned char* o = s->buf;
    audio_hold(1);
    for (hulk_u32 i = 0; i < g_nrng; i++)
        if (g_rng[i].flags & 1) {
            hulk_host_memcpy(g_rng[i].p, o, g_rng[i].size);
            o += g_rng[i].size;
        }
    audio_copy((void*)o, 1);
    o += audio_bytes();
    arena_lock();
    hulk_host_memcpy(g_ab, o, s->top);
    arena_unlock();
    audio_hold(0);
}

static hulk_u32 fnv_words(hulk_u32 h, const void* p, hulk_u32 n) {
    const hulk_u32* w = (const hulk_u32*)p;
    for (hulk_u32 i = 0; i < n / 4; i++)
        h = (h ^ w[i]) * 16777619u;
    const unsigned char* b = (const unsigned char*)p + (n & ~3u);
    for (hulk_u32 i = 0; i < (n & 3); i++)
        h = (h ^ b[i]) * 16777619u;
    return h;
}

// the whole snapshotted state (FLAGS 1) or the part both peers share (FLAGS 2: no per-instance platform state)
static hulk_u32 state_hash(hulk_u32 flags) {
    hulk_u32 h = 2166136261u;
    for (hulk_u32 i = 0; i < g_nrng; i++)
        if (g_rng[i].flags & flags)
            h = fnv_words(h, g_rng[i].p, g_rng[i].size);
    arena_lock();
    h = fnv_words(h, g_ab, A()->top);
    arena_unlock();
    return h;
}

// the 4 KB pages (of the arena and the image ranges) that differ from S; the first MAXLOG differing words are logged
static hulk_u32 slot_diff(const SnapSlot* s, hulk_u32 maxlog, const char* tag, hulk_u32* words_out) {
    hulk_u32 pages = 0, words = 0, logged = 0;
    const unsigned char* o = s->buf;
    char line[200];
    for (hulk_u32 i = 0; i < g_nrng; i++) {
        if (!(g_rng[i].flags & 1))
            continue;
        const SnapRange& r = g_rng[i];
        for (hulk_u32 off = 0; off < r.size; off += 4096) {
            hulk_u32 n = r.size - off < 4096 ? r.size - off : 4096;
            if (!hulk_host_memcmp(o + off, r.p + off, n))
                continue;
            pages++;
            for (hulk_u32 k = 0; k + 4 <= n; k += 4)
                if (*(const hulk_u32*)(o + off + k) != *(const hulk_u32*)(r.p + off + k)) {
                    words++;
                    if (logged < maxlog) {
                        logged++;
                        hulk_host__snprintf(line, sizeof(line), "%s diff image range %u va %08x was %08x now %08x", tag, i,
                                            (hulk_u32)(hulk_uptr)(r.p + off + k), *(const hulk_u32*)(o + off + k),
                                            *(const hulk_u32*)(r.p + off + k));
                        hulk_native_log(line);
                    }
                }
        }
        o += r.size;
    }
    o += audio_bytes();
    hulk_u32 top = A()->top < s->top ? A()->top : s->top;
    if (A()->top != s->top && logged < maxlog) {
        logged++;
        snap_log("%s diff arena top was %08x now %08x", tag, s->top, A()->top);
    }
    for (hulk_u32 off = 0; off < top; off += 4096) {
        hulk_u32 n = top - off < 4096 ? top - off : 4096;
        if (!hulk_host_memcmp(o + off, g_ab + off, n))
            continue;
        pages++;
        for (hulk_u32 k = 0; k + 4 <= n; k += 4)
            if (*(const hulk_u32*)(o + off + k) != *(const hulk_u32*)(g_ab + off + k)) {
                words++;
                if (logged < maxlog) {
                    logged++;
                    // the chunk that holds the word: walk from the first chunk (logging only)
                    hulk_u32 c = kSnapFirst, at = off + k;
                    while (c < top && c + (C(c)->size & ~1u) <= at && (C(c)->size & ~1u))
                        c += C(c)->size & ~1u;
                    hulk_host__snprintf(line, sizeof(line), "%s diff arena +%08x (chunk +%08x size %u serial %u req %u, word +%u) "
                                        "was %08x now %08x", tag, at, c, C(c)->size & ~1u, C(c)->serial, C(c)->req, at - c - 16,
                                        *(const hulk_u32*)(o + at), *(const hulk_u32*)(g_ab + at));
                    hulk_native_log(line);
                }
            }
    }
    if (words_out)
        *words_out = words;
    return pages;
}

// ---------------------------------------------------------------------------------------------------------------
// platform calls inside a window (the XDK shim's call counters, xdk_shim.h)
enum { kSnapCalls = 512 };
struct SnapCalls {
    const char* names[kSnapCalls];
    hulk_u32 calls[kSnapCalls];
    hulk_u32 n;
};
static void calls_take(SnapCalls* c) { c->n = hulk_xdk_called(c->names, c->calls, kSnapCalls); }
// the calls made since BEFORE, as "name+count ..." into OUT; returns how many functions were called
static hulk_u32 calls_delta(const SnapCalls* before, char* out, hulk_u32 cap) {
    SnapCalls now;
    calls_take(&now);
    hulk_u32 k = 0, len = 0;
    out[0] = 0;
    for (hulk_u32 i = 0; i < now.n; i++) {
        hulk_u32 was = i < before->n ? before->calls[i] : 0;
        if (now.calls[i] == was)
            continue;
        // the per-frame calls every window makes are not interesting: skip the ones a frame always makes
        const char* nm = now.names[i];
        static const char* const routine[] = {"QueryPerformanceCounter", "XInputGetState", "XGetDeviceChanges",
                                              "DirectSoundDoWork", "Sleep", "WaitForSingleObject", "ReleaseSemaphore",
                                              "RtlEnterCriticalSection", "RtlLeaveCriticalSection", "GetLocalTime",
                                              "IDirectSoundBuffer_GetStatus", "IDirectSoundBuffer_GetCurrentPosition",
                                              "IDirectSoundBuffer_SetFrequency", "IDirectSoundBuffer_SetMixBinVolumes_8",
                                              "IDirectSoundBuffer_SetHeadroom", "IDirectSound_CommitDeferredSettings",
                                              "IDirectSound_SetI3DL2Listener", 0};
        int skip = 0;
        for (int r = 0; routine[r]; r++)
            if (!hulk_host_strcmp(nm, routine[r]))
                skip = 1;
        if (!skip && (nm[0] == 'D' && nm[1] == '3' && nm[2] == 'D') && !hulk_host_strcmp(nm + 3, "Device_SetRenderState_Simple"))
            skip = 1;
        if (skip)
            continue;
        k++;
        int w = hulk_host__snprintf(out + len, cap - len, "%s%s+%u", len ? " " : "", nm, now.calls[i] - was);
        if (w > 0 && len + (hulk_u32)w < cap)
            len += (hulk_u32)w;
    }
    return k;
}

// The loader fiber (radcore's, 0x26d990..) keeps its stack in host memory, outside the snapshot: once a fiber has
// run between a snapshot and a restore, the restored heap no longer matches that stack (a level unload at play3's
// frame 2600 crashed this way). Fiber switches are a barrier: no restore across one.
static hulk_u32 snap_fibers(void) {
    SnapCalls c;
    calls_take(&c);
    hulk_u32 n = 0;
    for (hulk_u32 i = 0; i < c.n; i++)
        if (!hulk_host_strcmp(c.names[i], "SwitchToFiber") || !hulk_host_strcmp(c.names[i], "CreateFiber") ||
            !hulk_host_strcmp(c.names[i], "DeleteFiber"))
            n += c.calls[i];
    return n;
}

// ---------------------------------------------------------------------------------------------------------------
// the main actor and the per-frame signals of the latency probe
extern "C" char DAT_004dd700[];
static const char* sp_ptr(const char* p, unsigned off) { return p ? *(const char* const*)(p + off) : 0; }
static const char* snap_main_actor(void) {
    const char* world = sp_ptr(DAT_004dd700, 0);
    const char* am = sp_ptr(world, 0x20);
    if (!am)
        return 0;
    int handle = *(const int*)(am + 0x124);
    const char* table = sp_ptr(sp_ptr(am, 0), 0x44);
    hulk_u32 tn = table ? *(const hulk_u32*)(table + 4) : 0;
    const char* items = sp_ptr(table, 8);
    const char* flags = sp_ptr(table, 0xc);
    for (hulk_u32 k = 0; items && flags && k < tn; k++)
        if (flags[k] && *(const int*)(items + k * 0x24) == handle)
            return sp_ptr(items + k * 0x24, 0x10);
    // (+0x124 may hold the actor itself rather than a handle)
    if (in_arena((const void*)(hulk_uptr)(hulk_u32)handle))
        return (const char*)(hulk_uptr)(hulk_u32)handle;
    return 0;
}

extern "C" char DAT_004e231c[];         // the camera singleton pointer

// (no draw signal: the frame's render follows its update in the same main-loop iteration, so what changes the
// actor or the camera in frame k is drawn in frame k's render)
enum { kSigIn, kSigBody, kSigPos, kSigCam, kSigs };
static const char* const kSigName[kSigs] = {"input", "actor", "position", "camera"};
static void signals(hulk_u32* s) {
    const char* a = snap_main_actor();
    for (int i = 0; i < kSigs; i++)
        s[i] = 0;
    if (a) {
        s[kSigIn] = fnv_words(2166136261u, a + 0x1f58, 0x10c);      // the fighter's input block (0xb3660 copies 0x43 words)
        s[kSigBody] = fnv_words(fnv_words(2166136261u, a, 0x1f58), a + 0x2064, 0x19c);
        const char* node = sp_ptr(a, 0x10);
        const char* d = sp_ptr(node, 0x18);
        s[kSigPos] = d ? fnv_words(2166136261u, d + 0x40, 12) : node ? fnv_words(2166136261u, node + 4, 12) : 0;
    }
    const char* cam = *(const char* const*)DAT_004e231c;
    s[kSigCam] = cam ? fnv_words(2166136261u, cam + 0x4c, 12) : 0;
}

// ---------------------------------------------------------------------------------------------------------------
// the per-frame hook (hulk_native_frame, before the frame number moves on): the tests' state machines
static hulk_u32 frame_range(const char* v, hulk_u32* out, int n) {
    int k = 0;
    while (v && *v && k < n) {
        hulk_u32 x = 0;
        while (*v >= '0' && *v <= '9')
            x = x * 10 + (hulk_u32)(*v++ - '0');
        out[k++] = x;
        if (*v == ':')
            v++;
        else
            break;
    }
    return (hulk_u32)k;
}

static SnapSlot g_s0, g_s1;
extern "C" hulk_u32 HULK_CDECL hulk_io_post_count(void);

static struct {
    int on;
    hulk_u32 every, depth, from, to;
    int phase;                   // 0 idle, 1 first pass, 2 second pass
    hulk_u32 f0, hash1, posts0, posts1, dirty1, dirty_words1;
    unsigned long long t_save, t_restore, t_pass1, t_pass2, t0;
    SnapCalls calls0;
    char calls[512];
    hulk_u32 n_ok, n_bad, n_skip;
} g_rt;

static void rbtest_frame(hulk_u32 F, hulk_uptr esp) {
    if (g_rt.phase == 0) {
        if (F < g_rt.from || F > g_rt.to || F % g_rt.every)
            return;
        unsigned long long t = snap_now_us();
        if (!slot_save(&g_s0, F, esp))
            return;
        g_rt.t_save = snap_now_us() - t;
        g_rt.f0 = F;
        g_rt.posts0 = hulk_io_post_count();
        calls_take(&g_rt.calls0);
        g_rt.phase = 1;
        g_rt.t0 = snap_now_us();
        return;
    }
    if (g_rt.phase == 1 && F == g_rt.f0 + 1) {
        // the pages one frame writes (a lower bound for an incremental snapshot)
        g_rt.dirty1 = slot_diff(&g_s0, 0, "", &g_rt.dirty_words1);
        return;
    }
    if (F != g_rt.f0 + g_rt.depth)
        return;
    if (g_rt.phase == 1) {
        g_rt.t_pass1 = snap_now_us() - g_rt.t0;
        g_rt.posts1 = hulk_io_post_count();
        calls_delta(&g_rt.calls0, g_rt.calls, sizeof(g_rt.calls));
        int bar = barrier_crossed(&g_s0);
        if (esp != g_s0.esp || bar) {
            g_rt.n_skip++;
            snap_log("rbtest f=%u depth=%u SKIP (%s; stack %08x, snapshot's %08x) calls: %s", g_rt.f0, g_rt.depth,
                     esp != g_s0.esp ? "another call path" : bar == 1 ? "a fiber ran" : "drive requests posted",
                     (hulk_u32)esp, (hulk_u32)g_s0.esp, g_rt.calls[0] ? g_rt.calls : "-");
            g_rt.phase = 0;
            return;
        }
        g_rt.hash1 = state_hash(1);
        slot_save(&g_s1, F, esp);                      // the first pass's end state, for the diff
        unsigned long long t = snap_now_us();
        slot_restore(&g_s0);
        g_rt.t_restore = snap_now_us() - t;
        g_rt.phase = 2;
        g_rt.t0 = snap_now_us();
        return;
    }
    // the second pass is back at the window's end
    g_rt.t_pass2 = snap_now_us() - g_rt.t0;
    hulk_u32 h2 = state_hash(1);
    hulk_u32 words = 0, pages = 0;
    int ok = h2 == g_rt.hash1;
    if (!ok) {
        char tag[32];
        hulk_host__snprintf(tag, sizeof(tag), "rbtest f=%u", g_rt.f0);
        pages = slot_diff(&g_s1, g_rt.n_bad < 8 ? 24 : 4, tag, &words);
        g_rt.n_bad++;
    } else
        g_rt.n_ok++;
    snap_log("rbtest f=%u depth=%u %s state %u KB (arena %u KB, live %u blocks) save %u us restore %u us pass1 %u us "
             "pass2 %u us dirty1 %u pages (%u words) io posts %u diff %u pages %u words calls: %s",
             g_rt.f0, g_rt.depth, ok ? "ok" : "DIFF", g_s0.used >> 10, g_s0.top >> 10, A()->live, (hulk_u32)g_rt.t_save,
             (hulk_u32)g_rt.t_restore, (hulk_u32)g_rt.t_pass1, (hulk_u32)g_rt.t_pass2, g_rt.dirty1, g_rt.dirty_words1,
             g_rt.posts1 - g_rt.posts0, pages, words, g_rt.calls[0] ? g_rt.calls : "-");
    g_rt.phase = 0;
}

// the latency probe: per probe frame, NB test inputs then the unchanged baseline (so the run goes on as recorded)
enum { kProbeInputs = 6, kProbeMaxK = 40 };
static const char* const kProbeName[kProbeInputs] = {"A", "B", "X", "Y", "stick-right", "stick-up"};
static struct {
    int on;
    hulk_u32 every, k, from, to;
    int phase, branch;           // branch 0..kProbeInputs-1: an input; kProbeInputs: the baseline
    hulk_u32 f0, hold;
    hulk_u32 sig[kProbeInputs + 1][kProbeMaxK][kSigs];
    hulk_u32 reads[kProbeInputs + 1][kProbeMaxK];    // injected reads made in each frame (the input's arrival)
    hulk_u32 reads_seen;
    hulk_u32 n;
} g_lp;

#if defined(HULK_NATIVE_SDL)
static void probe_inject(int branch) {
    HulkPadState s;
    hulk_host_memset(&s, 0, sizeof(s));
    if (branch >= 0 && branch < 4)
        s.analog[branch] = 255;
    else if (branch == 4)
        s.thumb[0] = 32767;
    else if (branch == 5)
        s.thumb[1] = 32767;
    hulk_session_pad_or(0, branch >= 0 && branch < kProbeInputs ? &s : 0);
}
#endif

static void probe_frame(hulk_u32 F, hulk_uptr esp) {
#if defined(HULK_NATIVE_SDL)
    if (g_lp.phase == 0) {
        if (F < g_lp.from || F > g_lp.to || F % g_lp.every)
            return;
        if (!snap_main_actor()) {
            static hulk_u32 told;
            if (told++ < 4) {
                const char* world = sp_ptr(DAT_004dd700, 0);
                const char* am = sp_ptr(world, 0x20);
                snap_log("latprobe f=%u skipped: no main actor (world %08x, actor manager %08x, +0x124 %08x)", F,
                         (hulk_u32)(hulk_uptr)world, (hulk_u32)(hulk_uptr)am, am ? *(const hulk_u32*)(am + 0x124) : 0);
            }
            return;
        }
        if (!slot_save(&g_s0, F, esp))
            return;
        g_lp.f0 = F;
        g_lp.branch = 0;
        g_lp.phase = 1;
        g_lp.reads_seen = hulk_session_pad_or_reads();
        probe_inject(0);
        return;
    }
    hulk_u32 k = F - g_lp.f0 - 1;                           // the frame whose result this hook sees
    if (k < g_lp.k) {
        signals(g_lp.sig[g_lp.branch][k]);
        hulk_u32 r = hulk_session_pad_or_reads();
        g_lp.reads[g_lp.branch][k] = r - g_lp.reads_seen;
        g_lp.reads_seen = r;
        // a button is held 4 frames (a tap), a stick the whole window
        if (g_lp.branch < 4 && k + 1 == 4)
            probe_inject(-1);
    }
    if (F != g_lp.f0 + g_lp.k)
        return;
    if (esp != g_s0.esp || barrier_crossed(&g_s0)) {
        snap_log("latprobe f=%u SKIP (stack differs, a fiber ran or drive requests were posted)", g_lp.f0);
        probe_inject(-1);
        g_lp.phase = 0;
        return;
    }
    if (g_lp.branch < kProbeInputs) {
        slot_restore(&g_s0);
        g_lp.branch++;
        g_lp.reads_seen = hulk_session_pad_or_reads();
        probe_inject(g_lp.branch);                           // (the baseline: none)
        return;
    }
    // the baseline has run: compare each input's frames with it
    g_lp.n++;
    for (int b = 0; b < kProbeInputs; b++) {
        int first_read = -1, first[kSigs];
        for (int s = 0; s < kSigs; s++)
            first[s] = -1;
        for (hulk_u32 j = 0; j < g_lp.k; j++) {
            if (first_read < 0 && g_lp.reads[b][j])
                first_read = (int)j;
            for (int s = 0; s < kSigs; s++)
                if (first[s] < 0 && g_lp.sig[b][j][s] != g_lp.sig[kProbeInputs][j][s])
                    first[s] = (int)j;
        }
        char line[300];
        int len = hulk_host__snprintf(line, sizeof(line), "latprobe f=%u input=%s read=%d", g_lp.f0, kProbeName[b], first_read);
        for (int s = 0; s < kSigs; s++)
            len += hulk_host__snprintf(line + len, sizeof(line) - len, " %s=%d", kSigName[s], first[s]);
        hulk_native_log(line);
    }
    g_lp.phase = 0;
#else
    (void)F;
    (void)esp;
#endif
}

// the rollback session's snapshot ring (HULK_NET=rb: hulk_session.cpp drives it through these)
#if defined(HULK_NATIVE_SDL)
static SnapSlot* g_ring;
static hulk_u32 g_nring;
static hulk_uptr g_hook_esp;
extern "C" unsigned HULK_CDECL hulk_session_small_hash(hulk_u32 fno);     // replay_hooks.cpp
static int ops_save(unsigned slot, unsigned frame) {
    return slot < g_nring && slot_save(&g_ring[slot], frame, g_hook_esp);
}
static int ops_restore(unsigned slot, unsigned frame) {
    if (slot >= g_nring)
        return 0;
    SnapSlot* s = &g_ring[slot];
    if (!s->valid || s->frame != frame || s->esp != g_hook_esp || barrier_crossed(s))
        return 0;
    slot_restore(s);
    return 1;
}
static unsigned ops_hash_big(void) { return state_hash(2); }
static unsigned ops_hash_small(unsigned frame) { return hulk_session_small_hash(frame); }
static unsigned ops_barriers(void) {         // fiber switches and drive posts: the session waits for its inputs
    const char* e = hulk_host_getenv("HULK_SNAP_IO_BARRIER");
    return snap_fibers() + ((!e || *e != '0') ? hulk_io_post_count() : 0);
}
#endif

static int g_hook_init;
extern "C" void HULK_CDECL hulk_snap_frame(hulk_uptr esp) {
    if (!hulk_snap_on())
        return;
    if (!g_hook_init) {
        g_hook_init = 1;
        ranges_load();
        hulk_u32 v[4] = {0, 0, 0, 0xffffffffu};
        if (frame_range(hulk_host_getenv("HULK_RB_TEST"), v, 4) >= 2 && v[0] && v[1]) {
            g_rt.on = 1;
            g_rt.every = v[0];
            g_rt.depth = v[1];
            g_rt.from = v[2];
            g_rt.to = v[3];
            snap_log("rbtest: every %u frames, depth %u, frames %u..%u", v[0], v[1], v[2], v[3]);
        }
        hulk_u32 p[4] = {0, 0, 0, 0xffffffffu};
        if (frame_range(hulk_host_getenv("HULK_LAT_PROBE"), p, 4) >= 2 && p[0] && p[1]) {
            g_lp.on = 1;
            g_lp.every = p[0];
            g_lp.k = p[1] < kProbeMaxK ? p[1] : kProbeMaxK;
            g_lp.from = p[2];
            g_lp.to = p[3];
            snap_log("latprobe: every %u frames, %u frames per input, frames %u..%u", p[0], g_lp.k, p[2], p[3]);
        }
    }
    hulk_u32 F = hulk_native_frame_no;
#if defined(HULK_NATIVE_SDL)
    if (hulk_session_rb_active()) {
        if (!g_ring) {
            const char* e = hulk_host_getenv("HULK_SNAP_SLOTS");
            g_nring = e && *e >= '1' && *e <= '9' ? (hulk_u32)(e[0] - '0') * (e[1] >= '0' && e[1] <= '9' ? 10 : 1) +
                                                        (e[1] >= '0' && e[1] <= '9' ? (hulk_u32)(e[1] - '0') : 0)
                                                  : 10;
            g_ring = (SnapSlot*)hulk_host_calloc(g_nring, sizeof(SnapSlot));
            snap_log("snap: rollback ring of %u snapshots", g_nring);
        }
        static HulkSnapOps ops = {ops_save, ops_restore, ops_hash_big, ops_hash_small, ops_barriers, 0};
        ops.slots = g_nring;
        g_hook_esp = esp;
        F = hulk_session_rb_frame(F, &ops);
    }
#endif
    if (g_rt.on)
        rbtest_frame(F, esp);
    else if (g_lp.on)
        probe_frame(F, esp);
    if (F % 1500 == 0)
        snap_log("snap frame %u: arena top %u KB (peak %u KB), %u live blocks, %u KB live, %u allocs %u frees", F,
                 A()->top >> 10, A()->peak_top >> 10, A()->live, A()->live_bytes >> 10, A()->allocs, A()->frees);
}
