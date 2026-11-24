/* Threads, fibers and waits, cooperatively (docs/wasm-port.md "Threads and fibers").
 *
 * Every thread runs on a fiber: a C stack and an Asyncify buffer, both in the game arena or at the main thread's fixed
 * stack, switched by the driver below (ff_sched_loop) with Binaryen's Asyncify (the pass runs on the linked module;
 * the asyncify.* imports are its own functions). A suspended fiber's state is in linear memory, so it is game state
 * like the rest and the module needs no JS to switch (node and the wasm2c build run it alike). Exactly one thread runs; it switches
 * only when the game waits for an object that isn't signaled, sleeps, exits or switches fibers itself. The next
 * thread is the first runnable one after the current in handle order; when none is runnable the virtual clock jumps to
 * the earliest deadline. So a run is a function of its inputs alone. */
#include <emscripten/stack.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hulk_host.h"
#include "sim.h"

#define MAIN_STACK_LO 0x00E00000u
#define MAIN_STACK_HI 0x00F00000u
#define FIBER_C_STACK (256u << 10)
#define ASYNCIFY_STACK (256u << 10)
#define INFINITE 0xffffffffu
#define WAIT_TIMEOUT 0x102u

/* ------------------------------------------------------------------------------------------- fibers */
#define AI(n) __attribute__((import_module("asyncify"), import_name(n)))
AI("start_unwind") void as_start_unwind(void* data);
AI("stop_unwind") void as_stop_unwind(void);
AI("start_rewind") void as_start_rewind(void* data);
AI("stop_rewind") void as_stop_rewind(void);
void _emscripten_stack_restore(uintptr_t sp);

/* a fiber's context (in the arena): Asyncify's data header {current, end} first */
typedef struct {
    uint32_t ad_cur, ad_end;
    uint32_t buf, size;         /* the Asyncify buffer */
    uint32_t sp, stack_hi;      /* the C stack pointer while suspended; the stack's top */
    uint32_t stack_lo;
    uint32_t started;
    void (*fn)(uint32_t);
    uint32_t arg;
} hfiber;

static hfiber* next_fiber;      /* set by a fiber that unwinds: whom the driver runs next */
static hfiber* resuming;        /* the fiber the driver rewinds */

/* setjmp/longjmp (Lua's protected calls, libpng's and the physics' error exits) on the same machinery: a setjmp
 * unwinds its fiber and keeps a copy of the Asyncify data and the stack pointer (a continuation), then rewinds and
 * returns 0; a longjmp unwinds its fiber, puts the continuation's data back and rewinds into that setjmp, which
 * returns the value. As on x86, memory keeps what it holds at the longjmp; wasm locals come back as they were at
 * the setjmp (registers). Continuations live in the arena (game state), keyed by the jmp_buf's address. */
enum { SJ_NONE, SJ_CAPTURE, SJ_JUMP };
#define MAX_CONTS 32
typedef struct {
    uint32_t jb, fiber, sp, len, buf, cap, age;
} hcont;
static int sj_mode;
static uint64_t n_swaps, n_setjmps, n_longjmps, sj_bytes;   /* (statistics, host only) */
static uint32_t sj_jb, sj_value, sj_result;

static hcont* cont_for(uint32_t jb, int make) {
    if (!SIM->sj_conts) SIM->sj_conts = (uint32_t)(uintptr_t)ff_arena_alloc(MAX_CONTS * sizeof(hcont), 16);
    hcont* conts = PTR(SIM->sj_conts);
    hcont* old = &conts[0];
    for (int i = 0; i < MAX_CONTS; i++) {
        if (conts[i].jb == jb) return &conts[i];
        if (conts[i].age < old->age) old = &conts[i];
    }
    if (!make) return 0;
    old->jb = jb;
    old->len = 0;
    return old;
}

/* (the driver, between a fiber's unwind and its rewind) */
static void sj_step(hfiber* f) {
    if (sj_mode == SJ_CAPTURE) {
        hcont* k = cont_for(sj_jb, 1);
        uint32_t len = f->ad_cur - f->buf;
        n_setjmps++;
        sj_bytes += len;
        if (len > k->cap) {
            if (k->buf) ff_arena_free(PTR(k->buf));
            k->cap = (len + 4095) & ~4095u;
            k->buf = (uint32_t)(uintptr_t)ff_arena_alloc(k->cap, 16);
        }
        memcpy(PTR(k->buf), PTR(f->buf), len);
        k->len = len;
        k->sp = f->sp;
        k->fiber = (uint32_t)(uintptr_t)f;
        k->age = ++SIM->sj_age;
        sj_result = 0;
    } else {
        hcont* k = cont_for(sj_jb, 0);
        if (!k || !k->len) ff_fatal("longjmp(0x%x): no setjmp", sj_jb);
        if (k->fiber != (uint32_t)(uintptr_t)f) ff_fatal("longjmp(0x%x) into another fiber", sj_jb);
        memcpy(PTR(f->buf), PTR(k->buf), k->len);
        f->ad_cur = f->buf + k->len;
        f->sp = k->sp;
        sj_result = sj_value;
        n_longjmps++;
    }
    sj_mode = SJ_NONE;
}

static hfiber* new_ctx(void (*fn)(uint32_t), uint32_t arg, void* stack, uint32_t stack_size, uint32_t async_size) {
    hfiber* c = ff_arena_alloc(sizeof *c, 16);
    c->buf = (uint32_t)(uintptr_t)ff_arena_alloc(async_size, 16);
    c->size = async_size;
    c->stack_hi = ((uint32_t)(uintptr_t)stack + stack_size) & ~15u;
    c->stack_lo = (uint32_t)(uintptr_t)stack;
    c->fn = fn;
    c->arg = arg;
    return c;
}

/* suspend FROM (the running fiber) and run TO; returns when FROM runs again */
__attribute__((noinline)) static void fiber_swap(hfiber* from, hfiber* to) {
    if (resuming) {             /* (rewound: FROM runs again) */
        as_stop_rewind();
        resuming = 0;
        return;
    }
    from->sp = (uint32_t)emscripten_stack_get_current();
    from->ad_cur = from->buf;
    from->ad_end = from->buf + from->size;
    next_fiber = to;
    as_start_unwind(from);
}

/* HULK_ROLLTEST=A:B (D222): a rollback round trip. At the first fiber switch of frame A (every fiber suspended: the
 * whole game state is in linear memory) the state is copied; at frame B the game hash is taken and the copy put back,
 * and the run plays A..B again: the second hash at B must be the first ("rolltest: identical"; exit 0, else 3). */
uint64_t ff_game_hash(void);
uint64_t ff_state_hash(void);
void ff_game_dump(const char* path);
/* HULK_ROLLTEST_DUMP=PREFIX: the game state at B before the restore (PREFIX.1) and again (PREFIX.2) */
static void roll_dump(int k) {
    const char* p = getenv("HULK_ROLLTEST_DUMP");
    if (!p) return;
    char path[512];
    snprintf(path, sizeof path, "%s.%d", p, k);
    ff_game_dump(path);
}
uint32_t ff_state_bytes(void);
void ff_files_flush(void);
void ff_audio_restored(void) __attribute__((weak));     /* gfx/audio.c: the app's mixer makes its mirror again */
void ff_movie_restored(void) __attribute__((weak));     /* gfx/movie.c: the runner's movie decoders re-seek */
/* gfx/gfx.c (wroll1): the pddi front end's statics and resource table (a data section of the module, above 1 GB) are
 * game state too when it draws; after a restore the runner's GPU objects are made to match them */
uint32_t ff_gfx_state(uint32_t* lo) __attribute__((weak));
void ff_gfx_restored(void) __attribute__((weak));
uint64_t ff_gfx_hash(void) __attribute__((weak));
static uint32_t gfx_state(uint32_t* lo) {
    *lo = 0;
    return ff_gfx_state ? ff_gfx_state(lo) : 0;
}
uint32_t ff_module_state(uint32_t* lo);       /* frame.c: the tree's own globals (wasm_port.py GAME_STATE_SECTION) */
uint64_t ff_module_hash(void);
static void state_copy(uint8_t* q, int restore) {
    struct { uint32_t lo, n; } r[5] = {{0x0048ca80u, XBE_END - 0x0048ca80u},
                                       {MAIN_STACK_LO, MAIN_STACK_HI - MAIN_STACK_LO + (uint32_t)sizeof(hulk_sim)},
                                       {ARENA_LO, 0}, {0, 0}, {0, 0}};
    r[2].n = (restore ? *(uint32_t*)q : ff_arena_top()) - ARENA_LO;
    if (!restore) *(uint32_t*)q = ff_arena_top();
    q += 4;
    r[3].n = gfx_state(&r[3].lo);
    r[4].n = ff_module_state(&r[4].lo);
    for (int i = 0; i < 5; i++) {
        if (restore) memcpy(PTR(r[i].lo), q, r[i].n);
        else memcpy(q, PTR(r[i].lo), r[i].n);
        q += r[i].n;
    }
}
/* Playthrough snapshots on disk (wplay4, D244; replay.cpp "Playthroughs"): rolltest's state in a file, written and
 * put back at a switch where every fiber is suspended (a frame end: ff_frame_checkpoint), so a session can continue
 * in another process of the same build. Beyond the five ranges: the fiber to run next and the host state the game
 * reads that lives in module data outside them (the replay's position, virtual clock and private generators:
 * replay.cpp ff_replay_blob; lockstep I/O: io_lockstep.c ff_io_blob). A restore checks the ranges' places and sizes
 * against this build's; the file is keyed to the executable by tools/playthrough.py. */
#include "hulk_io.h"
uint32_t ff_replay_blob(void* buf, int restore);
uint32_t ff_io_blob(void* buf, int restore);
#define SNAP_MAGIC 0x504e5348u      /* "HSNP" */
#define SNAP_HDR 18
static uint8_t snap_blob[2][8192];
static void snap_ranges(uint32_t r[5][2], uint32_t top) {
    uint32_t lo;
    r[0][0] = 0x0048ca80u, r[0][1] = XBE_END - 0x0048ca80u;
    r[1][0] = MAIN_STACK_LO, r[1][1] = MAIN_STACK_HI - MAIN_STACK_LO + (uint32_t)sizeof(hulk_sim);
    r[2][0] = ARENA_LO, r[2][1] = top - ARENA_LO;
    r[3][1] = gfx_state(&lo), r[3][0] = lo;
    r[4][1] = ff_module_state(&lo), r[4][0] = lo;
}
int ff_snap_write(const char* path) {
    if (!next_fiber) return 0;
    int32_t f = hio_open(path, HIO_CREATE);
    if (f < 0) return 0;
    uint32_t h[SNAP_HDR], r[5][2];
    snap_ranges(r, ff_arena_top());
    h[0] = SNAP_MAGIC, h[1] = 1, h[2] = SIM->frame, h[3] = (uint32_t)(uintptr_t)next_fiber;
    for (int i = 0; i < 5; i++) h[4 + 2 * i] = r[i][0], h[5 + 2 * i] = r[i][1];
    h[14] = ff_replay_blob(snap_blob[0], 0);
    h[15] = ff_io_blob(snap_blob[1], 0);
    h[16] = (uint32_t)sizeof(hulk_sim), h[17] = 0;
    uint32_t off = 0;
    int ok = hio_write(f, h, sizeof h, off) == (int32_t)sizeof h;
    off += sizeof h;
    for (int i = 0; i < 5 && ok; i++) {
        ok = hio_write(f, PTR(r[i][0]), r[i][1], off) == (int32_t)r[i][1];
        off += r[i][1];
    }
    for (int i = 0; i < 2 && ok; i++) {
        ok = hio_write(f, snap_blob[i], h[14 + i], off) == (int32_t)h[14 + i];
        off += h[14 + i];
    }
    hio_close(f);
    return ok;
}
void ff_files_flush(void);
void ff_movie_restored(void) __attribute__((weak));
void ff_gfx_restored(void) __attribute__((weak));
int ff_snap_read(const char* path) {
    if (!next_fiber) return 0;
    int32_t f = hio_open(path, HIO_READ);
    if (f < 0) return 0;
    uint32_t h[SNAP_HDR], r[5][2], off = sizeof h;
    int ok = hio_read(f, h, sizeof h, 0) == (int32_t)sizeof h && h[0] == SNAP_MAGIC && h[1] == 1 &&
             h[16] == sizeof(hulk_sim) && h[14] == ff_replay_blob(snap_blob[0], 0) &&
             h[15] == ff_io_blob(snap_blob[1], 0);
    snap_ranges(r, ARENA_LO + h[9]);
    for (int i = 0; i < 5 && ok; i++)
        if (h[4 + 2 * i] != r[i][0] || h[5 + 2 * i] != r[i][1]) ok = 0;
    if (ok && (h[9] > ARENA_HI - ARENA_LO || h[2] < 1)) ok = 0;
    if (!ok) {
        hio_close(f);
        return 0;
    }
    for (int i = 0; i < 5 && ok; i++) {
        ok = hio_read(f, PTR(r[i][0]), r[i][1], off) == (int32_t)r[i][1];
        off += r[i][1];
    }
    for (int i = 0; i < 2 && ok; i++) {
        ok = hio_read(f, snap_blob[i], h[14 + i], off) == (int32_t)h[14 + i];
        off += h[14 + i];
    }
    hio_close(f);
    if (!ok) ff_fatal("playthrough: %s is truncated (the state is half restored)", path);
    ff_replay_blob(snap_blob[0], 1);
    ff_io_blob(snap_blob[1], 1);
    next_fiber = (hfiber*)(uintptr_t)h[3];
    ff_files_flush();
    if (ff_movie_restored) ff_movie_restored();
    if (ff_gfx_restored) ff_gfx_restored();
    return 1;
}
void ff_playthrough_switch(void);       /* replay.cpp */
int ff_playthrough_frame_end(void);
int ff_coop_frame_end(void) __attribute__((weak));      /* gfx/netplay.c (the app): 1 = a co-op snapshot or restore */
void ff_coop_switch(void) __attribute__((weak));

static long roll_a = -1, roll_b;
static int rolltest_on(void) {
    if (roll_a < 0) {
        const char* e = getenv("HULK_ROLLTEST");
        roll_a = 0;
        if (e && sscanf(e, "%ld:%ld", &roll_a, &roll_b) != 2) roll_a = 0;
        if (roll_b <= roll_a) roll_a = 0;
    }
    return roll_a > 0;
}
static void rolltest(void) {
    static int phase;
    static uint8_t* snap;
    static hfiber* snap_next;
    static uint64_t h1, s1, g1, m1;
    long a = rolltest_on() ? roll_a : 0, b = roll_b;
    if (!a || !next_fiber) return;
    if (phase == 0 && SIM->frame >= (uint32_t)a) {
        uint32_t top = ff_arena_top(), glo, mlo;
        uint32_t bytes = 4 + (XBE_END - 0x0048ca80u) + (MAIN_STACK_HI - MAIN_STACK_LO) + sizeof(hulk_sim) +
                         (top - ARENA_LO) + gfx_state(&glo) + ff_module_state(&mlo);
        double t0 = ff_now_ms();
        snap = malloc(bytes);
        if (!snap) ff_fatal("rolltest: no memory");
        state_copy(snap, 0);
        double t1 = ff_now_ms();
        snap_next = next_fiber;
        phase = 1;
        fprintf(stderr, "rolltest: snapshot at frame %u (game hash 0x%016llx; %u bytes, %.2f ms)\n", SIM->frame,
                (unsigned long long)ff_game_hash(), bytes, t1 - t0);
    } else if (phase == 1 && SIM->frame >= (uint32_t)b) {
        h1 = ff_game_hash();
        s1 = ff_state_hash();
        g1 = ff_gfx_hash ? ff_gfx_hash() : 0;
        m1 = ff_module_hash();
        roll_dump(1);
        uint32_t f = SIM->frame;
        double t0 = ff_now_ms();
        state_copy(snap, 1);
        double t1 = ff_now_ms();
        ff_files_flush();
        if (ff_audio_restored) ff_audio_restored();
        if (ff_movie_restored) ff_movie_restored();
        double t2 = ff_now_ms();
        if (ff_gfx_restored) ff_gfx_restored();
        double t3 = ff_now_ms();
        next_fiber = snap_next;
        phase = 2;
        fprintf(stderr, "rolltest: frame %u game hash 0x%016llx state hash 0x%016llx gfx 0x%016llx; restored frame %u "
                "(state %.2f ms, files+audio %.2f ms, gfx %.2f ms)\n", f, (unsigned long long)h1,
                (unsigned long long)s1, (unsigned long long)g1, SIM->frame, t1 - t0, t2 - t1, t3 - t2);
    } else if (phase == 2 && SIM->frame >= (uint32_t)b) {
        uint64_t h2 = ff_game_hash(), s2 = ff_state_hash(), g2 = ff_gfx_hash ? ff_gfx_hash() : 0;
        uint64_t m2 = ff_module_hash();
        int same = h1 == h2 && g1 == g2 && m1 == m2;
        if (m1 != m2) fprintf(stderr, "rolltest: the module's own globals differ\n");
        roll_dump(2);
        fprintf(stderr, "rolltest: frame %u again: game hash 0x%016llx state hash 0x%016llx gfx 0x%016llx: %s\n",
                SIM->frame, (unsigned long long)h2, (unsigned long long)s2, (unsigned long long)g2,
                same ? "identical" : "DIFFERENT");
        fflush(stderr);
        exit(same ? 0 : 3);
    }
}

/* the driver (not instrumented: tools/wasm_port.py lists it for Asyncify's removelist): runs fibers until the first
 * one returns */
__attribute__((noinline)) void ff_sched_loop(hfiber* f) {
    uintptr_t mine = emscripten_stack_get_current();
    while (f) {
        next_fiber = 0;
        _emscripten_stack_restore(f->started ? f->sp : f->stack_hi);
        if (f->started) {
            resuming = f;
            as_start_rewind(f);
        }
        f->started = 1;
        f->fn(f->arg);
        _emscripten_stack_restore(mine);
        if (!next_fiber) break;
        if ((uint32_t)(f->ad_cur - f->buf) > f->size) ff_fatal("asyncify buffer overflow");
        as_stop_unwind();
        n_swaps++;
        if (sj_mode) sj_step(f);
        rolltest();
        ff_playthrough_switch();
        if (ff_coop_switch) ff_coop_switch();
        f = next_fiber;
    }
}

static uint64_t deadline(hulk_obj* t) { return (uint64_t)t->deadline_hi << 32 | t->deadline_lo; }
static void set_deadline(hulk_obj* t, uint64_t d) { t->deadline_lo = (uint32_t)d; t->deadline_hi = (uint32_t)(d >> 32); }
static hfiber* ctx_of(uint32_t fiber) { return PTR(ff_obj(fiber)->ctx); }

static void fiber_main(uint32_t arg);

/* FN(ARG) on a host stack outside the game state: host work whose bytes depend on the host (a report line with
 * measured times) leaves no trace on a game stack, where a later uninitialized local could read it, and the state
 * stays a function of the game's inputs alone */
static char host_stack[256 << 10] __attribute__((aligned(16)));
__attribute__((noinline)) void ff_on_host_stack(void (*fn)(void*), void* arg) {
    uintptr_t sp = emscripten_stack_get_current();
    _emscripten_stack_restore((uintptr_t)(host_stack + sizeof host_stack));
    fn(arg);
    _emscripten_stack_restore(sp);
}

/* a fiber object with its own context, not started */
static uint32_t new_fiber(uint32_t entry, uint32_t param, uint32_t thread) {
    uint32_t h = ff_new_obj(OBJ_FIBER);
    hulk_obj* f = ff_obj(h);
    f->entry = entry;
    f->param = param;
    f->thread = thread;
    void* cs = ff_arena_alloc(FIBER_C_STACK, 16);
    f->ctx = (uint32_t)(uintptr_t)new_ctx(fiber_main, h, cs, FIBER_C_STACK, ASYNCIFY_STACK);
    return h;
}

static hulk_obj* cur(void) { return ff_obj(SIM->cur_thread); }

/* the current thread gives up the processor until something makes it runnable */
static void reschedule(void) {
    for (;;) {
        uint32_t me = SIM->cur_thread, next = 0;
        uint32_t start = (me - HANDLE_BASE) / 4;
        for (uint32_t k = 1; k <= MAX_OBJS && !next; k++) {
            uint32_t i = (start + k) % MAX_OBJS;
            hulk_obj* o = &SIM->objs[i];
            if (o->kind == OBJ_THREAD && o->state == T_RUNNABLE) next = HANDLE_BASE + i * 4;
        }
        if (!next) {
            /* nothing runnable: the clock jumps to the earliest deadline */
            uint64_t best = ~0ull;
            for (uint32_t i = 0; i < MAX_OBJS; i++) {
                hulk_obj* o = &SIM->objs[i];
                if (o->kind == OBJ_THREAD && (o->state == T_WAITING || o->state == T_SLEEPING) &&
                    deadline(o) < best) {
                    best = deadline(o);
                    next = HANDLE_BASE + i * 4;
                }
            }
            if (!next || best == ~0ull) ff_fatal("deadlock: every thread waits forever");
            if (best > SIM->clock) SIM->clock = best;
            hulk_obj* t = ff_obj(next);
            t->timed_out = t->state == T_WAITING;
            t->state = T_RUNNABLE;
        }
        if (next == me) return;
        hulk_obj* from = ff_obj(me);
        hulk_obj* to = ff_obj(next);
        SIM->cur_thread = next;
        fiber_swap(ctx_of(from->fiber), ctx_of(to->fiber));
        if (cur()->state == T_RUNNABLE) return;     /* (back here when this thread runs again) */
    }
}

static int try_acquire(hulk_obj* o) {
    switch (o->kind) {
    case OBJ_SEMAPHORE:
        if (o->count > 0) { o->count--; return 1; }
        return 0;
    case OBJ_EVENT:
        if (!o->signaled) return 0;
        if (!o->manual) o->signaled = 0;
        return 1;
    case OBJ_THREAD:
        return o->done != 0;
    default:
        return 1;
    }
}

static void wake_waiters(uint32_t h) {
    for (uint32_t i = 0; i < MAX_OBJS; i++) {
        hulk_obj* o = &SIM->objs[i];
        if (o->kind == OBJ_THREAD && o->state == T_WAITING && o->wait == h) {
            o->state = T_RUNNABLE;
            o->timed_out = 0;
        }
    }
}

void ff_wake(uint32_t h) { wake_waiters(h); }

/* io_lockstep.c (a replay's lockstep I/O) */
int ff_io_drive_wait(uint32_t h, uint32_t ms, uint32_t* result);
int ff_io_main_wait(uint32_t h, uint32_t* result);
void ff_io_main_sleep(void);
void ff_io_thread_created(uint32_t start, uint32_t param, uint32_t thread);
void ff_io_main_thread(uint32_t t);

uint32_t ff_wait(uint32_t h, uint32_t ms) {
    uint32_t r0;
    if (ff_io_drive_wait(h, ms, &r0) || (ms && ff_io_main_wait(h, &r0))) return r0;
    hulk_obj* o = ff_obj(h);
    if (!o) return 0xffffffffu;     /* WAIT_FAILED */
    hulk_obj* t = cur();
    uint64_t until = ms == INFINITE ? ~0ull : SIM->clock + (uint64_t)ms * (HULK_TSC_HZ / 1000);
    while (!try_acquire(o)) {
        if (ms == 0) return WAIT_TIMEOUT;
        t->state = T_WAITING;
        t->wait = h;
        set_deadline(t, until);
        t->timed_out = 0;
        reschedule();
        t->wait = 0;
        if (t->timed_out) return WAIT_TIMEOUT;
    }
    return 0;
}

void ff_sleep(uint32_t ms) {
    ff_io_main_sleep();
    hulk_obj* t = cur();
    t->state = T_SLEEPING;
    set_deadline(t, SIM->clock + (uint64_t)ms * (HULK_TSC_HZ / 1000));
    if (ms == 0) t->state = T_RUNNABLE;     /* a yield: others run first if they can */
    reschedule();
}

/* the end of a frame (D3D Swap, the app's present): with HULK_ROLLTEST the running fiber is suspended and resumed at
 * once, so the driver sees every fiber suspended there (the whole state in linear memory) once a frame. A run that
 * never waits (the app's gameplay with a renderer: no fiber switch for thousands of frames) otherwise gives it no
 * point to snapshot at; the frame's end is also the one where the runner's GPU work of the frame is complete
 * (wroll1). Nothing the game reads changes (an unwind writes only the fiber's Asyncify buffer). */
static void pt_frame_end(void* out) {
    *(int*)out = ff_playthrough_frame_end();
    if (ff_coop_frame_end && ff_coop_frame_end()) *(int*)out = 1;
}
void ff_frame_checkpoint(void) {
    int pt = 0;
    ff_on_host_stack(pt_frame_end, &pt);    /* (host work: its bytes stay off the game's stacks) */
    if (!rolltest_on() && !pt) return;
    hulk_obj* t = cur();
    if (!t || !t->fiber) return;
    hfiber* c = ctx_of(t->fiber);
    fiber_swap(c, c);
}

/* a time slice: a thread that polls (the clock, the current thread) instead of waiting lets the others run every
 * so many polls, as preemption would on the console (deterministic: by count) */
void ff_poll(void) {
    if (++SIM->polls % 32) return;
    hulk_obj* t = cur();
    if (t) {
        t->state = T_RUNNABLE;
        reschedule();
    }
}

/* a fiber's code: the thread's start routine (threads) or the fiber's (fibers); a thread ends when it returns */
static void fiber_main(uint32_t h) {
    hulk_obj* f = ff_obj(h);
    uint32_t code = ff_call(f->entry, 1, f->param);
    hulk_obj* t = cur();
    t->exit_code = code;
    t->done = 1;
    t->state = T_DONE;
    wake_waiters(SIM->cur_thread);
    reschedule();
    ff_fatal("a finished thread ran again");
}

/* the game's main thread on a fiber whose stack is at a fixed address (the game keeps stack addresses in objects) */
static void (*main_entry)(void);
/* HULK_SJTEST=1: setjmp/longjmp through a few frames, before the game starts */
void ffg_00347250(uint32_t, uint32_t, void*, void*);
void ffg_003471d4(uint32_t, uint32_t, void*, void*);
__attribute__((noinline)) static int sj_deep(uint32_t* jb, int depth) {
    if (depth == 0) {
        uint32_t st[2] = {(uint32_t)(uintptr_t)jb, 7};
        uint64_t rb;
        ffg_003471d4(0, 0, st, &rb);
        return 0;
    }
    return sj_deep(jb, depth - 1) + 1;
}
static void sj_test(void) {
    uint32_t jb[16];
    volatile int passes = 0;
    uint32_t st[2] = {(uint32_t)(uintptr_t)jb, 0};
    uint64_t rb = 0;
    ffg_00347250(0, 0, st, &rb);
    passes++;
    if ((uint32_t)rb == 0) sj_deep(jb, 20);
    fprintf(stderr, "hulk: sjtest: setjmp returned %u on pass %d (want 7 on pass 2)\n", (uint32_t)rb, passes);
}

static void main_fiber(uint32_t arg) {
    (void)arg;
    if (getenv("HULK_SJTEST")) sj_test();
    main_entry();
    ff_run_atexit();        /* (returning ends the driver's loop) */
}

void ff_run_main(void (*entry)(void)) {
    main_entry = entry;
    uint32_t t = ff_new_obj(OBJ_THREAD);
    uint32_t f = ff_new_obj(OBJ_FIBER);
    hfiber* c = new_ctx(main_fiber, 0, PTR(MAIN_STACK_LO), MAIN_STACK_HI - MAIN_STACK_LO, 1u << 20);
    ff_obj(f)->ctx = (uint32_t)(uintptr_t)c;
    ff_obj(f)->thread = t;
    ff_obj(t)->fiber = f;
    ff_obj(t)->state = T_RUNNABLE;
    SIM->cur_thread = t;
    ff_io_main_thread(t);
    ff_sched_loop(c);
}

/* ------------------------------------------------------------------------------------------- XAPI */
FFG(0020c0dd) {         /* CreateThread(sa, stack, start, param, flags, id*) */
    UNUSED;
    uint32_t t = ff_new_obj(OBJ_THREAD);
    hulk_obj* o = ff_obj(t);
    o->refs = 2;            /* the handle and the running thread */
    o->fiber = new_fiber(ARG(2), ARG(3), t);
    o->state = (ARG(4) & 4) ? T_SLEEPING : T_RUNNABLE;      /* CREATE_SUSPENDED: held until ResumeThread */
    set_deadline(o, ~0ull);
    if (ARG(5)) *(uint32_t*)PTR(ARG(5)) = t;
    ff_io_thread_created(ARG(2), ARG(3), t);
    RET(t);
}
FFG(0020bd91) {         /* ResumeThread */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (o && o->kind == OBJ_THREAD && o->state == T_SLEEPING && deadline(o) == ~0ull) o->state = T_RUNNABLE;
    RET(1);
}
FFG(0020be50) {         /* ExitThread */
    UNUSED;
    hulk_obj* t = cur();
    t->exit_code = ARG(0);
    t->done = 1;
    t->state = T_DONE;
    wake_waiters(SIM->cur_thread);
    reschedule();
    ff_fatal("a finished thread ran again");
}
FFG(0020bc3e) { UNUSED; RET(1); }                                               /* SetThreadPriority */
FFG(0020c14b) { UNUSED; RET(SIM->cur_thread); }                                 /* GetCurrentThreadId */
FFG(0020c723) { UNUSED; ff_sleep(ARG(0)); RET(0); }                             /* Sleep */
FFG(0020c6f7) { UNUSED; RET(ff_wait(ARG(0), ARG(1))); }                         /* WaitForSingleObject */
FFG(0020c2c9) {         /* CreateSemaphoreA(sa, initial, max, name) */
    UNUSED;
    uint32_t h = ff_new_obj(OBJ_SEMAPHORE);
    ff_obj(h)->count = (int32_t)ARG(1);
    ff_obj(h)->max = (int32_t)ARG(2);
    RET(h);
}
FFG(0020c380) {         /* ReleaseSemaphore(h, n, previous*) */
    UNUSED;
    hulk_obj* o = ff_obj(ARG(0));
    if (!o || o->kind != OBJ_SEMAPHORE) { RET(0); return; }
    if (ARG(2)) *(uint32_t*)PTR(ARG(2)) = (uint32_t)o->count;
    if (o->count + (int32_t)ARG(1) > o->max) { RET(0); return; }
    o->count += (int32_t)ARG(1);
    wake_waiters(ARG(0));
    RET(1);
}

/* fibers */
FFG(00355563) {         /* ConvertThreadToFiber(param): the thread's own context becomes a fiber */
    UNUSED;
    hulk_obj* t = cur();
    hulk_obj* f = ff_obj(t->fiber);
    f->param = ARG(0);
    RET(t->fiber);
}
FFG(0035547e) { UNUSED; RET(new_fiber(ARG(1), ARG(2), 0)); }                   /* CreateFiber(stack, start, param) */
FFG(0035551d) {         /* SwitchToFiber(fiber) */
    UNUSED;
    hulk_obj* t = cur();
    uint32_t from = t->fiber, to = ARG(0);
    if (to == from) return;
    ff_io_main_sleep();     /* (a loader polling a request switches fibers without sleeping: a drive turn) */
    if (!ff_obj(to) || ff_obj(to)->kind != OBJ_FIBER) ff_fatal("SwitchToFiber(0x%x): no fiber", to);
    t->fiber = to;
    ff_obj(to)->thread = SIM->cur_thread;
    fiber_swap(ctx_of(from), ctx_of(to));
}
FFG(0035550a) { UNUSED; ff_close_obj(ARG(0)); RET(0); }                         /* DeleteFiber */

/* the threads and what each waits for (the end of a run) */
void ff_dump_threads(void) {
    for (uint32_t i = 0; i < MAX_OBJS; i++) {
        hulk_obj* o = &SIM->objs[i];
        if (o->kind == OBJ_THREAD)
            fprintf(stderr, "hulk: thread 0x%x state %u wait 0x%x fiber 0x%x%s\n", HANDLE_BASE + i * 4, o->state,
                    o->wait, o->fiber, HANDLE_BASE + i * 4 == SIM->cur_thread ? " (running)" : "");
        else if (o->kind == OBJ_SEMAPHORE)
            fprintf(stderr, "hulk: semaphore 0x%x count %d\n", HANDLE_BASE + i * 4, o->count);
        else if (o->kind == OBJ_FIBER)
            fprintf(stderr, "hulk: fiber 0x%x entry 0x%08x\n", HANDLE_BASE + i * 4, o->entry);
    }
}

/* ------------------------------------------------------------------------------------------- setjmp/longjmp */
static hfiber* running_ctx(void) { return ctx_of(cur()->fiber); }
FFG(00347250) {         /* _setjmp3(jmp_buf, count): 0, or a longjmp's value */
    UNUSED;
    hfiber* c = running_ctx();
    sj_mode = SJ_CAPTURE;
    sj_jb = ARG(0);
    fiber_swap(c, c);
    RET(sj_result);
}
FFG(003471d4) {         /* longjmp(jmp_buf, value) */
    UNUSED;
    hfiber* c = running_ctx();
    sj_mode = SJ_JUMP;
    sj_jb = ARG(0);
    sj_value = ARG(1) ? ARG(1) : 1;
    fiber_swap(c, c);
    ff_fatal("longjmp returned");
}

void ff_sched_stats(void) {
    fprintf(stderr, "hulk: %llu fiber switches, %llu setjmps (%.0f bytes each), %llu longjmps\n",
            (unsigned long long)n_swaps, (unsigned long long)n_setjmps, n_setjmps ? (double)sj_bytes / n_setjmps : 0.0,
            (unsigned long long)n_longjmps);
}

/* the stacks and Asyncify buffers in the arena (fibers' and continuations'): [lo, hi) pairs into out, their count.
 * Their dead bytes depend on the code generation, not on the game: frame.c's game hash leaves them out. */
int ff_stack_ranges(uint32_t* out, int cap) {
    int n = 0;
    for (uint32_t i = 0; i < MAX_OBJS && n + 3 <= cap; i++) {
        hulk_obj* o = &SIM->objs[i];
        if (o->kind != OBJ_FIBER || !o->ctx) continue;
        hfiber* c = PTR(o->ctx);
        out[2 * n] = c->stack_lo, out[2 * n + 1] = c->stack_hi, n++;
        out[2 * n] = c->buf, out[2 * n + 1] = c->buf + c->size, n++;
        if (n < cap) out[2 * n] = o->ctx, out[2 * n + 1] = o->ctx + sizeof *c, n++;   /* (saved stack pointers) */
    }
    hcont* k = PTR(SIM->sj_conts);
    if (k && n < cap) out[2 * n] = SIM->sj_conts, out[2 * n + 1] = SIM->sj_conts + MAX_CONTS * sizeof *k, n++;
    for (int i = 0; k && i < MAX_CONTS && n < cap; i++)
        if (k[i].buf) out[2 * n] = k[i].buf, out[2 * n + 1] = k[i].buf + k[i].cap, n++;
    return n;
}
