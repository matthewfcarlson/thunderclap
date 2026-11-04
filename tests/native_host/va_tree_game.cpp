// va1 (docs/native-build.md "Varargs"): the game side of the varargs test. The real sources (the x86-style va_list
// producers and the slot-walking consumers, listed in tests/native_host/va_tree_test.sh) are compiled one TU each
// the way the tree compiles them for a 64-bit target (MS-ABI front end, then the target's retarget); this TU is
// compiled the same way and supplies what they call (a small vsnprintf over the game's va_list, a Lua stack for
// Lua's pushvfstring, recording stubs) and the callers: game -> game variadic calls with ints, doubles, chars,
// strings and wide strings, in and past the argument registers. Host side: tests/native_host/va_tree_test.cpp.
#include "compat/ptr.h"

extern "C" void* __cdecl malloc(unsigned long long);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned long long);

// ------------------------------------------------------------------------------------- a small vsnprintf
// %d %u %x %s %c %f (3 decimals) %%, over the game's va_list (a char* over 8-byte slots on the MS 64-bit targets).
static int put(char* b, unsigned n, unsigned* k, char c) {
    if (*k + 1 < n) b[*k] = c;
    (*k)++;
    return 0;
}
static void put_u(char* b, unsigned n, unsigned* k, unsigned long long v, unsigned base) {
    char t[24];
    int i = 0;
    do { t[i++] = "0123456789abcdef"[v % base]; v /= base; } while (v);
    while (i) put(b, n, k, t[--i]);
}
static int fmt_impl(char* b, unsigned n, const char* f, char* ap) {
    unsigned k = 0;
    for (; *f; f++) {
        if (*f != '%') { put(b, n, &k, *f); continue; }
        f++;
        if (*f == 'd') {
            int v = __builtin_va_arg(ap, int);
            if (v < 0) { put(b, n, &k, '-'); v = -v; }
            put_u(b, n, &k, (unsigned)v, 10);
        } else if (*f == 'u') {
            put_u(b, n, &k, __builtin_va_arg(ap, unsigned), 10);
        } else if (*f == 'x') {
            put_u(b, n, &k, __builtin_va_arg(ap, unsigned), 16);
        } else if (*f == 's') {
            for (const char* s = __builtin_va_arg(ap, const char*); *s; s++) put(b, n, &k, *s);
        } else if (*f == 'c') {
            put(b, n, &k, (char)__builtin_va_arg(ap, int));
        } else if (*f == 'f') {
            double d = __builtin_va_arg(ap, double);
            if (d < 0) { put(b, n, &k, '-'); d = -d; }
            unsigned long long m = (unsigned long long)(d * 1000.0 + 0.5);
            put_u(b, n, &k, m / 1000, 10);
            put(b, n, &k, '.');
            put(b, n, &k, (char)('0' + m / 100 % 10));
            put(b, n, &k, (char)('0' + m / 10 % 10));
            put(b, n, &k, (char)('0' + m % 10));
        } else {
            put(b, n, &k, *f);
        }
    }
    if (n) b[k < n ? k : n - 1] = 0;
    return (int)k;
}

// the names the sources declare for it (each source's own spelling)
extern "C" int __cdecl _vsnprintf(char* b, unsigned n, const char* f, char* ap) { return fmt_impl(b, n, f, ap); }   // 0x00246f50, 0x00267730
extern "C" int __cdecl __vsnprintf(char* b, unsigned n, const char* f, char* ap) { return fmt_impl(b, n, f, ap); }  // 0x00267760
int __cdecl __vsnprintf(char* b, int n, const char* f, void* ap) { return fmt_impl(b, (unsigned)n, f, (char*)ap); } // 0x000964a0
int Fmt(char* b, int n, const char* f, char* ap) { return fmt_impl(b, (unsigned)n, f, ap); }                        // 0x0023fde0
int vfmt(char* b, int n, const char* f, char* ap) { return fmt_impl(b, (unsigned)n, f, ap); }                       // 0x00245b00
extern "C" int __cdecl FUN_00267730(char*, unsigned, const char*, char*);                                          // real source
extern "C" void __cdecl CopyLike(char* b, unsigned n, hulk_uintptr f, void* ap) {                                   // 0x0023fef0
    FUN_00267730(b, n, (const char*)f, (char*)ap);
}

static char g_out[1024];   // what the last sink received
static void keep(const char* s) {
    int i = 0;
    for (; s[i] && i < 1023; i++) g_out[i] = s[i];
    g_out[i] = 0;
}

// ------------------------------------------------------------------------------------- the producers' callees
extern "C" void __cdecl FUN_0023fa40(int* out, char* buf, unsigned n, int) { keep(buf); *out = (int)n; }          // 0x0023fde0
struct Ctx;
bool F2(Ctx* c, const char* s, ...) {                                                                                // 0x00245b00
    __builtin_va_list ap;
    __builtin_va_start(ap, s);
    char t[256];
    fmt_impl(t, 256, s, ap);
    int i = 0;
    while (g_out[i]) i++;
    for (int j = 0; t[j] && i < 1023; j++) g_out[i++] = t[j];
    g_out[i] = 0;
    return true;
}
struct Reader {                                                                                                      // 0x00232cc0
    virtual void v0() {} virtual void v1() {} virtual void v2() {} virtual void v3() {} virtual void v4() {}
    virtual void v5() {} virtual void v6() {} virtual void v7() {} virtual void v8() {} virtual void v9() {}
    virtual void v10() {} virtual void v11() {} virtual void v12() {} virtual void v13() {} virtual void v14() {}
    virtual void v15() {} virtual void v16() {} virtual void v17() {}
    virtual const char* filename() { return "fight.txt"; }
    virtual int line() { return 42; }
};
static void __cdecl reader_sink(const char* s, Reader*, void*) { keep(s); }
void (__cdecl *DAT_004e5bb0)(const char*, Reader*, void*) = reader_sink;
void* DAT_004e5bb4;
#include "gen/owners.h"
owners::String_23fe50* owners::String_23fe50::FUN_0023fe50(const char* s) { keep(s); return this; }              // 0x0023fef0
// 0x000fc020 declares the wide formatter with its own types; the tree's link binds that name to FUN_000fbc00
extern "C" hulk_intptr FUN_000fbc00(unsigned short* buf, unsigned count, const char* fmt, char* ap);
void FUN_000fbc00(hulk_uintptr a, unsigned b, hulk_uintptr c, unsigned* d) {
    ::FUN_000fbc00((unsigned short*)a, b, (const char*)c, (char*)d);
}
// 0x00338e20's callees: F2 is 0x00213440 (the real source, C name)
extern "C" void __cdecl FUN_00213440(void* self, hulk_intptr x, hulk_intptr y);
static int g_f1, g_f3;
void __cdecl F1(hulk_uintptr, int v) { g_f1 = v; }
void __cdecl F2(hulk_uintptr a, hulk_uintptr b, unsigned* va) { FUN_00213440((void*)a, (hulk_intptr)b, (hulk_intptr)va); }
void __cdecl F3(hulk_uintptr, int v) { g_f3 = v; }
int __cdecl F4(hulk_uintptr) { return 77; }
class Obj_213440;
class Obj_213470;
void __cdecl helper1(Obj_213440*) {}
void helper1(Obj_213470*) {}
extern "C" void __cdecl FUN_00214900(int, int) {}                                                                  // 0x00214a90
extern "C" void __cdecl FUN_002149b0(void*) {}
void __cdecl FUN_002152b0(const char*, int) {}                                                                      // 0x0021f800

// ------------------------------------------------------------------------------------- a Lua stack (0x002160c0's view)
struct TString_2160c0 { char hdr[0x10]; char str[1]; };
struct TValue_2160c0 { int tt; union { TString_2160c0* ts; float n; } value; };
struct lua_State_2160c0 { char pad0[8]; TValue_2160c0* top; TValue_2160c0* base; char pad10[8]; TValue_2160c0* stack_last; };
static char g_lua[1024];   // the last concatenation (pushvfstring's result)
TString_2160c0* __cdecl FUN_00219430(lua_State_2160c0*, const char* s, unsigned int len) {
    TString_2160c0* t = (TString_2160c0*)malloc(sizeof(TString_2160c0) + len);
    memcpy(t->str, s, len);
    t->str[len] = 0;
    return t;
}
extern "C" void __cdecl FUN_00216060(void* L_, const char* s) {
    lua_State_2160c0* L = (lua_State_2160c0*)L_;
    unsigned n = 0;
    while (s[n]) n++;
    L->top->value.ts = FUN_00219430(L, s, n);
    L->top->tt = 4;
    L->top++;
}
extern "C" void __cdecl FUN_00215460(void*, int) {}
extern "C" void __cdecl FUN_00217f20(void* L_, int total, int last) {   // luaV_concat: numbers as integers or %f
    lua_State_2160c0* L = (lua_State_2160c0*)L_;
    char t[1024];
    unsigned k = 0;
    for (int i = last - total + 1; i <= last; i++) {
        TValue_2160c0* o = L->base + i;
        if (o->tt == 4) {
            for (const char* s = o->value.ts->str; *s; s++) put(t, 1024, &k, *s);
        } else {
            double d = o->value.n;
            if (d == (double)(long long)d) {
                long long v = (long long)d;
                if (v < 0) { put(t, 1024, &k, '-'); v = -v; }
                put_u(t, 1024, &k, (unsigned long long)v, 10);
            } else {
                unsigned long long m = (unsigned long long)((d < 0 ? -d : d) * 1000.0 + 0.5);
                if (d < 0) put(t, 1024, &k, '-');
                put_u(t, 1024, &k, m / 1000, 10);
                put(t, 1024, &k, '.');
                put(t, 1024, &k, (char)('0' + m / 100 % 10));
                put(t, 1024, &k, (char)('0' + m / 10 % 10));
                put(t, 1024, &k, (char)('0' + m % 10));
            }
        }
    }
    t[k < 1024 ? k : 1023] = 0;
    for (unsigned i = 0; i <= k && i < 1024; i++) g_lua[i] = t[i];
    TValue_2160c0* r = L->base + (last - total + 1);
    r->value.ts = FUN_00219430(L, t, k);
    r->tt = 4;
}
static lua_State_2160c0* new_lua() {
    lua_State_2160c0* L = (lua_State_2160c0*)malloc(0x100);
    TValue_2160c0* st = (TValue_2160c0*)malloc(sizeof(TValue_2160c0) * 64);
    L->top = L->base = st;
    L->stack_last = st + 60;
    return L;
}

// ------------------------------------------------------------------------------------- the single-slot keys
static const char* g_key;
extern "C" void* __cdecl FUN_0025f670(void*, const char** key) { g_key = *key; return (void*)1; }                  // 0x0025fad0
extern "C" bool __cdecl FUN_0025f450(void*, void*, const char** key) { g_key = *key; return true; }               // 0x0025fba0
extern "C" char DAT_00429420[16];
char DAT_00429420[16];
struct Node { char pad[0x14]; char item[0x1c]; Node* next; void FUN_0025fad0(hulk_intptr value); };
struct MetaTypeAttribBase { void* vptr; char pad[0x10]; unsigned a; unsigned b; MetaTypeAttribBase* init(void*, hulk_uintptr, hulk_uintptr); };

// ------------------------------------------------------------------------------------- the producers, as callers see them
void FUN_000964a0(char* buffer, int size, const char* format, ...);
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format, ...);
struct Out_23fde0 { int p; unsigned short flag; unsigned short pad; unsigned short len; };
Out_23fde0* Fn(Out_23fde0* out, int x, const char* fmt, ...);
struct Parser_245b00 { char pad[0x90]; int line; };
bool Err(Parser_245b00* p, Ctx* c, const char* fmt, ...);
struct Writer { int unused; int (__cdecl* write)(Writer*, const char*, int); };
int __cdecl FUN_00246f50(Writer* w, const char* fmt, ...);
void __cdecl FUN_00232cc0(Reader* reader, const char* format, ...);
extern "C" void FUN_000fc020(hulk_uintptr a, unsigned b, hulk_uintptr c, ...);
hulk_intptr FUN_000fbe00(unsigned short* buf, unsigned int count, const unsigned short* fmt, char* ap);
int __cdecl FUN_00216320(hulk_uintptr a, hulk_uintptr b, ...);
void __cdecl FUN_00214a90(hulk_intptr first, hulk_intptr second, ...);
extern "C" int FUN_00213470(Obj_213470* self, hulk_intptr arg, ...);
int __cdecl target(hulk_uintptr a, hulk_uintptr b, ...);   // 0x00338e20
struct LogContext { const char* name; char padding[12]; const char* message; };
void __cdecl FUN_0021f800(LogContext* context, const char* format, ...);
class Obj_23fef0 { public: };
Obj_23fef0* __cdecl Target(Obj_23fef0* a, hulk_uintptr b, ...);

// ------------------------------------------------------------------------------------- the cases
static int g_fail;
static char* g_rep;
static unsigned g_rk;
static void report(const char* name, const char* got, const char* want) {
    int ok = 1;
    for (int i = 0;; i++) {
        if (got[i] != want[i]) { ok = 0; break; }
        if (!got[i]) break;
    }
    if (!ok) g_fail++;
    const char* parts[] = {ok ? "ok   " : "FAIL ", name, ": '", got, "'", ok ? "" : " want '", ok ? "" : want, ok ? "" : "'", "\n"};
    for (unsigned i = 0; i < sizeof parts / sizeof parts[0]; i++)
        for (const char* s = parts[i]; *s; s++) put(g_rep, 8192, &g_rk, *s);
}
static int __cdecl writer_cb(Writer*, const char* s, int) { keep(s); return 1; }
static hulk_intptr wfmt(unsigned short* buf, unsigned n, const unsigned short* fmt, ...) {   // a game va_list into 0x000fbe00
    __builtin_va_list ap;
    __builtin_va_start(ap, fmt);
    return FUN_000fbe00(buf, n, fmt, ap);
}
static void narrow(const unsigned short* w, char* out) { int i = 0; for (; w[i]; i++) out[i] = (char)w[i]; out[i] = 0; }

extern "C" int __cdecl va_tree_run(char* rep) {
    g_rep = rep; g_rk = 0; g_fail = 0;
    char b[256];
    // `...` definitions, (char*)&fmt + 4
    FUN_000964a0(b, 256, "%d-%d|%s|%f|%c", 11, 22, "xy", 2.5, 'Q');
    report("0x000964a0 mixed", b, "11-22|xy|2.500|Q");
    FUN_000964a0(b, 256, "%d %d %d %d %d %d %d %d %d %d %f %f", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0.5, -1.25);
    report("0x000964a0 12 args", b, "1 2 3 4 5 6 7 8 9 10 0.500 -1.250");
    Out_23fde0 o;
    Fn(&o, 0, "%s:%u:%x", "fn", 7u, 255u);
    report("0x0023fde0 Fn", g_out, "fn:7:ff");
    Parser_245b00 p;
    p.line = 12;
    g_out[0] = 0;
    Err(&p, 0, "bad %s %d", "token", 3);
    report("0x00245b00 Err (+ F2)", g_out, "bad token 3\nError Line: [12]\n");
    Writer w;
    w.write = writer_cb;
    FUN_00246f50(&w, "%f/%d/%s", 0.125, -4, "w");
    report("0x00246f50 writer", g_out, "0.125/-4/w");
    // a named-parameter fake (format, then `(char*)&format + 4`)
    FUN_00267760(b, 256, "%s=%d %f %c", "k", -7, 0.25, 'z');
    report("0x00267760 fake +4", b, "k=-7 0.250 z");
    // &format + 1, through FUN_00267730 and a game -> game call of 0x00267760
    Reader r;
    FUN_00232cc0(&r, "x%dy%f", 5, 1.5);
    report("0x00232cc0 reader", g_out, "fight::Reader ERROR\nfight.txt(42):  x5y1.500\n");
    // `&c` (the first variadic argument a named parameter on the 32-bit build)
    Obj_23fef0 t;
    Target(&t, (hulk_uintptr)"%s|%d|%f", "tg", 64, 3.0);
    report("0x0023fef0 Target", g_out, "tg|64|3.000");
    // the wide formatter: (&c) + 1 into the 4-byte slot walk of 0x000fbc00
    unsigned short wb[64];
    char nb[64];
    static const unsigned short wide[] = {'w', 'i', 0};
    FUN_000fc020((hulk_uintptr)wb, 64, (hulk_uintptr)"%s,%u,%c,%S", "ab", 123u, 'C', wide);
    narrow(wb, nb);
    report("0x000fc020 -> 0x000fbc00", nb, "ab,123,C,wi");
    static const unsigned short wf[] = {'%', 'u', '+', '%', 's', '+', '%', 'S', 0};
    wfmt(wb, 64, wf, 9u, "nar", wide);
    narrow(wb, nb);
    report("0x000fbe00 wide fmt", nb, "9+nar+wi");
    // Lua's pushvfstring (0x002160c0) through its producers
    lua_State_2160c0* L = new_lua();
    FUN_00216320((hulk_uintptr)L, (hulk_uintptr)"a%sb%dc%fd%ce%%", "S", 31, 0.75, 'k');
    report("0x00216320 -> 0x002160c0", g_lua, "aSb31c0.750dke%");
    L = new_lua();
    FUN_00214a90((hulk_intptr)L, (hulk_intptr)"err %s at %d", "x.lua", 8);
    report("0x00214a90 -> 0x002160c0", g_lua, "err x.lua at 8");
    // 0x00213470: Obj_213470 is the Lua state here (its own view puts p where the 64-bit lua_State keeps base)
    L = new_lua();
    FUN_00213470((Obj_213470*)L, (hulk_intptr)"%d+%f", 2, 0.5);
    report("0x00213470 -> 0x002160c0", g_lua, "2+0.500");
    L = new_lua();
    int rt = target((hulk_uintptr)L, (hulk_uintptr)"%s#%d", "tgt", -9);
    report("0x00338e20 -> 0x00213440 -> 0x002160c0", g_lua, "tgt#-9");
    if (rt != 77 || g_f1 != 1 || g_f3 != 2) report("0x00338e20 F1/F3/F4", "wrong", "right");
    L = new_lua();
    LogContext lc;
    lc.name = (const char*)L;
    lc.message = "ctx";
    FUN_0021f800(&lc, "m=%d", 6);
    report("0x0021f800 -> 0x002160c0, 0x00216320", g_lua, "ctx: m=6");
    // single-slot keys (pointer-sized parameters)
    Node n;
    n.next = 0;
    g_key = 0;
    n.FUN_0025fad0((hulk_intptr)"needle");
    report("0x0025fad0 key", g_key ? g_key : "(null)", "needle");
    MetaTypeAttribBase m;
    g_key = 0;
    m.init(&m, (hulk_uintptr)"attr", 4);
    report("0x0025fba0 key", g_key ? g_key : "(null)", "attr");
    if (g_rk < 8192) rep[g_rk] = 0;
    return g_fail;
}
