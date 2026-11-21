/* The wasm32 port's host side (docs/wasm-port.md).
 *
 * The game's functions are linked by their original addresses (tools/wasm_port.py). A generic entry is
 * void ffg_<addr>(uint32_t ecx, uint32_t edx, void* st, void* rb): the arguments where x86 had them (st: the stack,
 * 4-byte slots) and the result stored at rb (eax:edx at +0, st0 at +8, as a double). A library function the game
 * calls (CRT, XAPI, D3D, DirectSound, XInput: code inside the XBE that the tree doesn't define) is the host's: it
 * defines FFG(addr). A variadic library function that callers declare variadic is also called directly as
 * ff_<addr>(...), with wasm's va_list.
 *
 * Game state lives in linear memory only: the XBE image at its own addresses and the game arena (arena.c), so a
 * snapshot is those bytes and two runs with the same inputs hash the same. */
#ifndef HULK_WASM_HOST_H
#define HULK_WASM_HOST_H
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

#define FFG(addr) void ffg_##addr(uint32_t ecx, uint32_t edx, void* st, void* rb)
#define ARG(i) (((uint32_t*)st)[i])
#define ARGF(i) (*(float*)&((uint32_t*)st)[i])
#define ARGD(i) (*(double*)&((uint32_t*)st)[i])
#define PTR(a) ((void*)(uintptr_t)(a))
#define RET(v) (*(uint64_t*)rb = (uint32_t)(v))
#define RET64(v) (*(uint64_t*)rb = (uint64_t)(v))
#define RETF(v) (((double*)rb)[1] = (double)(v))
#define UNUSED (void)ecx, (void)edx, (void)st, (void)rb, ff_trace_host(__func__, st)
extern int ff_trace_on;
void ff_trace_host_(const char* fn, void* st);
#define ff_trace_host(fn, st) (ff_trace_on ? ff_trace_host_(fn, st) : (void)0)

/* the XBE (public format) */
#define XBE_BASE 0x10000u
#define XBE_END 0x589860u
/* the C++ dynamic initializer table (.CRT$XCA..XCZ: tools/wine_host.py XC_A/XC_Z) and the game's main */
#define HULK_XC_A 0x0048ca90u
#define HULK_XC_Z 0x0048d4f4u
#define HULK_MAIN 0x0008ee30u
/* the game arena: memory the game is handed and keeps pointers to (16 MB..1 GB, below Emscripten's static data;
 * a snapshot covers it up to its top) */
#define ARENA_LO (16u << 20)
#define ARENA_HI (1024u << 20)
/* addresses that are no game code: kernel imports and host methods (ff_dispatch_miss) */
#define KERNEL_FN 0xE0000000u
#define HOST_FN 0xE1000000u

typedef void (*ffg_t)(uint32_t, uint32_t, void*, void*);
void ff_dispatch(uint32_t addr, uint32_t ecx, uint32_t edx, void* st, void* rb);
ffg_t ff_lookup(uint32_t addr);
void ff_unbound(uint32_t addr, const char* what);
void ff_log(const char* fmt, ...);
void ff_fatal(const char* fmt, ...) __attribute__((noreturn));

void* ff_arena_alloc(uint32_t n, uint32_t align);   /* zeroed */
void ff_arena_free(void* p);
void* ff_arena_realloc(void* p, uint32_t n);
uint32_t ff_arena_usable(void* p);
uint32_t ff_arena_base(void);
uint32_t ff_arena_top(void);

/* call a game function by its address: N stack arguments, the result's eax */
uint32_t ff_call(uint32_t addr, int n, ...);
uint32_t ff_call_this(uint32_t addr, uint32_t self, int n, ...);

/* a host function the game can call through a pointer (objects the host hands it) */
uint32_t ff_host_method(ffg_t f);

double ff_now_ms(void);    /* the host's monotonic clock (measurements only, never game state) */
int ff_boot(const char* xbe);
void ff_run_atexit(void);
void ff_run_main(void (*entry)(void));
uint32_t ff_wait(uint32_t h, uint32_t ms);
void ff_sleep(uint32_t ms);
void ff_poll(void);
void ff_on_host_stack(void (*fn)(void*), void* arg);    /* host work off the game's stacks */
int ff_host_path(const char* game, char* out, size_t cap);
void ff_kernel(uint32_t ord, uint32_t ecx, uint32_t edx, void* st, void* rb);
#endif
