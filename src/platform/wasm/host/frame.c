/* The end of a frame (D3D Swap): the virtual clock moves on one 60 Hz field, the next frame's input is applied, and
 * the run's statistics are kept (HULK_FRAMES ends the run; the frame rate is reported every HULK_REPORT frames). */
#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include "hulk_host.h"
#include "sim.h"

static double t0, t_last;
void ff_frame_end(void) {
    static long limit = -1, every = 0;
    if (limit < 0) {
        limit = getenv("HULK_FRAMES") ? atol(getenv("HULK_FRAMES")) : 0;
        every = getenv("HULK_REPORT") ? atol(getenv("HULK_REPORT")) : 600;
        t0 = t_last = emscripten_get_now();
    }
    SIM->frame++;
    if (getenv("HULK_STACK_AT") && SIM->frame == (uint32_t)atol(getenv("HULK_STACK_AT")))
        ff_fatal("stack at frame %u (HULK_STACK_AT)", SIM->frame);
    SIM->clock += HULK_TSC_HZ / 60;
    if (every && SIM->frame % every == 0) {
        double now = emscripten_get_now();
        fprintf(stderr, "hulk: frame %u (%.0f frames/s over the last %ld, %.1f s in all)\n", SIM->frame,
                every * 1000.0 / (now - t_last), every, (now - t0) / 1000.0);
        t_last = now;
    }
    if (limit && SIM->frame >= (uint32_t)limit) {
        void ff_dump_threads(void);
        if (getenv("HULK_THREADS")) ff_dump_threads();
        double now = emscripten_get_now();
        fprintf(stderr, "hulk: %u frames in %.2f s (%.0f frames/s)\n", SIM->frame, (now - t0) / 1000.0,
                SIM->frame * 1000.0 / (now - t0));
        exit(0);
    }
}
