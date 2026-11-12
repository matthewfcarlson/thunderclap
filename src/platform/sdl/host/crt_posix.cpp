// The C runtime glue of the native builds on macOS / Linux: the `glue` and `math` rows of
// src/platform/sdl/crt/native_crt_table.h (docs/native-mac.md "Host side"). Host side (system headers, the host's
// ABI), C linkage throughout. Not linked into an image yet. The behaviours below are the documented ones of the
// Microsoft C runtime the game was built against, reimplemented; no Microsoft code.
#if !defined(_WIN32)
#if defined(HULK_NATIVE_CANARY) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE 1   // dladdr (the debug canary allocator)
#endif
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// soft-intrinsics' routines when its header is in the tree (then the image links src/platform/sdl/crt/softx87.cpp);
// -DHULK_NO_SOFT_X87 takes the host's libm instead
#if defined(__has_include) && !defined(HULK_NO_SOFT_X87)
#if __has_include("../crt/softx87.h")
#include "../crt/softx87.h"
#define HULK_NCRT_SOFT_X87 1
#endif
#endif

typedef unsigned int hulk_u32;

extern "C" {
void hulk_native_missing(const char* name);   // entry_posix.cpp: report and exit

// ---------------------------------------------------------------------------------------------------------------
// /GS: the game's lifted code reads the cookie (XBE 0x004d9968) itself and hands it back; both sides read this word
hulk_u32 hulk_ncrt_security_cookie = 0xbb40e64eu;

void hulk_ncrt_security_check_cookie(uintptr_t cookie) {
    if ((hulk_u32)cookie != hulk_ncrt_security_cookie)
        hulk_native_missing("__security_check_cookie: stack cookie overwritten");
}

// atexit: the game's dynamic initializers register their destructors; entry_posix.cpp runs them after main
typedef void (*hulk_exit_fn)(void);
static hulk_exit_fn g_exit_fns[2048];
static hulk_u32 g_exit_n;

int hulk_ncrt_atexit(hulk_exit_fn fn) {
    if (g_exit_n >= sizeof(g_exit_fns) / sizeof(g_exit_fns[0]))
        return -1;
    g_exit_fns[g_exit_n++] = fn;
    return 0;
}

void hulk_crt_run_atexit(void) {
    while (g_exit_n)
        g_exit_fns[--g_exit_n]();
}

// The game's malloc (0x003479aa and the tree's `malloc`): zero-filled, as the Xbox's fresh heap pages are
// (docs/wine-build.md native11). free (0x003479bc) and realloc (0x00347d7a) are the host's, through the glue below so
// that the debug canary allocator sees them.
#if !defined(HULK_NATIVE_CANARY)
void* hulk_ncrt_malloc(size_t size) { return calloc(1, size ? size : 1); }
void hulk_ncrt_free(void* p) { free(p); }
void* hulk_ncrt_realloc(void* p, size_t size) { return realloc(p, size); }
#else
// The debug canary allocator (docs/native-build.md "The canary allocator"; compiled in only when the native link runs
// with HULK_NATIVE_DEBUG_CANARY=1, active only when the image runs with HULK_CANARY set). Each game block gets 16
// canary bytes after it; the last HULK_CANARY live blocks (default 256, at most 4096) are checked on every malloc,
// realloc and free, and a block's own canary when it is freed. A broken canary prints the block (size, allocation
// number, where it was allocated, the bytes past its end) and where it was found, then traps: a 64-bit overrun of a
// block sized for the 32-bit layout shows at the next allocation instead of as damage much later. Blocks the host
// frees without the glue stay in the ring (a false report then names a freed block).
#include <dlfcn.h>
#include <unwind.h>

enum { CANARY_BYTES = 16, CANARY_MAX = 4096, CANARY_DEPTH = 8 };
static const unsigned char CANARY = 0xab;
struct CanaryBlock {
    unsigned char* p;
    size_t size;
    unsigned long seq;
    void* ra[CANARY_DEPTH];
};
static CanaryBlock g_canary[CANARY_MAX];
static unsigned g_canary_slots;   // 0: off (HULK_CANARY unset)
static unsigned long g_canary_seq;
static int g_canary_init;

static unsigned canary_slots(void) {
    if (!g_canary_init) {
        g_canary_init = 1;
        const char* e = getenv("HULK_CANARY");
        if (e && *e && *e != '0') {
            long n = strtol(e, 0, 0);
            g_canary_slots = n > 1 ? (n > CANARY_MAX ? CANARY_MAX : (unsigned)n) : 256;
            fprintf(stderr, "canary: on, %u blocks checked\n", g_canary_slots);
        }
    }
    return g_canary_slots;
}

// the callers by the unwind tables (the game's objects need not keep frame pointers), from the glue's frame on
struct CanaryUnwind {
    void** ra;
    int n, skip;
};
static _Unwind_Reason_Code canary_frame(struct _Unwind_Context* c, void* arg) {
    CanaryUnwind* u = (CanaryUnwind*)arg;
    if (u->skip > 0) {
        --u->skip;
        return _URC_NO_REASON;
    }
    u->ra[u->n++] = (void*)_Unwind_GetIP(c);
    return u->n < CANARY_DEPTH ? _URC_NO_REASON : _URC_END_OF_STACK;
}

static void __attribute__((noinline)) canary_frames(void** ra) {
    CanaryUnwind u = {ra, 0, 1};
    for (int k = 0; k < CANARY_DEPTH; ++k)
        ra[k] = 0;
    _Unwind_Backtrace(canary_frame, &u);
}

static void canary_where(void* a) {
    Dl_info di;
    if (a && dladdr(a, &di) && di.dli_sname)
        fprintf(stderr, "    %p %s+0x%lx\n", a, di.dli_sname, (unsigned long)((char*)a - (char*)di.dli_saddr));
    else
        fprintf(stderr, "    %p\n", a);
}

static void canary_fail(const CanaryBlock* b, const char* when) {
    fprintf(stderr, "canary: block %p (%lu bytes, allocation %lu) overrun, found at %s (allocation %lu); bytes past "
            "its end:", (void*)b->p, (unsigned long)b->size, b->seq, when, g_canary_seq);
    for (int k = 0; k < CANARY_BYTES; ++k)
        fprintf(stderr, " %02x", b->p[b->size + k]);
    fprintf(stderr, "\n  allocated at:\n");
    for (int k = 0; k < CANARY_DEPTH; ++k)
        canary_where(b->ra[k]);
    void* ra[CANARY_DEPTH];
    canary_frames(ra);
    fprintf(stderr, "  found at:\n");
    for (int k = 0; k < CANARY_DEPTH; ++k)
        canary_where(ra[k]);
    fflush(stderr);
    __builtin_trap();
}

static int canary_ok(const CanaryBlock* b) {
    for (int k = 0; k < CANARY_BYTES; ++k)
        if (b->p[b->size + k] != CANARY)
            return 0;
    return 1;
}

static void canary_check_all(const char* when) {
    for (unsigned i = 0; i < g_canary_slots; ++i)
        if (g_canary[i].p && !canary_ok(&g_canary[i]))
            canary_fail(&g_canary[i], when);
}

static void canary_forget(void* p, const char* when) {
    for (unsigned i = 0; i < g_canary_slots; ++i)
        if (g_canary[i].p == p) {
            if (!canary_ok(&g_canary[i]))
                canary_fail(&g_canary[i], when);
            g_canary[i].p = 0;
        }
}

static void* canary_track(unsigned char* p, size_t size) {
    if (!p)
        return p;
    memset(p + size, CANARY, CANARY_BYTES);
    CanaryBlock* b = &g_canary[g_canary_seq % g_canary_slots];
    b->p = p;
    b->size = size;
    b->seq = ++g_canary_seq;
    canary_frames(b->ra);
    return p;
}

void* hulk_ncrt_malloc(size_t size) {
    if (!size)
        size = 1;
    if (!canary_slots())
        return calloc(1, size);
    canary_check_all("malloc");
    return canary_track((unsigned char*)calloc(1, size + CANARY_BYTES), size);
}

void hulk_ncrt_free(void* p) {
    if (p && canary_slots()) {
        canary_forget(p, "free");
        canary_check_all("free");
    }
    free(p);
}

void* hulk_ncrt_realloc(void* p, size_t size) {
    if (!canary_slots())
        return realloc(p, size);
    canary_check_all("realloc");
    if (p)
        canary_forget(p, "realloc");
    if (!size) {
        free(p);
        return 0;
    }
    return canary_track((unsigned char*)realloc(p, size + CANARY_BYTES), size);
}
#endif

// ---------------------------------------------------------------------------------------------------------------
// stdio: the game names the Xbox CRT's stdin / stdout / stderr by address (the `_iob` array at 0x004d99f0, three
// 32-byte FILEs); those cells are this proxy, mapped to the host's streams
unsigned char hulk_ncrt_iob_proxy[96];

static FILE* stream(void* f) {
    unsigned char* p = (unsigned char*)f;
    if (p >= hulk_ncrt_iob_proxy && p < hulk_ncrt_iob_proxy + sizeof(hulk_ncrt_iob_proxy)) {
        long i = (p - hulk_ncrt_iob_proxy) / 32;
        return i == 0 ? stdin : i == 1 ? stdout : stderr;
    }
    return (FILE*)f;
}

static int starts(const char* s, const char* prefix) {
    while (*prefix)
        if (tolower((unsigned char)*s++) != *prefix++)
            return 0;
    return 1;
}

// `D:\x\y` (the extracted game files, HULK_DATA_DIR), `T:\` (HULK_TDATA_DIR, else HULK_SAVE_DIR), `U:\` / `Z:\`
// (HULK_SAVE_DIR), `\x` (HULK_DATA_DIR) -> a host path with '/' separators; 0 if the path is not one we map
char* hulk_ncrt_host_path(const char* p, char* buf, size_t size) {
    const char* root = 0;
    const char* rest = 0;
    if (starts(p, "d:\\") || starts(p, "d:/")) {
        root = getenv("HULK_DATA_DIR");
        rest = p + 3;
    } else if (starts(p, "t:\\") && (root = getenv("HULK_TDATA_DIR")) != 0 && *root) {
        rest = p + 3;
    } else if (starts(p, "t:\\") || starts(p, "u:\\") || starts(p, "z:\\")) {
        root = getenv("HULK_SAVE_DIR");
        rest = p + 3;
    } else if (p[0] == '\\' && p[1] != '\\') {
        root = getenv("HULK_DATA_DIR");
        rest = p + 1;
    }
    if (!root || !*root)
        return 0;
    int n = snprintf(buf, size, "%s/%s", root, rest);
    if (n < 0 || (size_t)n >= size)
        return 0;
    for (char* c = buf; *c; c++)
        if (*c == '\\')
            *c = '/';
    return buf;
}

void* hulk_ncrt_fopen(const char* path, const char* mode) {
    char buf[1024];
    const char* host = hulk_ncrt_host_path(path, buf, sizeof(buf));
    return fopen(host ? host : path, mode);
}

int hulk_ncrt_fclose(void* f) {
    FILE* h = stream(f);
    return h == (FILE*)f ? fclose(h) : 0;
}

size_t hulk_ncrt_fread(void* p, size_t size, size_t n, void* f) { return fread(p, size, n, stream(f)); }
size_t hulk_ncrt_fwrite(const void* p, size_t size, size_t n, void* f) { return fwrite(p, size, n, stream(f)); }
int hulk_ncrt_getc(void* f) { return getc(stream(f)); }
int hulk_ncrt_ungetc(int c, void* f) { return ungetc(c, stream(f)); }
char* hulk_ncrt_fgets(char* s, int n, void* f) { return fgets(s, n, stream(f)); }
int hulk_ncrt_fputs(const char* s, void* f) { return fputs(s, stream(f)); }

// exit (0x003471a3): run the atexit table, then end the process (Lua's luaD_throw: exit(EXIT_FAILURE) when a
// script error has no handler)
void hulk_ncrt_exit(int code) {
    fprintf(stderr, "hulk: the game called exit(%d)\n", code);
    hulk_crt_run_atexit();
    exit(code);
}

int hulk_ncrt_fprintf(void* f, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vfprintf(stream(f), fmt, ap);
    va_end(ap);
    return r;
}

// The game's va_list is the MS one on every native target (the front end is the Windows triple's): a char* walking
// 8-byte slots. On arm64 macOS that is the host's va_list too; on ELF (AAPCS64, x86-64 System V) the host's is a
// struct, so the glue that takes a game va_list builds one whose register save areas count as used up, which makes
// the host read every argument from the game's slots (docs/native-android.md section 12, tests/android/va_host.cpp).
typedef char* hulk_ms_va_list;
#if defined(__aarch64__) && !defined(__APPLE__)
#define HULK_MS_VA(ap, ms)                                                                                      \
    va_list ap;                                                                                                  \
    do {                                                                                                         \
        struct Aapcs { void* stack; void* gr_top; void* vr_top; int gr_offs; int vr_offs; };                     \
        static_assert(sizeof(va_list) == sizeof(Aapcs), "AAPCS64 va_list");                                     \
        Aapcs a_ = {(void*)(ms), 0, 0, 0, 0}; /* offsets >= 0: registers used up, all from `stack` */            \
        memcpy(&ap, &a_, sizeof a_);                                                                             \
    } while (0)
#elif defined(__x86_64__)
#define HULK_MS_VA(ap, ms)                                                                                      \
    va_list ap;                                                                                                  \
    do {                                                                                                         \
        struct SysV { unsigned gp_offset, fp_offset; void* overflow; void* save; };                             \
        static_assert(sizeof(va_list) == sizeof(SysV), "System V va_list");                                     \
        SysV s_ = {48, 176, (void*)(ms), 0}; /* 6 GPRs * 8, + 8 XMM * 16: used up */                             \
        memcpy(&ap, &s_, sizeof s_);                                                                             \
    } while (0)
#else
#define HULK_MS_VA(ap, ms) va_list ap = (va_list)(ms)
#endif

// _vsnprintf / _snprintf: at most `count` characters; a NUL only if there is room for it; -1 when the output
// (without its NUL) did not fit
static int vsnprintf_ms(char* buf, size_t count, const char* fmt, va_list ap) {
    va_list ap2;
    va_copy(ap2, ap);
    int need = vsnprintf(0, 0, fmt, ap2);
    va_end(ap2);
    if (need < 0)
        return -1;
    if ((size_t)need < count)
        return vsnprintf(buf, count, fmt, ap);
    if (count) {
        char* tmp = (char*)malloc((size_t)need + 1);
        if (!tmp)
            return -1;
        vsnprintf(tmp, (size_t)need + 1, fmt, ap);
        memcpy(buf, tmp, count);
        free(tmp);
    }
    return (size_t)need == count ? need : -1;
}

// the game's _vsnprintf (0x00345774) and vsprintf: the va_list is the game's
int hulk_ncrt_vsnprintf_ms(char* buf, size_t count, const char* fmt, hulk_ms_va_list ms) {
    HULK_MS_VA(ap, ms);
    return vsnprintf_ms(buf, count, fmt, ap);
}

int hulk_ncrt_vsprintf_ms(char* buf, const char* fmt, hulk_ms_va_list ms) {
    HULK_MS_VA(ap, ms);
    return vsnprintf(buf, INT_MAX, fmt, ap);   // (vsprintf: unbounded; the host marks vsprintf deprecated)
}

int hulk_ncrt_snprintf_ms(char* buf, size_t count, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vsnprintf_ms(buf, count, fmt, ap);
    va_end(ap);
    return r;
}

// ---------------------------------------------------------------------------------------------------------------
// strings, numbers
char* hulk_ncrt_strlwr(char* s) {
    for (char* c = s; c && *c; c++)
        if (*c >= 'A' && *c <= 'Z')
            *c += 'a' - 'A';
    return s;
}

static thread_local char* t_strtok;   // (per thread, as the multithreaded CRT keeps it)
char* hulk_ncrt_strtok(char* s, const char* delim) { return strtok_r(s, delim, &t_strtok); }

// wcslen of the game's 16-bit wchar_t (the host's wchar_t is 32-bit)
size_t hulk_ncrt_wcslen16(const unsigned short* s) {
    size_t n = 0;
    while (s[n])
        n++;
    return n;
}

// `long` is 32 bits on the game side: the 32-bit results and overflow clamps
int hulk_ncrt_strtol(const char* s, char** end, int base) {
    long long v = strtoll(s, end, base);
    if (v > INT_MAX) {
        errno = ERANGE;
        return INT_MAX;
    }
    if (v < INT_MIN) {
        errno = ERANGE;
        return INT_MIN;
    }
    return (int)v;
}

unsigned hulk_ncrt_strtoul(const char* s, char** end, int base) {
    const char* p = s;
    while (isspace((unsigned char)*p))
        p++;
    int neg = *p == '-';
    unsigned long long v = strtoull(s, end, base);
    if (!neg && v > UINT_MAX) {
        errno = ERANGE;
        return UINT_MAX;
    }
    return (unsigned)v;   // (a negated value wraps, as strtoul specifies)
}

int hulk_ncrt_labs(int v) { return v < 0 ? -v : v; }

int hulk_ncrt_isnan(double x) { return isnan(x) ? 1 : 0; }

// _ftol: truncation toward zero to a 64-bit integer (the x86 helper returns edx:eax)
long long hulk_ncrt_ftol(double x) { return (long long)x; }

int* hulk_ncrt_errno(void) { return &errno; }

// rand / srand: the C runtime's linear congruential generator (x = x * 214013 + 2531011, bits 16..30), seeded 1 per
// thread: the game's random sequences, which the replay checkpoints hash, depend on it
static thread_local hulk_u32 t_rand = 1;
void hulk_ncrt_srand(unsigned seed) { t_rand = seed; }
int hulk_ncrt_rand(void) {
    t_rand = t_rand * 214013u + 2531011u;
    return (int)((t_rand >> 16) & 0x7fff);
}

// ---------------------------------------------------------------------------------------------------------------
// C++ runtime pieces that do not depend on the ABI decision
void hulk_ncrt_purecall(void) { hulk_native_missing("_purecall: a pure virtual function was called"); }
void hulk_ncrt_terminate(void) { hulk_native_missing("terminate"); }
void hulk_ncrt_CxxThrowException(void* object, void* info) {
    (void)object; (void)info;
    hulk_native_missing("_CxxThrowException: the game threw a C++ exception (no handler on the native builds)");
}

// ---------------------------------------------------------------------------------------------------------------
// setjmp / longjmp: the game's jmp_buf is 64 bytes (Lua's error chain, equivalent/0x002152f0: `__setjmp3(env, 0)`);
// the callee-saved state of AArch64 (21 registers) or x86-64 (8 words) is kept in a per-thread table keyed by the
// buffer's address, and the buffer holds a pointer to its entry. Two live buffers have two addresses, so live
// entries are never shared; the table (4096 entries) recycles the least recently used one when full.
struct JmpSlot {
    uintptr_t key;
    unsigned long long used;
    uintptr_t regs[22];
};
enum { JMP_SLOTS = 4096 };
static thread_local JmpSlot* t_jmp;
static thread_local unsigned long long t_jmp_clock;

// called by the assembly below with the buffer: the entry's register area; the buffer gets the entry's address
uintptr_t* hulk_ncrt_jmp_slot(void* buf) {
    if (!t_jmp)
        t_jmp = (JmpSlot*)calloc(JMP_SLOTS, sizeof(JmpSlot));
    uintptr_t key = (uintptr_t)buf;
    unsigned h = (unsigned)((key >> 4) * 2654435761u) % JMP_SLOTS;
    JmpSlot* best = 0;
    for (unsigned i = 0; i < 16; i++) {
        JmpSlot* s = &t_jmp[(h + i) % JMP_SLOTS];
        if (s->key == key || !s->key) {
            best = s;
            break;
        }
        if (!best || s->used < best->used)
            best = s;
    }
    best->key = key;
    best->used = ++t_jmp_clock;
    memcpy(buf, &best, sizeof(best));
    return best->regs;
}

int hulk_ncrt_setjmp3(void* buf, int count, ...);
void hulk_ncrt_longjmp(void* buf, int value) __attribute__((noreturn));
}  // extern "C"

#if defined(__APPLE__)
#define HULK_SYM(x) "_" #x
#else
#define HULK_SYM(x) #x
#endif

#if defined(__aarch64__)
// regs: x19..x28 (0-9), x29 (10), x30 (11), sp (12), d8..d15 (13-20)
__asm__(".text\n.p2align 2\n"
        ".globl " HULK_SYM(hulk_ncrt_setjmp3) "\n" HULK_SYM(hulk_ncrt_setjmp3) ":\n"
        "  stp x0, x30, [sp, #-16]!\n"
        "  bl " HULK_SYM(hulk_ncrt_jmp_slot) "\n"      // (preserves x19..x29, sp, d8..d15: what is saved next)
        "  ldp x1, x30, [sp], #16\n"
        "  stp x19, x20, [x0, #0]\n  stp x21, x22, [x0, #16]\n  stp x23, x24, [x0, #32]\n"
        "  stp x25, x26, [x0, #48]\n  stp x27, x28, [x0, #64]\n  stp x29, x30, [x0, #80]\n"
        "  mov x2, sp\n  str x2, [x0, #96]\n"
        "  stp d8, d9, [x0, #104]\n  stp d10, d11, [x0, #120]\n  stp d12, d13, [x0, #136]\n  stp d14, d15, [x0, #152]\n"
        "  mov w0, #0\n  ret\n"
        ".globl " HULK_SYM(hulk_ncrt_longjmp) "\n" HULK_SYM(hulk_ncrt_longjmp) ":\n"
        "  ldr x2, [x0]\n"                               // the entry the buffer points to
        "  add x2, x2, #16\n"                            // (its regs: after key and used)
        "  ldp x19, x20, [x2, #0]\n  ldp x21, x22, [x2, #16]\n  ldp x23, x24, [x2, #32]\n"
        "  ldp x25, x26, [x2, #48]\n  ldp x27, x28, [x2, #64]\n  ldp x29, x30, [x2, #80]\n"
        "  ldr x3, [x2, #96]\n  mov sp, x3\n"
        "  ldp d8, d9, [x2, #104]\n  ldp d10, d11, [x2, #120]\n  ldp d12, d13, [x2, #136]\n  ldp d14, d15, [x2, #152]\n"
        "  cmp w1, #0\n  csinc w0, w1, wzr, ne\n"         // longjmp(buf, 0) returns 1
        "  ret\n");
#elif defined(__x86_64__)
// regs: rbx, rbp, r12, r13, r14, r15, rsp (after the return), rip
__asm__(".text\n"
        ".globl " HULK_SYM(hulk_ncrt_setjmp3) "\n" HULK_SYM(hulk_ncrt_setjmp3) ":\n"
        "  pushq %rdi\n"
        "  call " HULK_SYM(hulk_ncrt_jmp_slot) "\n"
        "  popq %rdi\n"
        "  movq %rbx, 0(%rax)\n  movq %rbp, 8(%rax)\n  movq %r12, 16(%rax)\n  movq %r13, 24(%rax)\n"
        "  movq %r14, 32(%rax)\n  movq %r15, 40(%rax)\n"
        "  leaq 8(%rsp), %rcx\n  movq %rcx, 48(%rax)\n"
        "  movq (%rsp), %rcx\n  movq %rcx, 56(%rax)\n"
        "  xorl %eax, %eax\n  ret\n"
        ".globl " HULK_SYM(hulk_ncrt_longjmp) "\n" HULK_SYM(hulk_ncrt_longjmp) ":\n"
        "  movq (%rdi), %rax\n  addq $16, %rax\n"
        "  movq 0(%rax), %rbx\n  movq 8(%rax), %rbp\n  movq 16(%rax), %r12\n  movq 24(%rax), %r13\n"
        "  movq 32(%rax), %r14\n  movq 40(%rax), %r15\n  movq 48(%rax), %rsp\n  movq 56(%rax), %rcx\n"
        "  movl %esi, %eax\n  testl %eax, %eax\n  jnz 1f\n  incl %eax\n1:\n"
        "  jmpq *%rcx\n");
#else
#error "crt_posix.cpp: no setjmp for this architecture"
#endif

// ---------------------------------------------------------------------------------------------------------------
// Math: soft-intrinsics' x87 routines where they exist (what the original's fsin / fpatan / f2xm1 ... return), the
// host's libm otherwise. sqrt is exact everywhere.
extern "C" {
#if defined(HULK_NCRT_SOFT_X87)
#define HULK_M1(name) double hulk_ncrt_##name(double x) { return hulk_x87_##name(x); }
#define HULK_M2(name) double hulk_ncrt_##name(double y, double x) { return hulk_x87_##name(y, x); }
#else
#define HULK_M1(name) double hulk_ncrt_##name(double x) { return ::name(x); }
#define HULK_M2(name) double hulk_ncrt_##name(double y, double x) { return ::name(y, x); }
#endif
HULK_M1(sin) HULK_M1(cos) HULK_M1(tan) HULK_M1(asin) HULK_M1(acos) HULK_M1(atan) HULK_M1(exp) HULK_M1(log)
HULK_M1(log10) HULK_M2(atan2) HULK_M2(pow) HULK_M2(fmod)
double hulk_ncrt_sqrt(double x) { return sqrt(x); }
// the float variants: the double routine, rounded once
#define HULK_F1(name) float hulk_ncrt_##name##f(float x) { return (float)hulk_ncrt_##name((double)x); }
#define HULK_F2(name) float hulk_ncrt_##name##f(float y, float x) { return (float)hulk_ncrt_##name((double)y, (double)x); }
HULK_F1(sin) HULK_F1(cos) HULK_F1(tan) HULK_F1(asin) HULK_F1(acos) HULK_F1(atan) HULK_F1(exp) HULK_F1(log)
HULK_F2(atan2) HULK_F2(pow) HULK_F2(fmod)
int hulk_ncrt_soft_x87(void) {
#if defined(HULK_NCRT_SOFT_X87)
    return 1;
#else
    return 0;
#endif
}
}
#endif  // !_WIN32
