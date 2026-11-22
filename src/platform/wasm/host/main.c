/* The wasm32 port's entry and failure paths (docs/wasm-port.md). */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hulk_host.h"

void ff_log(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

void ff_fatal(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "hulk: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    abort();
}

/* a call to a function nothing defines yet: the host's work list (tools/wasm_port.py report) */
void ff_unbound(uint32_t addr, const char* what) { ff_fatal("unbound %s at 0x%08x", what, addr); }
void ff_unbound_name(const char* name) { ff_fatal("unbound %s", name); }

/* HULK_TRACE=1: every host function the game calls, with its first stack words (not under HULK_WATCH: a watch prints
 * only the changes of its word) */
int ff_trace_on, ff_trace_watch;
void ff_trace_host_(const char* fn, void* st) {
    const uint32_t* a = st;
    if (ff_trace_watch)
        return;
    fprintf(stderr, "host %s (%08x %08x %08x %08x)\n", fn, a[0], a[1], a[2], a[3]);
}

/* HULK_WATCH=ADDR[:FROM-TO]: with HULK_TRACE=2, only the calls through ff_dispatch around a change of the word at ADDR
 * (in update frames FROM..TO): finding the code that writes it */
uint32_t ff_replay_frame(void);
void ff_trace_dispatch(uint32_t a, uint32_t ecx, void* st) {
    const uint32_t* s = st;
    static int watch = -1;
    static uint32_t waddr, wfrom, wto, last, prev_a, prev_ecx;
    if (watch < 0) {
        const char* w = getenv("HULK_WATCH");
        watch = w && *w;
        if (watch) {
            char* e;
            waddr = (uint32_t)strtoul(w, &e, 16);
            wfrom = 0, wto = ~0u;
            if (*e == ':') { wfrom = (uint32_t)strtoul(e + 1, &e, 10); wto = *e == '-' ? (uint32_t)strtoul(e + 1, 0, 10) : wfrom; }
            last = *(uint32_t*)PTR(waddr);
        }
    }
    if (watch) {
        uint32_t v = *(uint32_t*)PTR(waddr), f = ff_replay_frame();
        if (v != last && f >= wfrom && f <= wto)
            fprintf(stderr, "watch f=%u %08x -> %08x between call 0x%08x (ecx %08x) and call 0x%08x ecx=%08x (%08x %08x %08x)\n",
                    f, last, v, prev_a, prev_ecx, a, ecx, s[0], s[1], s[2]);
        last = v, prev_a = a, prev_ecx = ecx;
        return;
    }
    fprintf(stderr, "call 0x%08x ecx=%08x (%08x %08x %08x)\n", a, ecx, s[0], s[1], s[2]);
}

double ff_now_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6;
}

int main(int argc, char** argv) {
    ff_trace_on = getenv("HULK_TRACE") ? atoi(getenv("HULK_TRACE")) : 0;
    ff_trace_watch = getenv("HULK_WATCH") && *getenv("HULK_WATCH");
    const char* xbe = argc > 1 ? argv[1] : getenv("HULK_XBE");
    if (!xbe) {
        fprintf(stderr, "usage: hulk DEFAULT.XBE (the game's own, from its disc)\n");
        return 2;
    }
    return ff_boot(xbe);
}
