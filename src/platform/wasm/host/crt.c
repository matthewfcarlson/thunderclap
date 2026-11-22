/* The C library functions the game calls, by their addresses in the XBE's LIBCMT (which address is which function:
 * src/platform/sdl/crt/native_crt_table.h). Written from the C standard and MSVC's documented behaviour; the
 * formatter is adapted from the owner's fusion-frenzy port (port/host/crt.c). State the game observes (rand's seed,
 * strtok's position, errno, atexit's list) is in the sim block. */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "crt/hulk_qsort.h"
#include "hulk_host.h"
#include "sim.h"

typedef struct {
    va_list* va;            /* wasm variadic arguments, or */
    const uint32_t* slot;   /* x86 stack slots */
} ff_args;

/* ------------------------------------------------------------------------------------------- the formatter */
typedef struct {
    void* out;
    int wide, cap, n;
} sink;

static void put(sink* s, unsigned c) {
    if (s->cap < 0 || s->n < s->cap - 1) {
        if (s->wide) ((uint16_t*)s->out)[s->n] = (uint16_t)c;
        else ((char*)s->out)[s->n] = (char)c;
    }
    s->n++;
}

static uint32_t next32(ff_args* a) { return a->va ? va_arg(*a->va, uint32_t) : *a->slot++; }
static uint64_t next64(ff_args* a) {
    if (a->va) return va_arg(*a->va, uint64_t);
    uint64_t v = a->slot[0] | (uint64_t)a->slot[1] << 32;
    a->slot += 2;
    return v;
}
static double nextd(ff_args* a) {
    if (a->va) return va_arg(*a->va, double);
    double d;
    memcpy(&d, a->slot, 8);
    a->slot += 2;
    return d;
}

static unsigned fch(const void* f, int wide, int i) {
    return wide ? ((const uint16_t*)f)[i] : ((const unsigned char*)f)[i];
}

static void pad(sink* s, int n, unsigned c) {
    while (n-- > 0) put(s, c);
}

static int ff_format(void* out, int wide, int cap, const void* fmt, ff_args* a) {
    sink s = {out, wide, cap, 0};
    for (int i = 0; fch(fmt, wide, i); i++) {
        unsigned c = fch(fmt, wide, i);
        if (c != '%') { put(&s, c); continue; }
        char spec[32] = "%";
        int k = 1, left = 0, zero = 0, width = -1, prec = -1;
        for (;; i++) {
            c = fch(fmt, wide, i + 1);
            if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0') {
                if (c == '-') left = 1;
                if (c == '0') zero = 1;
                if (k < 8) spec[k++] = (char)c;
            } else break;
        }
        if (fch(fmt, wide, i + 1) == '*') { width = (int)next32(a); i++; }
        else for (width = 0; isdigit(fch(fmt, wide, i + 1)); i++) width = width * 10 + fch(fmt, wide, i + 1) - '0';
        if (width < 0) { left = 1; width = -width; }
        if (fch(fmt, wide, i + 1) == '.') {
            i++;
            if (fch(fmt, wide, i + 1) == '*') { prec = (int)next32(a); i++; }
            else for (prec = 0; isdigit(fch(fmt, wide, i + 1)); i++) prec = prec * 10 + fch(fmt, wide, i + 1) - '0';
        }
        int size = 0;          /* 'h' narrow, 'l' wide/long, 'q' 64-bit */
        for (;;) {
            c = fch(fmt, wide, i + 1);
            if (c == 'h') { size = 'h'; i++; }
            else if (c == 'l') { size = size == 'l' ? 'q' : 'l'; i++; }
            else if (c == 'w') { size = 'l'; i++; }
            else if (c == 'L') { i++; }
            else if (c == 'I' && fch(fmt, wide, i + 2) == '6' && fch(fmt, wide, i + 3) == '4') { size = 'q'; i += 3; }
            else if (c == 'I' && fch(fmt, wide, i + 2) == '3' && fch(fmt, wide, i + 3) == '2') { i += 3; }
            else break;
        }
        c = fch(fmt, wide, ++i);
        if (!c) break;
        char tmp[512];
        int len;
        switch (c) {
        case '%':
            put(&s, '%');
            continue;
        case 'c': case 'C': {
            unsigned ch = next32(a);
            int w = c == 'C' ? !wide : wide;
            if (size == 'h') w = 0;
            if (size == 'l') w = 1;
            ch = w ? ch & 0xffff : ch & 0xff;
            if (!left) pad(&s, width - 1, ' ');
            put(&s, ch);
            if (left) pad(&s, width - 1, ' ');
            continue;
        }
        case 's': case 'S': {
            uint32_t p = next32(a);
            int w = c == 'S' ? !wide : wide;
            if (size == 'h') w = 0;
            if (size == 'l') w = 1;
            static const char null_s[] = "(null)";
            const void* str = p ? PTR(p) : (const void*)null_s;
            if (!p) w = 0;
            int n = 0;
            while ((prec < 0 || n < prec) && fch(str, w, n)) n++;
            if (!left) pad(&s, width - n, ' ');
            for (int j = 0; j < n; j++) put(&s, fch(str, w, j));
            if (left) pad(&s, width - n, ' ');
            continue;
        }
        case 'd': case 'i': case 'u': case 'x': case 'X': case 'o': case 'p': {
            long long v;
            if (c == 'p') { v = next32(a); size = 0; }
            else if (size == 'q') v = (long long)next64(a);
            else {
                uint32_t u = next32(a);
                if (size == 'h') u = (c == 'd' || c == 'i') ? (uint32_t)(int16_t)u : u & 0xffff;
                v = (c == 'd' || c == 'i') ? (long long)(int32_t)u : (long long)u;
            }
            if (c == 'p') { width = 8; prec = -1; spec[1] = 0; k = 1; zero = 1; c = 'X'; spec[k++] = '0'; }
            if (width >= 0 && k < 20) k += snprintf(spec + k, sizeof spec - k, "%d", width);
            if (prec >= 0 && k < 20) k += snprintf(spec + k, sizeof spec - k, ".%d", prec);
            spec[k++] = 'l'; spec[k++] = 'l'; spec[k++] = (char)c; spec[k] = 0;
            len = snprintf(tmp, sizeof tmp, spec, v);
            break;
        }
        case 'f': case 'e': case 'E': case 'g': case 'G': {
            double d = nextd(a);
            if (width >= 0 && k < 20) k += snprintf(spec + k, sizeof spec - k, "%d", width);
            if (prec >= 0 && k < 20) k += snprintf(spec + k, sizeof spec - k, ".%d", prec);
            spec[k++] = (char)c; spec[k] = 0;
            len = snprintf(tmp, sizeof tmp, spec, d);
            break;
        }
        case 'n':
            *(int*)PTR(next32(a)) = s.n;
            continue;
        default:
            put(&s, '%');
            put(&s, c);
            continue;
        }
        (void)zero;
        if (len > (int)sizeof tmp - 1) len = sizeof tmp - 1;
        for (int j = 0; j < len; j++) put(&s, (unsigned char)tmp[j]);
    }
    if (s.cap != 0) {
        int at = s.cap < 0 || s.n < s.cap ? s.n : s.cap - 1;
        if (wide) ((uint16_t*)out)[at] = 0;
        else ((char*)out)[at] = 0;
    }
    return s.n;
}



/* printf family. Game code passes variadic arguments as x86 stack words (tools/wasm_port.py: callers lay them out so,
 * and the game's own variadic functions walk them x86-style), so a va_list is a pointer to x86 slots: called variadic
 * (ff_<addr>(...)) the slots are wasm's variadic area; packed (FFG), the stack words after the fixed ones. */
static const uint32_t* slots(va_list ap) {
    const uint32_t* p;
    memcpy(&p, &ap, sizeof p);
    return p;
}
#define SPRINTF(addr)                                                                                     \
    int ff_##addr(char* buf, const char* fmt, ...) {                                                      \
        va_list ap;                                                                                       \
        va_start(ap, fmt);                                                                                \
        ff_args a = {0, slots(ap)};                                                                       \
        int n = ff_format(buf, 0, -1, fmt, &a);                                                           \
        va_end(ap);                                                                                       \
        return n;                                                                                         \
    }                                                                                                     \
    FFG(addr) { UNUSED; ff_args a = {0, &ARG(2)}; RET(ff_format(PTR(ARG(0)), 0, -1, PTR(ARG(1)), &a)); }
SPRINTF(00344f75)       /* sprintf */
SPRINTF(00356734)       /* sprintf (XAPI's copy) */

/* _vsnprintf (0x345774): -1 when the output doesn't fit; the list is x86 slots */
FFG(00345774) {
    UNUSED;
    int cap = (int)ARG(1);
    ff_args a = {0, PTR(ARG(3))};
    int n = ff_format(PTR(ARG(0)), 0, cap, PTR(ARG(2)), &a);
    RET(n >= cap ? -1 : n);
}

/* fprintf (0x347792): to the host's stderr when the stream is one of the C library's (the game logs) */
static void fprintf_out(uint32_t fp, const char* fmt, const uint32_t* sl) {
    char buf[4096];
    ff_args a = {0, sl};
    ff_format(buf, 0, sizeof buf, fmt, &a);
    (void)fp;
    if (getenv("HULK_LOG")) fputs(buf, stderr);
}
int ff_00347792(uint32_t fp, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    fprintf_out(fp, fmt, slots(ap));
    va_end(ap);
    return 0;
}
FFG(00347792) { UNUSED; fprintf_out(ARG(0), PTR(ARG(1)), &ARG(2)); RET(0); }

/* sscanf (0x345804): every scanned argument is a pointer, one slot each */
static int scan(const char* buf, const char* fmt, const uint32_t* p) {
    return sscanf(buf, fmt, PTR(p[0]), PTR(p[1]), PTR(p[2]), PTR(p[3]), PTR(p[4]), PTR(p[5]), PTR(p[6]), PTR(p[7]),
                  PTR(p[8]), PTR(p[9]), PTR(p[10]), PTR(p[11]), PTR(p[12]), PTR(p[13]), PTR(p[14]), PTR(p[15]));
}
int ff_00345804(const char* buf, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    uint32_t p[16] = {0};
    memcpy(p, slots(ap), sizeof p);     /* (reads past the arguments the call has: unused) */
    va_end(ap);
    return scan(buf, fmt, p);
}
FFG(00345804) { UNUSED; RET(scan(PTR(ARG(0)), PTR(ARG(1)), &ARG(2))); }

/* ------------------------------------------------------------------------------------------- start-up, memory */
/* atexit (0x34511c): the list is in the sim block; the host runs it at exit */
FFG(0034511c) {
    UNUSED;
    if (SIM->natexit >= sizeof SIM->atexit / sizeof SIM->atexit[0]) { RET(-1); return; }
    SIM->atexit[SIM->natexit++] = ARG(0);
    RET(0);
}
void ff_run_atexit(void) {
    while (SIM->natexit) ff_call(SIM->atexit[--SIM->natexit], 0);
}
FFG(0034502e) { UNUSED; }                                                       /* __security_check_cookie */
FFG(003471a3) { UNUSED; ff_run_atexit(); exit((int)ARG(0)); }                   /* exit */
FFG(003479aa) { UNUSED; RET((uintptr_t)ff_arena_alloc(ARG(0), 16)); }           /* malloc (the game arena) */
FFG(003479bc) { UNUSED; ff_arena_free(PTR(ARG(0))); }                           /* free */
FFG(00347d7a) { UNUSED; RET((uintptr_t)ff_arena_realloc(PTR(ARG(0)), ARG(1))); }    /* realloc */
FFG(00347aa0) { UNUSED; RET((uintptr_t)ff_arena_alloc(ARG(0) * ARG(1), 16)); }  /* calloc */
FFG(00347ba4) { UNUSED; RET((uintptr_t)&SIM->crt_errno); }                       /* _errno */
FFG(00347b53) { UNUSED; RET((uintptr_t)"error"); }                              /* strerror */

/* setjmp/longjmp: sched.c (continuations on the fibers' Asyncify machinery) */

/* ------------------------------------------------------------------------------------------- strings, ctype */
static int lower(int c) { return c >= 'A' && c <= 'Z' ? c + 32 : c; }
static int upper(int c) { return c >= 'a' && c <= 'z' ? c - 32 : c; }
FFG(00346fc5) {                                                                 /* _stricmp */
    UNUSED;
    const unsigned char *a = PTR(ARG(0)), *b = PTR(ARG(1));
    int d;
    while ((d = lower(*a) - lower(*b)) == 0 && *a) a++, b++;
    RET(d);
}
FFG(00345840) { UNUSED; RET(strncmp(PTR(ARG(0)), PTR(ARG(1)), ARG(2))); }
FFG(003473c6) { UNUSED; RET(strcmp(PTR(ARG(0)), PTR(ARG(1)))); }
FFG(00345650) { UNUSED; RET((uintptr_t)strncpy(PTR(ARG(0)), PTR(ARG(1)), ARG(2))); }
FFG(003468c0) { UNUSED; RET((uintptr_t)strncat(PTR(ARG(0)), PTR(ARG(1)), ARG(2))); }
FFG(00346890) { UNUSED; RET((uintptr_t)strrchr(PTR(ARG(0)), (int)ARG(1))); }
FFG(00345db0) { UNUSED; RET((uintptr_t)strchr(PTR(ARG(0)), (int)ARG(1))); }
FFG(00345e70) { UNUSED; RET((uintptr_t)strstr(PTR(ARG(0)), PTR(ARG(1)))); }
FFG(00348340) { UNUSED; RET((uintptr_t)strpbrk(PTR(ARG(0)), PTR(ARG(1)))); }
FFG(00347380) { UNUSED; RET(strcspn(PTR(ARG(0)), PTR(ARG(1)))); }
FFG(00348290) { UNUSED; RET((uintptr_t)memchr(PTR(ARG(0)), (int)ARG(1), ARG(2))); }
FFG(00345130) { UNUSED; RET((uintptr_t)memmove(PTR(ARG(0)), PTR(ARG(1)), ARG(2))); }       /* memmove */
FFG(003465c6) {                                     /* strtok: its position is in the sim block */
    UNUSED;
    char* s = ARG(0) ? PTR(ARG(0)) : PTR(SIM->strtok_next);
    const char* delim = PTR(ARG(1));
    if (!s) { RET(0); return; }
    s += strspn(s, delim);
    if (!*s) { SIM->strtok_next = 0; RET(0); return; }
    char* e = s + strcspn(s, delim);
    if (*e) {
        *e = 0;
        SIM->strtok_next = (uint32_t)(uintptr_t)(e + 1);
    } else
        SIM->strtok_next = 0;
    RET((uintptr_t)s);
}
FFG(00348380) {                                                                 /* _strlwr */
    UNUSED;
    for (char* p = PTR(ARG(0)); *p; p++) *p = (char)lower((unsigned char)*p);
    RET(ARG(0));
}
FFG(003454fe) { UNUSED; RET(atol(PTR(ARG(0)))); }                               /* atol */
FFG(003458c1) { UNUSED; RETF(strtod(PTR(ARG(0)), NULL)); }                       /* atof */
FFG(003472cb) {                                                                 /* strtod */
    UNUSED;
    char* end;
    double d = strtod(PTR(ARG(0)), &end);
    if (ARG(1)) *(uint32_t*)PTR(ARG(1)) = (uint32_t)(uintptr_t)end;
    RETF(d);
}
FFG(00345d81) {                                                                 /* strtoul */
    UNUSED;
    char* end;
    unsigned long v = strtoul(PTR(ARG(0)), &end, (int)ARG(2));
    if (ARG(1)) *(uint32_t*)PTR(ARG(1)) = (uint32_t)(uintptr_t)end;
    RET((uint32_t)v);
}
/* ctype in the "C" locale (MSVC's tables for 0..127; nothing above) */
#define CT(addr, fn) FFG(addr) { UNUSED; int c = (int)ARG(0); RET(c >= 0 && c < 128 ? fn(c) != 0 : 0); }
CT(0034591d, isalpha)
CT(0034594b, isupper)
CT(00345974, islower)
CT(0034599d, isdigit)
CT(003459c6, isxdigit)
CT(003459f4, isspace)
CT(00345a1d, ispunct)
CT(00345a46, isalnum)
CT(00345ad0, iscntrl)
FFG(00345475) { UNUSED; RET(lower((int)ARG(0))); }                              /* tolower */
FFG(00345b90) { UNUSED; RET(upper((int)ARG(0))); }                              /* toupper */

/* qsort / bsearch: the comparison is a game function (cdecl, two pointers). qsort is crt/hulk_qsort.h, which orders
 * equal elements as the Xbox CRT does (the game's comparators may never return 0: ItemQueue's 0x001cb3a0) */
static uint32_t cmp_fn;
static int gcmp(const void* a, const void* b) {
    return (int)ff_call(cmp_fn, 2, (uint32_t)(uintptr_t)a, (uint32_t)(uintptr_t)b);
}
FFG(00345f90) {
    UNUSED;
    uint32_t saved = cmp_fn;
    cmp_fn = ARG(3);
    hulk_qsort(PTR(ARG(0)), ARG(1), ARG(2), gcmp);
    cmp_fn = saved;
}
FFG(00347a14) {
    UNUSED;
    uint32_t saved = cmp_fn;
    cmp_fn = ARG(4);
    RET((uintptr_t)bsearch(PTR(ARG(0)), PTR(ARG(1)), ARG(2), ARG(3), gcmp));
    cmp_fn = saved;
}

/* ------------------------------------------------------------------------------------------- math */
FFG(0034557c) { UNUSED; RETF(floor(ARGD(0))); }
FFG(003481ba) { UNUSED; RETF(ceil(ARGD(0))); }
FFG(0034476f) { UNUSED; RET(isnan(ARGD(0)) != 0); }                             /* _isnan */
FFG(00347f64) {                                                                 /* frexp */
    UNUSED;
    int e;
    double m = frexp(ARGD(0), &e);
    *(int*)PTR(ARG(2)) = e;
    RETF(m);
}
FFG(00348010) { UNUSED; RETF(ldexp(ARGD(0), (int)ARG(2))); }
FFG(0034773f) { UNUSED; SIM->rand_seed = ARG(0); }                              /* srand */
FFG(0034774c) {                                                                 /* rand: MSVC's LCG */
    UNUSED;
    SIM->rand_seed = SIM->rand_seed * 0x343fd + 0x269ec3;
    RET((SIM->rand_seed >> 16) & 0x7fff);
}
