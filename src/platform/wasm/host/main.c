/* The wasm32 port's entry and failure paths (docs/wasm-port.md). */
#include <stdio.h>
#include <stdlib.h>
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

/* HULK_TRACE=1: every host function the game calls, with its first stack words */
int ff_trace_on;
void ff_trace_host_(const char* fn, void* st) {
    const uint32_t* a = st;
    fprintf(stderr, "host %s (%08x %08x %08x %08x)\n", fn, a[0], a[1], a[2], a[3]);
}

void ff_trace_dispatch(uint32_t a, uint32_t ecx, void* st) {
    const uint32_t* s = st;
    fprintf(stderr, "call 0x%08x ecx=%08x (%08x %08x %08x)\n", a, ecx, s[0], s[1], s[2]);
}

int main(int argc, char** argv) {
    ff_trace_on = getenv("HULK_TRACE") ? atoi(getenv("HULK_TRACE")) : 0;
    const char* xbe = argc > 1 ? argv[1] : getenv("HULK_XBE");
    if (!xbe) {
        fprintf(stderr, "usage: hulk DEFAULT.XBE (the game's own, from its disc)\n");
        return 2;
    }
    return ff_boot(xbe);
}
