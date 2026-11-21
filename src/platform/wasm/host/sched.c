/* Threads, fibers and waits, cooperatively (docs/wasm-port.md "Threads and fibers").
 *
 * Every thread runs on a fiber (Emscripten's, through Asyncify: a suspended fiber's state is its C stack and its
 * Asyncify buffer, both in the game arena or at the main thread's fixed stack). Exactly one thread runs; it switches
 * only when the game waits for an object that isn't signaled, sleeps, exits or switches fibers itself. The next
 * thread is the first runnable one after the current in handle order; when none is runnable the virtual clock jumps to
 * the earliest deadline. So a run is a function of its inputs alone. */
#include <emscripten/fiber.h>
#include <stdio.h>
#include <stdlib.h>
#include "hulk_host.h"
#include "sim.h"

#define MAIN_STACK_LO 0x00E00000u
#define MAIN_STACK_HI 0x00F00000u
#define FIBER_C_STACK (256u << 10)
#define ASYNCIFY_STACK (256u << 10)
#define INFINITE 0xffffffffu
#define WAIT_TIMEOUT 0x102u

static emscripten_fiber_t host_ctx;          /* the host's own context (start-up and the end of the run) */
static char host_async[64 << 10];

static uint64_t deadline(hulk_obj* t) { return (uint64_t)t->deadline_hi << 32 | t->deadline_lo; }
static void set_deadline(hulk_obj* t, uint64_t d) { t->deadline_lo = (uint32_t)d; t->deadline_hi = (uint32_t)(d >> 32); }
static emscripten_fiber_t* ctx_of(uint32_t fiber) { return PTR(ff_obj(fiber)->ctx); }

static void fiber_main(void* arg);

/* a fiber object with its own context, not started */
static uint32_t new_fiber(uint32_t entry, uint32_t param, uint32_t thread) {
    uint32_t h = ff_new_obj(OBJ_FIBER);
    hulk_obj* f = ff_obj(h);
    f->entry = entry;
    f->param = param;
    f->thread = thread;
    emscripten_fiber_t* c = ff_arena_alloc(sizeof *c, 16);
    void* cs = ff_arena_alloc(FIBER_C_STACK, 16);
    void* as = ff_arena_alloc(ASYNCIFY_STACK, 16);
    emscripten_fiber_init(c, fiber_main, (void*)(uintptr_t)h, cs, FIBER_C_STACK, as, ASYNCIFY_STACK);
    f->ctx = (uint32_t)(uintptr_t)c;
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
        emscripten_fiber_swap(ctx_of(from->fiber), ctx_of(to->fiber));
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

uint32_t ff_wait(uint32_t h, uint32_t ms) {
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
    hulk_obj* t = cur();
    t->state = T_SLEEPING;
    set_deadline(t, SIM->clock + (uint64_t)ms * (HULK_TSC_HZ / 1000));
    if (ms == 0) t->state = T_RUNNABLE;     /* a yield: others run first if they can */
    reschedule();
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
static void fiber_main(void* arg) {
    uint32_t h = (uint32_t)(uintptr_t)arg;
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
static void main_fiber(void* arg) {
    (void)arg;
    main_entry();
    ff_run_atexit();
    emscripten_fiber_swap(ctx_of(cur()->fiber), &host_ctx);
}

void ff_run_main(void (*entry)(void)) {
    main_entry = entry;
    uint32_t t = ff_new_obj(OBJ_THREAD);
    uint32_t f = ff_new_obj(OBJ_FIBER);
    emscripten_fiber_t* c = ff_arena_alloc(sizeof *c, 16);
    void* as = ff_arena_alloc(1u << 20, 16);
    emscripten_fiber_init(c, main_fiber, 0, PTR(MAIN_STACK_LO), MAIN_STACK_HI - MAIN_STACK_LO, as, 1u << 20);
    ff_obj(f)->ctx = (uint32_t)(uintptr_t)c;
    ff_obj(f)->thread = t;
    ff_obj(t)->fiber = f;
    ff_obj(t)->state = T_RUNNABLE;
    SIM->cur_thread = t;
    emscripten_fiber_init_from_current_context(&host_ctx, host_async, sizeof host_async);
    emscripten_fiber_swap(&host_ctx, c);
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
    if (!ff_obj(to) || ff_obj(to)->kind != OBJ_FIBER) ff_fatal("SwitchToFiber(0x%x): no fiber", to);
    t->fiber = to;
    ff_obj(to)->thread = SIM->cur_thread;
    emscripten_fiber_swap(ctx_of(from), ctx_of(to));
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
