// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033bd00..0x0033d6e0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f5bfbc89 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5bfbc89 {} using namespace fn_f5bfbc89;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f5bfbc89 {
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);
extern "C" unsigned char __cdecl FUN_00345b90(unsigned character);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* B, const char* s, unsigned int l);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_00213b60(LuaVMState* L, LuaVMWriter writer, void* data);
extern "C" int __cdecl FUN_0033c1b0(LuaVMState* L, const void* p, unsigned int size, void* ud);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_0033c7e0(LuaVMMatchState* ms, const char* s, const char* p);
void FUN_0033cec0(LuaVMMatchState* ms, LuaVMLBuffer* b, const char* s, const char* e);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
} // namespace fn_f5bfbc89
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);
namespace fn_f5bfbc89 {
const char *FUN_0033d310(const char *strfrmt, LuaVMState *L, char *form, int *hasprecision);
extern "C" float __cdecl FUN_00339ec0(LuaVMState *L, int narg);
void FUN_0033d1c0(LuaVMLBuffer *b, LuaVMState *L, int arg);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00339590(LuaVMLBuffer *B);
struct Frame_33d400 {
    int unused;
    int hasprecision;
    const char *strfrmt_end;
    int arg;
    unsigned int sfl;
    unsigned int l;
    char form[20];
    LuaVMLBuffer b;
    int gap;
    char buff[512];  // Lua 5.0 MAX_ITEM; the old source had 120, which %99.99f overflows
};


// 0x0033bde0 FUN_0033bde0 (179 B): matches/0x0033bde0.cpp
// sym: _FUN_0033bde0
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 6/6)
// FUN_0033bde0 @ 0x0033bde0
// string.reverse
extern "C" int __cdecl FUN_0033bde0(LuaVMState* L) {
    unsigned int l;
    LuaVMLBuffer b;
    const char* s = FUN_00339df0(L, 1, &l);
    FUN_00339630(L, &b);
    if (l) {
        do {
            --l;
            if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
                FUN_00339470(&b);
            *b.p = s[l];
            ++b.p;
        } while (l);
    }
    --l;
    FUN_00339540(&b);
    return 1;
}


// 0x0033bea0 FUN_0033bea0 (170 B): equivalent/0x0033bea0.cpp
// sym: _FUN_0033bea0 @4d0c3b4c7913 @we03e85264bdd
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 6/6)
// FUN_0033bea0 @ 0x0033bea0
// string.lower
extern "C" int __cdecl FUN_0033bea0(LuaVMState* L) {
    unsigned int l;
    LuaVMLBuffer b;
    const unsigned char* s = (const unsigned char*)FUN_00339df0(L, 1, &l);
    FUN_00339630(L, &b);
    for (unsigned i = 0; i < l; ++i) {
        if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
            FUN_00339470(&b);
        int c = FUN_00345475(s[i]);
        *b.p = (char)c;
        ++b.p;
    }
    FUN_00339540(&b);
    return 1;
}


// 0x0033bf50 FUN_0033bf50 (170 B): matches/0x0033bf50.cpp
// sym: _FUN_0033bf50
// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 6/6)
// FUN_0033bf50 @ 0x0033bf50
// string.upper
extern "C" int __cdecl FUN_0033bf50(LuaVMState* L) {
    struct { unsigned int l; LuaVMLBuffer b; } local;
    const unsigned char* s = (const unsigned char*)FUN_00339df0(L, 1, &local.l);
    FUN_00339630(L, &local.b);
    for (unsigned i = 0; i < local.l; ++i) {
        if (local.b.p >= local.b.buffer + LUAVM_BUFFERSIZE)
            FUN_00339470(&local.b);
        unsigned char ch = FUN_00345b90(s[i]);
        *local.b.p = ch;
        ++local.b.p;
    }
    FUN_00339540(&local.b);
    return 1;
}


// 0x0033c000 FUN_0033c000 (133 B): matches/0x0033c000.cpp
// sym: _FUN_0033c000
// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 4/4)
// FUN_0033c000 @ 0x0033c000
// string.rep
extern "C" int __cdecl FUN_0033c000(LuaVMState* L)
{
    unsigned int l;
    LuaVMLBuffer b;
    const char* s = FUN_00339df0(L, 1, &l);
    int n = FUN_00339f70(L, 2);
    FUN_00339630(L, &b);
    while (n > 0) {
        FUN_003394b0(&b, s, l);
        n--;
    }
    FUN_00339540(&b);
    return 1;
}


// 0x0033c0f0 FUN_0033c0f0 (187 B): matches/0x0033c0f0.cpp
// sym: _FUN_0033c0f0
// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 8/8)
// FUN_0033c0f0 @ 0x0033c0f0
// string.char
extern "C" int __cdecl FUN_0033c0f0(LuaVMState* L) {
    LuaVMLBuffer b;
    int n = FUN_00212d70(L);
    FUN_00339630(L, &b);
    for (int i = 1; i <= n; ++i) {
        int c = FUN_00339f70(L, i);
        if ((unsigned char)c != c)
            FUN_00339c30(L, i, "invalid value");
        if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
            FUN_00339470(&b);
        *b.p = (char)(unsigned char)c;
        ++b.p;
    }
    FUN_00339540(&b);
    return 1;
}


// 0x0033c1d0 FUN_0033c1d0 (122 B): equivalent/0x0033c1d0.cpp
// sym: _FUN_0033c1d0 @95f018940b01 @w8a27af228d15
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033c1d0 @ 0x0033c1d0
// Lua 5.0 str_dump
                                 // luaL_pushresult
extern "C" int __cdecl FUN_0033c1d0(LuaVMState* L) {
    LuaVMLBuffer b;
    FUN_00339d70(L, 1, LUAVM_TFUNCTION);
    FUN_00339630(L, &b);
    if (!FUN_00213b60(L, FUN_0033c1b0, &b))
        FUN_00338e20(L, "unable to dump given function");
    FUN_00339540(&b);
    return 1;
}


// 0x0033cff0 FUN_0033cff0 (451 B): equivalent/0x0033cff0.cpp
// sym: _FUN_0033cff0 @960de7032488 @wf49d5137ec67
// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 22/22)
// FUN_0033cff0 @ 0x0033cff0
// lstrlib str_gsub
// equiv-conv: FUN_0033cec0 eax ebx stack stack
extern "C" int __cdecl FUN_0033cff0(LuaVMState* L) {
    unsigned int srcl;
    const char* src = FUN_00339df0(L, 1, &srcl);
    const char* p = FUN_00339df0(L, 2, 0);
    int max_s = FUN_00339fe0(L, 4, (int)(srcl + 1));
    bool anchor = (*p == '^');
    if (anchor)
        ++p;
    int n = 0;
    if (FUN_00212d70(L) < 3 || (!FUN_00212fb0(L, 3) && FUN_00212f00(L, 3) != LUAVM_TFUNCTION))
        FUN_00339c30(L, 3, "string or function expected");
    LuaVMLBuffer b;
    FUN_00339630(L, &b);
    LuaVMMatchState ms;
    ms.L = L;
    ms.src_init = src;
    ms.src_end = src + srcl;
    if (max_s > 0) {
        do {
            ms.level = 0;
            const char* e = FUN_0033c7e0(&ms, src, p);
            if (e) {
                ++n;
                FUN_0033cec0(&ms, &b, src, e);
            }
            if (e && e > src)
                src = e;
            else {
                if (src >= ms.src_end)
                    break;
                if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
                    FUN_00339470(&b);
                *b.p = *src;
                ++b.p;
                ++src;
            }
        } while (!anchor && n < max_s);
    }
    FUN_003394b0(&b, src, (unsigned int)(ms.src_end - src));
    FUN_00339540(&b);
    FUN_00213360(L, n);
    return 2;
}


// 0x0033d400 FUN_0033d400 (627 B): equivalent/0x0033d400.cpp
// sym: _FUN_0033d400 @b4f28797de63 @w2e225bed8976
// STATUS: equivalent (tools/equiv.py level 3: 2000 inputs, branch coverage 30/30)
// FUN_0033d400 @ 0x0033d400
// checked with equiv.py --time-budget 3600 (at the defaults most inputs hit the time budget)
// equiv-conv: FUN_0033d310 ebx stack stack stack
// equiv-conv: FUN_0033d1c0 esi edx ecx
extern "C" int __cdecl FUN_0033d400(LuaVMState *L)
{
    Frame_33d400 f;
    f.arg = 1;
    const char *strfrmt = FUN_00339df0(L, f.arg, &f.sfl);
    f.strfrmt_end = strfrmt + f.sfl;
    FUN_00339630(L, &f.b);
    while (strfrmt < f.strfrmt_end) {
        if (*strfrmt != '%') {
            if (f.b.p >= f.b.buffer + sizeof(f.b.buffer))
                FUN_00339470(&f.b);
            *f.b.p++ = *strfrmt++;
        } else if (*++strfrmt == '%') {
            if (f.b.p >= f.b.buffer + sizeof(f.b.buffer))
                FUN_00339470(&f.b);
            *f.b.p++ = *strfrmt++;
        } else {
            f.hasprecision = 0;
            if (isdigit((unsigned char)*strfrmt) && strfrmt[1] == '$') {
                int r = FUN_00338e20(L, "obsolete option (d$) to `format'");
                return r;
            }
            f.arg++;
            strfrmt = FUN_0033d310(strfrmt, L, f.form, &f.hasprecision);
            switch (*strfrmt++) {
            case 'c':
            case 'd':
            case 'i':
                _sprintf(f.buff, f.form, FUN_00339f70(L, f.arg));
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                _sprintf(f.buff, f.form, (unsigned int)FUN_00339ec0(L, f.arg));
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'g':
            case 'G':
                _sprintf(f.buff, f.form, (double)FUN_00339ec0(L, f.arg));
                break;
            case 'q':
                FUN_0033d1c0(&f.b, L, f.arg);
                continue;
            case 's': {
                const char *s = FUN_00339df0(L, f.arg, &f.l);
                if (!f.hasprecision && f.l >= 100) {
                    FUN_00212ed0(L, f.arg);
                    FUN_00339590(&f.b);
                    continue;
                }
                _sprintf(f.buff, f.form, s);
                break;
            }
            default: {
                int r = FUN_00338e20(L, "invalid option to `format'");
                return r;
            }
            }
            const char *e = f.buff;
            while (*e++ != 0) {
            }
            FUN_003394b0(&f.b, f.buff, (unsigned int)(e - 1 - f.buff));
        }
    }
    FUN_00339540(&f.b);
    return 1;
}

} // namespace fn_f5bfbc89
