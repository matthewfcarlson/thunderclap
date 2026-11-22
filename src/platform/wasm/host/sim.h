/* The host's own state that the game observes, at a fixed address in linear memory (docs/wasm-port.md): with the
 * XBE image and the game arena it is the whole game state, so a snapshot or a state hash covers it. */
#ifndef HULK_WASM_SIM_H
#define HULK_WASM_SIM_H
#include <stdint.h>

#define SIM_ADDR 0x00F00000u          /* above the game stack (0xE00000..0xF00000), below the arena (16 MB) */

#define HULK_TSC_HZ 733333333ull      /* the console's timestamp counter (QueryPerformanceFrequency) */

/* kernel objects, addressed by handle HANDLE_BASE + 4 * index */
#define HANDLE_BASE 0x00001000u
#define MAX_OBJS 256
enum { OBJ_NONE, OBJ_FILE, OBJ_THREAD, OBJ_FIBER, OBJ_SEMAPHORE, OBJ_EVENT, OBJ_HEAP, OBJ_SAVE_FIND };
enum { T_RUNNABLE, T_WAITING, T_SLEEPING, T_DONE };
typedef struct {
    int32_t kind, refs;
    /* files */
    char path[200];
    uint32_t writable, pos;
    /* semaphores (count, max) and events (signaled, manual reset); a thread is signaled when done */
    int32_t count, max;
    uint32_t signaled, manual;
    /* threads: state, what it waits for, until when (clock), its current fiber, exit code, timed out */
    uint32_t state, wait, deadline_lo, deadline_hi, fiber, exit_code, done, timed_out;
    /* fibers: the context (an emscripten_fiber_t in the arena), entry, parameter, started */
    uint32_t ctx, entry, param, thread;
} hulk_obj;

typedef struct {
    uint32_t magic, size;
    uint32_t arena_ready, arena_top;  /* arena.c */
    uint32_t arena_lb[32];            /* arena.c: no free block of 2^k bytes or more below arena_lb[k] (0: the base) */
    uint64_t clock;                   /* the virtual clock: ticks of the 733 MHz timestamp counter */
    uint32_t frame;                   /* Presents so far */
    uint32_t kernel_data[16];         /* kernel data exports the import table points at */
    uint32_t rand_seed, strtok_next, crt_errno;   /* crt.c */
    uint32_t natexit, atexit[256];
    uint32_t last_error;
    uint32_t pads_in, pads_reported;  /* input.c: ports with a gamepad, and what the game was last told */
    uint8_t pads[4][20];              /* XINPUT_GAMEPAD per port (18 bytes used) */
    uint32_t cur_thread;              /* sched.c: the running thread's handle */
    uint32_t polls;                   /* sched.c: polls of the clock (a time slice every 32) */
    uint32_t sj_conts, sj_age;        /* sched.c: setjmp continuations (an array in the arena), their clock */
    hulk_obj objs[MAX_OBJS];
    /* d3d_null.c */
    uint32_t d3d_device, d3d_back, d3d_depth, d3d_rt, d3d_ds, d3d_vs, d3d_ps, d3d_shaders, d3d_vblank_cb;
    uint32_t d3d_viewport[6];
    uint8_t d3d_gamma[768];          /* D3DGAMMARAMP (Xbox: 256 bytes a channel) */
    float d3d_xf[24][16];
    uint32_t d3d_xf_set[24];
    uint8_t d3d_lights[8][104];
    /* dsound_null.c */
    uint32_t ds_object;
    uint32_t ds_voices;               /* the live buffers (a list in the arena) */
    /* arena.c (wasm15): no free block of 16k bytes or more below arena_lbn[k] (k = 1..64; 0: the base) */
    uint32_t arena_lbn[65];
    uint32_t ds_clock;                /* the voices' clock: 0 a DirectSoundDoWork (replays), 1 the virtual clock */
    uint32_t ds_spare;
    uint64_t ds_frames;               /* ds_clock 1: the virtual clock's 48 kHz frames the voices have reached */
} hulk_sim;

#define SIM ((hulk_sim*)(uintptr_t)SIM_ADDR)
hulk_obj* ff_obj(uint32_t h);
uint32_t ff_new_obj(int kind);
void ff_close_obj(uint32_t h);
#endif
