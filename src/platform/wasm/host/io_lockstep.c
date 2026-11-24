/* Lockstep I/O in a replay (the Wine build's HULK_SYNCIO=5, src/platform/sdl/xdk/replay_hooks.cpp "native17"): the
 * drive thread (core::DriveThread's routine 0x002731d0) runs one request step at a time, and only while the main
 * thread hands it a turn, so the frame a file request's result lands in is the hybrid recording's:
 *   - after each post of the main thread (0x00272fc0, an entry hook here: the post runs, then the turn) the drive
 *     runs until its queue is empty or HULK_IO_IDLE (default 4) steps in a row retire nothing; the turn waits while
 *     the main thread holds a critical section (the post's caller may hold a lock the step takes);
 *   - at each GameClock::Update entry, when the main thread sleeps, switches fibers or pumps the drive (0x00272df0):
 *     the same;
 *   - when the main thread waits on a handle: one step at a time while the handle is unsignalled and a drive has work.
 * A step boundary is the drive's wait on its `ready` semaphore (drive +0x68): it reports its arrival and waits for the
 * next grant. A step that waits for the main thread (more than 5 s of the virtual clock) is left to finish on its own.
 * The threads are cooperative (sched.c), so the arrive/grant semaphores are ordinary objects and every wait is
 * deterministic. Off without a recording, or with HULK_SYNCIO=0. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hulk_host.h"
#include "sim.h"

#define INFINITE 0xffffffffu
#define WAIT_TIMEOUT 0x102u
#define DRIVE_ROUTINE 0x002731d0u    /* core::DriveThread's thread routine */
#define THREAD_TRAMPOLINE 0x0026db70u /* the routine 0x0026dc50 passes to CreateThread */

typedef struct {
    uint32_t drive, ready, done, thread;
    uint32_t arrive, grant;     /* host semaphores */
    int need_arrival, in_done, inner;
} ls_drive;
static ls_drive drives[4];
static int ndrives, mode = -1, idle_steps = 4, in_ls, io_log;
static uint32_t main_thread, cs_depth, post_pending, steps, blocked, posts;

/* the state above, for playthrough snapshots (sched.c ff_snap_write / ff_snap_read): copied out (restore 0) or back */
uint32_t ff_io_blob(void* buf, int restore) {
    struct {
        ls_drive drives[4];
        int ndrives, mode, idle_steps, in_ls, io_log;
        uint32_t main_thread, cs_depth, post_pending, steps, blocked, posts;
    } * b = buf;
#define IO_FIELD(x) (restore ? memcpy(&x, &b->x, sizeof x) : memcpy(&b->x, &x, sizeof x))
    IO_FIELD(drives), IO_FIELD(ndrives), IO_FIELD(mode), IO_FIELD(idle_steps), IO_FIELD(in_ls), IO_FIELD(io_log);
    IO_FIELD(main_thread), IO_FIELD(cs_depth), IO_FIELD(post_pending), IO_FIELD(steps), IO_FIELD(blocked);
    IO_FIELD(posts);
#undef IO_FIELD
    return (uint32_t)sizeof *b;
}

int ff_replay_active(void);     /* replay.cpp */
void ff_replay_log(const char* line);
static void log_line(const char* fmt, ...) __attribute__((format(printf, 1, 2)));
static void log_line(const char* fmt, ...) {
    char line[200];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(line, sizeof line, fmt, ap);
    va_end(ap);
    ff_replay_log(line);
}

static int on(void) {
    if (mode < 0) {
        const char* e = getenv("HULK_SYNCIO");
        mode = e && *e ? e[0] - '0' : ff_replay_active() ? 5 : 0;
        e = getenv("HULK_IO_IDLE");
        if (e && *e >= '1' && *e <= '9') idle_steps = *e - '0';
        io_log = getenv("HULK_SYNCIO_LOG") && getenv("HULK_SYNCIO_LOG")[0] == '1';
    }
    return mode == 5;
}
static int on_main(void) { return main_thread && SIM->cur_thread == main_thread; }
static uint32_t count_of(const ls_drive* d) { return *(volatile uint32_t*)PTR(d->drive + 0x8c); }
static uint32_t new_sem(void) {
    uint32_t h = ff_new_obj(OBJ_SEMAPHORE);
    ff_obj(h)->max = 0x7fffffff;
    return h;
}
static void release(uint32_t h) {
    ff_obj(h)->count++;
    void ff_wake(uint32_t h);
    ff_wake(h);
}

/* the game's main thread (boot: the thread that runs main) */
void ff_io_main_thread(uint32_t t) { main_thread = t; }

/* CreateThread: a drive thread runs in lockstep */
void ff_io_thread_created(uint32_t start, uint32_t param, uint32_t thread) {
    if (start != THREAD_TRAMPOLINE || !param || !on() || ndrives == 4) return;
    if (*(uint32_t*)PTR(param + 8) != DRIVE_ROUTINE) return;
    ls_drive* d = &drives[ndrives++];
    d->drive = *(uint32_t*)PTR(param + 0xc);
    d->ready = *(uint32_t*)PTR(d->drive + 0x68);
    d->done = *(uint32_t*)PTR(d->drive + 0x84);
    d->thread = thread;
    d->arrive = new_sem();
    d->grant = new_sem();
    d->need_arrival = 1;
    log_line("io lockstep: drive %d at %08x (ready semaphore %08x)", ndrives - 1, d->drive, d->ready);
}

/* the drive thread at a step boundary (its wait on `ready`, or on `done` for the main thread): 1 = handled */
int ff_io_drive_wait(uint32_t h, uint32_t ms, uint32_t* result) {
    if (mode != 5 || ms != INFINITE || on_main()) return 0;
    for (int i = 0; i < ndrives; i++) {
        ls_drive* d = &drives[i];
        if (d->thread != SIM->cur_thread || d->inner) continue;
        if (h == d->done) {
            d->in_done = 1;
            release(d->arrive);
            d->inner = 1;
            ff_wait(d->grant, INFINITE);
            d->inner = 0;
            d->in_done = 0;
            *result = 0;
            return 1;
        }
        if (h != d->ready) continue;
        release(d->arrive);
        d->inner = 1;
        ff_wait(d->grant, INFINITE);
        *result = ff_wait(h, INFINITE);
        d->inner = 0;
        return 1;
    }
    return 0;
}

/* one step of drive d (main thread): 1 = the step ran and the drive is back at its boundary */
static int step(ls_drive* d) {
    in_ls++;
    int ok = 0;
    if (d->need_arrival) {
        if (ff_wait(d->arrive, 5000) != 0) goto out;
        d->need_arrival = 0;
    }
    if (d->in_done) {
        if (ff_wait(d->done, 0) != 0) goto out;
    } else if (!count_of(d)) {
        goto out;
    }
    release(d->grant);
    d->need_arrival = 1;
    steps++;
    if (ff_wait(d->arrive, 5000) != 0) {
        blocked++;
        log_line("io lockstep frame %u: a step still running after 5 s (it waits for the main thread); left to "
                 "finish on its own", SIM->frame);
        goto out;
    }
    d->need_arrival = 0;
    ok = 1;
out:
    in_ls--;
    return ok;
}

static void settle(void) {
    for (int i = 0; i < ndrives; i++) {
        uint32_t idle = 0;
        for (int n = 0; n < 100000; n++) {
            uint32_t before = count_of(&drives[i]);
            if (!before || !step(&drives[i])) break;
            if (count_of(&drives[i]) < before) idle = 0;
            else if (++idle >= (uint32_t)idle_steps) break;
        }
    }
}

/* the main thread sleeps, switches fibers or pumps the drive; GameClock::Update's entry */
void ff_io_main_sleep(void) {
    if (!in_ls && ndrives && on() && on_main()) settle();
}

/* the main thread about to wait on h: drive steps while it is unsignalled and a drive has work */
int ff_io_main_wait(uint32_t h, uint32_t* result) {
    if (in_ls || !ndrives || !on() || !on_main()) return 0;
    for (int n = 0; n < 100000; n++) {
        in_ls++;
        uint32_t r = ff_wait(h, 0);
        in_ls--;
        if (r != WAIT_TIMEOUT) {
            *result = r;
            return 1;
        }
        int stepped = 0;
        for (int i = 0; i < ndrives && !stepped; i++)
            if (count_of(&drives[i])) stepped = step(&drives[i]);
        if (!stepped) return 0;
    }
    return 0;
}

/* the main thread's critical sections (kernel.c): a post's turn waits for the last leave */
void ff_io_cs_enter(void) {
    if (on_main()) cs_depth++;
}
void ff_io_cs_leave(void) {
    if (!on_main()) return;
    if (cs_depth) cs_depth--;
    if (!cs_depth && post_pending) {
        post_pending = 0;
        if (!in_ls) settle();
    }
}

/* entry 0x00272fc0 core::DriveThread's post (`this` the drive, the node first): the post, then the drive's turn */
void ffgo_00272fc0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_nhook_drive_post(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    ffgo_00272fc0(ecx, edx, st, rb);
    if (!on() || !ecx || !ARG(0) || !on_main()) return;
    posts++;
    if (io_log) log_line("io post frame %u class %08x count %u", SIM->frame, *(uint32_t*)PTR(ARG(0)),
                         *(uint32_t*)PTR(ecx + 0x8c));
    if (cs_depth) post_pending = 1;
    else if (!in_ls) settle();
}

/* entry 0x00272df0 core::Drive::vfunc_3, the main thread's drive pump */
void ffgo_00272df0(uint32_t, uint32_t, void*, void*);
void ffh_hulk_nhook_drive_pump(uint32_t ecx, uint32_t edx, void* st, void* rb) {
    void ff_poll(void);
    if (!on()) ff_poll();   /* (no lockstep: a loader spinning on the pump lets the drive thread run, as preemption would) */
    ff_io_main_sleep();
    ffgo_00272df0(ecx, edx, st, rb);
}

void ff_io_stats(uint32_t* p, uint32_t* s, uint32_t* b) { *p = posts; *s = steps; *b = blocked; }
