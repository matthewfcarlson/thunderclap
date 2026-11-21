/* Start-up: the XBE's image at its own addresses, the kernel's imports, the game's static initializers, main.
 *
 * What the original's entry point does, minus the XAPI and C library's own initialization (theirs is the host's):
 * the C++ dynamic initializer table (.CRT$XCA..XCZ, game initializers only), then main. */
#include <stdio.h>
#include <stdlib.h>
#include "hulk_host.h"
#include "hulk_io.h"
#include "sim.h"

#define KERNEL_KEY 0x5B6D40B6u       /* retail XOR key of the kernel thunk address (public XBE format) */

static uint8_t* mem(uint32_t va) { return (uint8_t*)(uintptr_t)va; }
static uint32_t rd32(const uint8_t* p) { return p[0] | p[1] << 8 | p[2] << 16 | (uint32_t)p[3] << 24; }

/* library code inside the XBE (tools/platform_map.py): its initializers are the host's business */
static int is_library(uint32_t a) {
    return (a >= 0x208b9c && a < 0x212bb0) || (a >= 0x3440e0 && a < 0x356bf0) || (a >= 0x35a7b0 && a < 0x35be88) ||
           (a >= 0x364840 && a < 0x3f2be0);
}

static int load_xbe(const char* path) {
    int32_t f = hio_open(path, HIO_READ);
    if (f < 0) { fprintf(stderr, "hulk: can't open %s\n", path); return -1; }
    uint32_t n = hio_size(f);
    uint8_t* x = malloc(n);
    if (!x || hio_read(f, x, n, 0) != (int32_t)n) { hio_close(f); free(x); return -1; }
    hio_close(f);
    if (memcmp(x, "XBEH", 4) || rd32(x + 0x104) != XBE_BASE) {
        fprintf(stderr, "hulk: %s is no XBE\n", path);
        free(x);
        return -1;
    }
    uint32_t headers = rd32(x + 0x108), nsec = rd32(x + 0x11c), sec = rd32(x + 0x120) - XBE_BASE;
    memcpy(mem(XBE_BASE), x, headers);
    for (uint32_t i = 0; i < nsec; i++) {
        const uint8_t* s = x + sec + i * 56;
        uint32_t va = rd32(s + 4), vsize = rd32(s + 8), raw = rd32(s + 12), rsize = rd32(s + 16);
        if (va < XBE_BASE || va + vsize > XBE_END + 0x10000) {
            fprintf(stderr, "hulk: section at 0x%08x outside the image\n", va);
            free(x);
            return -1;
        }
        memset(mem(va), 0, vsize);
        memcpy(mem(va), x + raw, rsize < vsize ? rsize : vsize);
    }
    uint32_t thunks = rd32(x + 0x158) ^ KERNEL_KEY;
    int k = 0;
    for (uint32_t* t = (uint32_t*)mem(thunks); *t; t++) {
        uint32_t ord = *t & 0x7fffffff;
        *t = KERNEL_FN + ord;
        (void)k;
    }
    free(x);
    return 0;
}

static void call3(uint32_t addr, uint32_t a0, uint32_t a1, uint32_t a2) {
    uint32_t st[8] = {a0, a1, a2};
    uint64_t rb[2] = {0};
    ff_dispatch(addr, 0, 0, st, rb);
}

static void game_main(void) {
    int run = 0, skipped = 0;
    for (uint32_t p = HULK_XC_A + 4; p < HULK_XC_Z; p += 4) {
        uint32_t fn = rd32(mem(p));
        if (!fn || fn == 0xffffffffu) continue;
        if (is_library(fn) || !ff_lookup(fn)) {
            if (!is_library(fn)) fprintf(stderr, "hulk: static initializer 0x%08x has no definition\n", fn);
            skipped++;
            continue;
        }
        call3(fn, 0, 0, 0);
        run++;
    }
    fprintf(stderr, "hulk: %d static initializers run (%d skipped); main\n", run, skipped);
    call3(HULK_MAIN, 0, 0, 0);
    fprintf(stderr, "hulk: main returned\n");
}

int ff_boot(const char* xbe) {
    if (load_xbe(xbe)) return 1;
    SIM->magic = 0x4d49534bu;   /* "KSIM" */
    SIM->size = sizeof(hulk_sim);
    SIM->pads_in = 1;           /* a gamepad in port 0 */
    ff_run_main(game_main);     /* (sched.c: the game's main thread on its fiber) */
    return 0;
}


/* host methods: objects the host hands the game need addresses it can call through ff_dispatch */
static ffg_t methods[256];
static uint32_t nmethods;
uint32_t ff_host_method(ffg_t f) {
    for (uint32_t i = 0; i < nmethods; i++)
        if (methods[i] == f) return HOST_FN + i;
    if (nmethods == 256) ff_fatal("too many host methods");
    methods[nmethods] = f;
    return HOST_FN + nmethods++;
}

void ff_dispatch_miss(uint32_t addr, uint32_t ecx, uint32_t edx, void* st, void* rb) {
    if ((addr & 0xFFFFFF00u) == HOST_FN && (addr & 0xFF) < nmethods) methods[addr & 0xFF](ecx, edx, st, rb);
    else if ((addr & 0xFFFFF000u) == KERNEL_FN) ff_kernel(addr & 0xFFF, ecx, edx, st, rb);
    else {
        uint32_t vft = ecx && ecx < 0x40000000u ? *(uint32_t*)PTR(ecx) : 0;
        fprintf(stderr, "hulk: this=0x%08x vftable=0x%08x stack %08x %08x %08x\n", ecx, vft, ARG(0), ARG(1), ARG(2));
        if (vft && vft < 0x40000000u)
            for (int i = 0; i < 8; i++) fprintf(stderr, "  slot %d: 0x%08x\n", i, ((uint32_t*)PTR(vft))[i]);
        (void)rb;
        ff_fatal("indirect call to 0x%08x, which is no function", addr);
    }
}

uint32_t ff_call(uint32_t addr, int n, ...) {
    uint32_t st[16] = {0};
    uint64_t rb[2] = {0};
    va_list ap;
    va_start(ap, n);
    for (int i = 0; i < n && i < 16; i++) st[i] = va_arg(ap, uint32_t);
    va_end(ap);
    ff_dispatch(addr, 0, 0, st, rb);
    return (uint32_t)rb[0];
}

uint32_t ff_call_this(uint32_t addr, uint32_t self, int n, ...) {
    uint32_t st[16] = {0};
    uint64_t rb[2] = {0};
    va_list ap;
    va_start(ap, n);
    for (int i = 0; i < n && i < 16; i++) st[i] = va_arg(ap, uint32_t);
    va_end(ap);
    ff_dispatch(addr, self, 0, st, rb);
    return (uint32_t)rb[0];
}
