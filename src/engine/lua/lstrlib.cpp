// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033bd00..0x0033d6e0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f0814e11 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0814e11 {} using namespace fn_f0814e11;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f0814e11 {
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00339f70(LuaVMState *L, int narg);
extern "C" int __cdecl FUN_00339fe0(LuaVMState *L, int narg, int def);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* B, const char* s, unsigned int l);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
} // namespace fn_f0814e11
extern "C" int __cdecl _isalpha(int);
extern "C" int __cdecl _iscntrl(int);
extern "C" int __cdecl _isdigit(int);
extern "C" int __cdecl _islower(int);
extern "C" int __cdecl _ispunct(int);
extern "C" int __cdecl _isupper(int);
extern "C" int __cdecl _isalnum(int);
extern "C" int __cdecl _isxdigit(int);
namespace fn_f0814e11 {
int FUN_0033c320(int c, int cl);
int FUN_0033c430(int c, const char *p, const char *ec);
extern "C" const char *__cdecl FUN_0033c7e0(LuaVMMatchState *ms, const char *s, const char *p);
const char *FUN_0033c790(int l, LuaVMMatchState *ms, const char *s);
const char *FUN_0033c2b0(LuaVMMatchState *ms, const char *p);
const char *FUN_0033c520(const char *p, const char *s, LuaVMMatchState *ms);
const char *FUN_0033c6e0(LuaVMMatchState *ms, const char *s, const char *p, int what);
const char *FUN_0033c730(LuaVMMatchState *ms, const char *s, const char *p);
const char *FUN_0033c590(const char *p, LuaVMMatchState *ms, const char *s, const char *ep);
const char *FUN_0033c640(const char *s, LuaVMMatchState *ms, const char *p, const char *ep);
extern "C" void *__cdecl memchr(const void *, int, unsigned int);
} // namespace fn_f0814e11
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl memcmp(const void *, const void *, unsigned int);
#endif
namespace fn_f0814e11 {
extern "C" void __cdecl FUN_00338fe0(LuaVMState *L, int space, const char *mes);
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx);
extern "C" char* __cdecl strpbrk(const char*, const char*);
const char* FUN_0033caa0(const char* s1, unsigned int l1, const char* s2, unsigned int l2);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
int FUN_0033cb70(LuaVMMatchState* ms, const char* s, const char* e);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" int __cdecl FUN_0033cdb0(LuaVMState* L);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
void FUN_0033cb10(int i, LuaVMMatchState* ms);
extern "C" void __cdecl FUN_00339590(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);


// 0x0033bd00 FUN_0033bd00 (41 B): matches/0x0033bd00.cpp
// sym: _FUN_0033bd00
// string.len
extern "C" int __cdecl FUN_0033bd00(LuaVMState* L) {
    unsigned int l;
    FUN_00339df0(L, 1, &l);
    FUN_00213360(L, (int)l);
    return 1;
}


// 0x0033bd40 FUN_0033bd40 (155 B): equivalent/0x0033bd40.cpp
// sym: _FUN_0033bd40
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 10/10)
// FUN_0033bd40 @ 0x0033bd40
// FUN_0033bd40: Lua string.sub
extern "C" int __cdecl FUN_0033bd40(LuaVMState *L)
{
    unsigned int l;
    const char *s = FUN_00339df0(L, 1, &l);
    int start = FUN_00339f70(L, 2);
    if (start < 0)
        start = (int)l + start + 1;
    int end = FUN_00339fe0(L, 3, -1);
    if (end < 0)
        end = end + (int)l + 1;
    if (start < 1)
        start = 1;
    if (end > (int)l)
        end = (int)l;
    if (start <= end)
        FUN_00213380(L, s + start - 1, (unsigned int)(end - start + 1));
    else
        FUN_00213380(L, "", 0);
    return 1;
}


// 0x0033c090 FUN_0033c090 (90 B): matches/0x0033c090.cpp
// sym: _FUN_0033c090
// string.byte
extern "C" int __cdecl FUN_0033c090(LuaVMState* L) {
    unsigned int l;
    const unsigned char* s = (const unsigned char*)FUN_00339df0(L, 1, &l);
    unsigned int oldLength = l;
    int result = FUN_00339fe0(L, 2, 1);
    unsigned int pos = (unsigned int)result;
    if (result < 0)
        pos += oldLength + 1;
    if ((int)pos > 0 && pos <= l) {
        FUN_00213360(L, s[pos - 1]);
        return 1;
    }
    return 0;
}


// 0x0033c1b0 FUN_0033c1b0 (29 B): matches/0x0033c1b0.cpp
// sym: _FUN_0033c1b0
// writer (str_dump's lua_Writer): add the piece to the buffer in ud
extern "C" int __cdecl FUN_0033c1b0(LuaVMState* L, const void* p, unsigned int size, void* ud) {
    FUN_003394b0((LuaVMLBuffer*)ud, (const char*)p, size);
    return 1;
}


// 0x0033c2b0 FUN_0033c2b0 (105 B): equivalent/0x0033c2b0.cpp
// sym: ?FUN_0033c2b0@fn_f0814e11@@YAPBDPAULuaVMMatchState@@PBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3065 inputs, branch coverage 16/16)
// FUN_0033c2b0 @ 0x0033c2b0
// lstrlib luaI_classend: the end of the single-character class at p
// equiv-conv: FUN_0033c2b0 edi eax
const char* FUN_0033c2b0(LuaVMMatchState* ms, const char* p) {
    char c = *p++;
    if (c == '%') {
        if (*p == 0)
            FUN_00338e20(ms->L, "malformed pattern (ends with `%%')");
        return p + 1;
    }
    if (c == '[') {
        if (*p == '^')
            p++;
        do {
            if (*p == 0)
                FUN_00338e20(ms->L, "malformed pattern (missing `]')");
            if (*(p++) == '%' && *p != 0)
                p++;
        } while (*p != ']');
        return p + 1;
    }
    return p;
}


// 0x0033c320 FUN_0033c320 (199 B): equivalent/0x0033c320.cpp
// sym: ?FUN_0033c320@fn_f0814e11@@YAHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3045 inputs, branch coverage 21/21)
// FUN_0033c320 @ 0x0033c320
// equiv-conv: FUN_0033c320 eax edi
int __cdecl FUN_0033c320(int character, int classCode) {
    int result;
    switch (FUN_00345475(classCode)) {
    case 'a': result = _isalpha(character); break;
    case 'c': result = _iscntrl(character); break;
    case 'd': result = _isdigit(character); break;
    case 'l': result = _islower(character); break;
    case 'p': result = _ispunct(character); break;
    case 's': result = _isspace(character); break;
    case 'u': result = _isupper(character); break;
    case 'w': result = _isalnum(character); break;
    case 'x': result = _isxdigit(character); break;
    case 'z': result = character == 0; break;
    default: return classCode == character;
    }
    return _islower(classCode) ? result : !result;
}


// 0x0033c430 FUN_0033c430 (145 B): equivalent/0x0033c430.cpp
// sym: ?FUN_0033c430@fn_f0814e11@@YAHHPBD0@Z
// STATUS: equivalent (tools/equiv.py level 3: 2752 inputs, branch coverage 22/22)
// FUN_0033c430 @ 0x0033c430
// Lua 5.0 lstrlib matchbracketclass
// equiv-conv: FUN_0033c320 eax edi
// equiv-conv: FUN_0033c430 ebx eax stack
int FUN_0033c430(int c, const char *p, const char *ec)
{
    int sig = 1;
    if (*(p + 1) == '^') {
        sig = 0;
        p++;
    }
    while (++p < ec) {
        if (*p == '%') {
            p++;
            if (FUN_0033c320(c, *p))
                return sig;
        } else if (*(p + 1) == '-' && (p + 2 < ec)) {
            p += 2;
            if ((unsigned char)*(p - 2) <= c && c <= (unsigned char)*p)
                return sig;
        } else if ((unsigned char)*p == c) {
            return sig;
        }
    }
    return !sig;
}


// 0x0033c4d0 FUN_0033c4d0 (70 B): equivalent/0x0033c4d0.cpp
// sym: ?FUN_0033c4d0@fn_f0814e11@@YAHPBDH0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// FUN_0033c4d0 @ 0x0033c4d0
// lstrlib singlematch(c, p, ep)
// equiv-conv: FUN_0033c320 eax edi
// equiv-conv: FUN_0033c430 ebx eax stack
// equiv-conv: FUN_0033c4d0 eax ecx stack
int FUN_0033c4d0(const char *p, int c, const char *ep)
{
    unsigned char pc = (unsigned char)*p;
    if (pc == '%')
        return FUN_0033c320(c, (signed char)p[1]);
    if (pc == '.')
        return 1;
    if (pc == '[')
        return FUN_0033c430(c, p, ep - 1);
    return pc == (unsigned int)c;
}


// 0x0033c520 FUN_0033c520 (100 B): equivalent/0x0033c520.cpp
// sym: ?FUN_0033c520@fn_f0814e11@@YAPBDPBD0PAULuaVMMatchState@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 16/16)
// FUN_0033c520 @ 0x0033c520
// lstrlib matchbalance
// equiv-conv: FUN_0033c520 eax ecx ebx
const char *FUN_0033c520(const char *p, const char *s, LuaVMMatchState *ms)
{
    if (*p == 0 || p[1] == 0)
        FUN_00338e20(ms->L, "unbalanced pattern");
    if (*s != *p)
        return 0;
    int b = *p;
    int e = p[1];
    int cont = 1;
    const char *end = ms->src_end;
    while (++s < end) {
        int c = *s;
        if (c == e) {
            if (--cont == 0)
                return s + 1;
        } else if (c == b) {
            cont++;
        }
    }
    return 0;
}


// 0x0033c590 FUN_0033c590 (164 B): equivalent/0x0033c590.cpp
// sym: ?FUN_0033c590@fn_f0814e11@@YAPBDPBDPAULuaVMMatchState@@00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3097 inputs, branch coverage 17/18, incomplete)
// FUN_0033c590 @ 0x0033c590
// Lua 5.0 lstrlib max_expand
// equiv-conv: FUN_0033c430 ebx eax stack
// equiv-conv: FUN_0033c320 eax edi
// equiv-conv: FUN_0033c590 eax stack stack stack
const char *FUN_0033c590(const char *p, LuaVMMatchState *ms, const char *s, const char *ep)
{
    int i = 0;
    while (s + i < ms->src_end) {
        int c = (unsigned char)s[i];
        int ok;
        switch (*p) {
        case '%':
            ok = FUN_0033c320(c, p[1]);
            break;
        case '.':
            ok = 1;
            break;
        case '[':
            ok = FUN_0033c430(c, p, ep - 1);
            break;
        default:
            ok = (unsigned char)*p == c;
            break;
        }
        if (!ok)
            break;
        i++;
    }
    while (i >= 0) {
        const char *res = FUN_0033c7e0(ms, s + i, ep + 1);
        if (res != 0)
            return res;
        i--;
    }
    return 0;
}


// 0x0033c640 FUN_0033c640 (145 B): equivalent/0x0033c640.cpp
// sym: ?FUN_0033c640@fn_f0814e11@@YAPBDPBDPAULuaVMMatchState@@00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3058 inputs, branch coverage 14/14)
// FUN_0033c640 @ 0x0033c640
// Lua 5.0 lstrlib min_expand
// equiv-conv: FUN_0033c430 ebx eax stack
// equiv-conv: FUN_0033c320 eax edi
// equiv-conv: FUN_0033c640 eax stack stack stack
const char *FUN_0033c640(const char *s, LuaVMMatchState *ms, const char *p, const char *ep)
{
    for (;;) {
        const char *res = FUN_0033c7e0(ms, s, ep + 1);
        if (res != 0)
            return res;
        if (s >= ms->src_end)
            return 0;
        int c = (unsigned char)*s;
        int ok;
        switch (*p) {
        case '%':
            ok = FUN_0033c320(c, p[1]);
            break;
        case '.':
            ok = 1;
            break;
        case '[':
            ok = FUN_0033c430(c, p, ep - 1);
            break;
        default:
            ok = (unsigned char)*p == c;
            break;
        }
        if (!ok)
            return 0;
        s++;
    }
}


// 0x0033c6e0 FUN_0033c6e0 (66 B): equivalent/0x0033c6e0.cpp
// sym: ?FUN_0033c6e0@fn_f0814e11@@YAPBDPAULuaVMMatchState@@PBD1H@Z
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_0033c6e0 @ 0x0033c6e0
// lstrlib start_capture
// equiv-conv: FUN_0033c6e0 esi ebx stack stack
const char* FUN_0033c6e0(LuaVMMatchState* ms, const char* s, const char* p, int what)
{
    int level = ms->level;
    if (level >= LUAVM_MAXCAPTURES)
        FUN_00338e20(ms->L, "too many captures");
    ms->capture[level].init = s;
    ms->capture[level].len = what;
    ms->level = level + 1;
    const char* res = FUN_0033c7e0(ms, s, p);
    if (!res)
        --ms->level;
    return res;
}


// 0x0033c730 FUN_0033c730 (89 B): equivalent/0x0033c730.cpp
// sym: ?FUN_0033c730@fn_f0814e11@@YAPBDPAULuaVMMatchState@@PBD1@Z
// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 8/8)
// FUN_0033c730 @ 0x0033c730
// lstrlib end_capture (capture_to_close inlined)
// equiv-conv: FUN_0033c730 esi ebx stack
const char* FUN_0033c730(LuaVMMatchState* ms, const char* s, const char* p)
{
    int l = ms->level - 1;
    while (l >= 0 && ms->capture[l].len != LUAVM_CAP_UNFINISHED)
        --l;
    if (l < 0)
        l = FUN_00338e20(ms->L, "invalid pattern capture");
    ms->capture[l].len = (int)(s - ms->capture[l].init);
    const char* res = FUN_0033c7e0(ms, s, p);
    if (res == 0)
        ms->capture[l].len = LUAVM_CAP_UNFINISHED;
    return res;
}


// 0x0033c790 FUN_0033c790 (75 B): equivalent/0x0033c790.cpp
// sym: ?FUN_0033c790@fn_f0814e11@@YAPBDHPAULuaVMMatchState@@PBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 10/10)
// FUN_0033c790 @ 0x0033c790
// lstrlib match_capture (check_capture inlined)
// equiv-conv: FUN_0033c790 eax ecx ebx
const char *FUN_0033c790(int l, LuaVMMatchState *ms, const char *s)
{
    l -= 0x31;
    if (l < 0 || l >= ms->level || ms->capture[l].len == LUAVM_CAP_UNFINISHED)
        l = FUN_00338e20(ms->L, "invalid capture index");
    unsigned len = (unsigned)ms->capture[l].len;
    if ((unsigned)(ms->src_end - s) >= len) {
        const char *text = ms->capture[l].init;
        for (unsigned i = 0; i < len; ++i)
            if (text[i] != s[i]) return 0;
        return s + len;
    }
    return 0;
}


// 0x0033c7e0 FUN_0033c7e0 (591 B): equivalent/0x0033c7e0.cpp
// sym: _FUN_0033c7e0
// STATUS: equivalent (tools/equiv.py level 3: 3164 inputs, branch coverage 53/57, incomplete)
// FUN_0033c7e0 @ 0x0033c7e0
// lstrlib match
// equiv-conv: FUN_0033c790 eax ecx ebx
// equiv-conv: FUN_0033c2b0 edi eax
// equiv-conv: FUN_0033c430 ebx eax stack
// equiv-conv: FUN_0033c520 eax ecx ebx
// equiv-conv: FUN_0033c320 eax edi
// equiv-conv: FUN_0033c6e0 esi ebx stack stack
// equiv-conv: FUN_0033c730 esi ebx stack
// equiv-conv: FUN_0033c590 eax stack stack stack
// equiv-conv: FUN_0033c640 eax stack stack stack
extern "C" const char *__cdecl FUN_0033c7e0(LuaVMMatchState *ms, const char *s, const char *p)
{
    for (;;) {
        bool deflt = false;
        switch (*p) {
        case '(':
            if (p[1] == ')')
                return FUN_0033c6e0(ms, s, p + 2, -2);
            return FUN_0033c6e0(ms, s, p + 1, -1);
        case ')':
            return FUN_0033c730(ms, s, p + 1);
        case '%':
            if (p[1] == 'b') {
                s = FUN_0033c520(p + 2, s, ms);
                if (s == 0)
                    return 0;
                p += 4;
                continue;
            }
            if (p[1] == 'f') {
                p += 2;
                if (*p != '[')
                    FUN_00338e20(ms->L, "missing `[' after `%%f' in pattern");
                const char *ep = FUN_0033c2b0(ms, p);
                char previous = (s == ms->src_init) ? 0 : s[-1];
                if (FUN_0033c430((unsigned char)previous, p, ep - 1))
                    return 0;
                if (!FUN_0033c430((unsigned char)*s, p, ep - 1))
                    return 0;
                p = ep;
                continue;
            }
            if (isdigit((unsigned char)p[1])) {
                s = FUN_0033c790(p[1], ms, s);
                if (s == 0)
                    return 0;
                p += 2;
                continue;
            }
            deflt = true;
            break;
        case 0:
            return s;
        case '$':
            if (p[1] == 0)
                return (s == ms->src_end) ? s : 0;
            deflt = true;
            break;
        default:
            deflt = true;
            break;
        }
        if (deflt) {
            const char *ep = FUN_0033c2b0(ms, p);
            int m = 0;
            if (s < ms->src_end) {
                int c = (unsigned char)*s;
                if (*p == '%')
                    m = FUN_0033c320(c, p[1]);
                else if (*p == '.')
                    m = 1;
                else if (*p == '[')
                    m = FUN_0033c430(c, p, ep - 1);
                else
                    m = ((unsigned char)*p == c);
            }
            switch (*ep) {
            case '?':
                if (m) {
                    const char *res = FUN_0033c7e0(ms, s + 1, ep + 1);
                    if (res != 0)
                        return res;
                }
                p = ep + 1;
                continue;
            case '*':
                return FUN_0033c590(p, ms, s, ep);
            case '+':
                if (!m)
                    return 0;
                return FUN_0033c590(p, ms, s + 1, ep);
            case '-':
                return FUN_0033c640(s, ms, p, ep);
            default:
                if (!m)
                    return 0;
                s++;
                p = ep;
                continue;
            }
        }
    }
}


// 0x0033caa0 FUN_0033caa0 (109 B): equivalent/0x0033caa0.cpp
// sym: ?FUN_0033caa0@fn_f0814e11@@YAPBDPBDI0I@Z
// STATUS: equivalent (tools/equiv.py level 3: 2528 inputs, branch coverage 10/12, incomplete)
// FUN_0033caa0 @ 0x0033caa0
// equiv-conv: FUN_0033caa0 eax stack stack stack
const char *FUN_0033caa0(const char *s1, unsigned int l1, const char *s2, unsigned int l2)
{
    if (l2 == 0)
        return s1;
    if (l2 > l1)
        return 0;
    l2--;
    l1 = l1 - l2;
    while (l1 > 0) {
        const char *init = (const char *)memchr(s1, *s2, l1);
        if (init == 0)
            break;
        init++;
        if (memcmp(init, s2 + 1, l2) == 0)
            return init - 1;
        l1 -= init - s1;
        s1 = init;
    }
    return 0;
}


// 0x0033cb10 FUN_0033cb10 (81 B): equivalent/0x0033cb10.cpp
// sym: ?FUN_0033cb10@fn_f0814e11@@YAXHPAULuaVMMatchState@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4)
// FUN_0033cb10 @ 0x0033cb10
// lstrlib push_onecapture
// equiv-conv: FUN_0033cb10 eax esi
void FUN_0033cb10(int i, LuaVMMatchState* ms)
{
    int l = ms->capture[i].len;
    if (l == LUAVM_CAP_UNFINISHED)
        FUN_00338e20(ms->L, "unfinished capture");
    else if (l == LUAVM_CAP_POSITION) {
        FUN_00213360(ms->L, (int)(ms->capture[i].init - ms->src_init) + 1);
        return;
    }
    FUN_00213380(ms->L, ms->capture[i].init, (unsigned int)l);
}


// 0x0033cb70 FUN_0033cb70 (158 B): equivalent/0x0033cb70.cpp
// sym: ?FUN_0033cb70@fn_f0814e11@@YAHPAULuaVMMatchState@@PBD1@Z
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// FUN_0033cb70 @ 0x0033cb70
// FUN_0033cb70 @ 0x0033cb70: Lua 5.0 lstrlib push_captures (push_onecapture inlined)
// equiv-conv: FUN_0033cb70 esi ecx eax
int FUN_0033cb70(LuaVMMatchState *ms, const char *s, const char *e)
{
    FUN_00338fe0(ms->L, ms->level, "too many captures");
    if (ms->level == 0 && s) {
        FUN_00213380(ms->L, s, (unsigned int)(e - s));
        return 1;
    }
    for (int i = 0; i < ms->level; i++) {
        int l = ms->capture[i].len;
        if (l == LUAVM_CAP_UNFINISHED)
            FUN_00338e20(ms->L, "unfinished capture");
        if (l == LUAVM_CAP_POSITION)
            FUN_00213360(ms->L, (int)(ms->capture[i].init - ms->src_init + 1));
        else
            FUN_00213380(ms->L, ms->capture[i].init, (unsigned int)l);
    }
    return ms->level;
}


// 0x0033cc10 FUN_0033cc10 (402 B): equivalent/0x0033cc10.cpp
// sym: _FUN_0033cc10
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 20/20)
// FUN_0033cc10 @ 0x0033cc10
// lstrlib str_find
// equiv-conv: FUN_0033caa0 eax stack stack stack
// equiv-conv: FUN_0033cb70 esi ecx eax
extern "C" int __cdecl FUN_0033cc10(LuaVMState* L) {
    // the original's frame order (the harness compares the uninitialized locals passed by address)
    struct {
        unsigned int l1;
        const char* pattern;
        unsigned int l2;
        int anchor;
        LuaVMMatchState ms;
    } f;
    const char* s = FUN_00339df0(L, 1, &f.l1);
    const char* p = FUN_00339df0(L, 2, &f.l2);
    f.pattern = p;
    unsigned int oldLength = f.l1;
    int requested = FUN_00339fe0(L, 3, 1);
    if (requested < 0)
        requested = (int)((unsigned)requested + oldLength + 1);
    unsigned int init = (unsigned)requested - 1;
    if ((int)init < 0)
        init = 0;
    else if (init > f.l1)
        init = f.l1;
    if (!FUN_00213160(L, 4) && strpbrk(p, "^$*+?.([%-")) {
        f.anchor = (*p == '^');
        if (f.anchor) {
            ++p;
            f.pattern = p;
        }
        f.ms.src_init = s;
        f.ms.src_end = s + f.l1;
        f.ms.L = L;
        const char* s1 = s + init;
        for (;;) {
            f.ms.level = 0;
            const char* e = FUN_0033c7e0(&f.ms, s1, p);
            if (e) {
                FUN_00213360(L, (int)(s1 - s) + 1);
                FUN_00213360(L, (int)(e - s));
                return FUN_0033cb70(&f.ms, 0, 0) + 2;
            }
            const char* previous = s1++;
            if (previous >= f.ms.src_end || f.anchor)
                break;
            p = f.pattern;
        }
    } else {
        const char* s2 = FUN_0033caa0(s + init, f.l1 - init, p, f.l2);
        if (s2) {
            unsigned int offset = (unsigned int)(s2 - s);
            FUN_00213360(L, (int)(offset + 1));
            FUN_00213360(L, (int)(offset + f.l2));
            return 2;
        }
    }
    FUN_00213320(L);
    return 1;
}


// 0x0033cdb0 FUN_0033cdb0 (207 B): equivalent/0x0033cdb0.cpp
// sym: _FUN_0033cdb0
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033cdb0 @ 0x0033cdb0
// lstrlib gfind_aux (upvalues: the string, the pattern, the position)
// equiv-conv: FUN_0033cb70 esi ecx eax
extern "C" int __cdecl FUN_0033cdb0(LuaVMState* L) {
    const char* s = FUN_00213190(L, -10002);
    unsigned int ls = FUN_002131f0(L, -10002);
    const char* p = FUN_00213190(L, -10003);
    LuaVMMatchState ms;
    ms.L = L;
    ms.src_init = s;
    ms.src_end = s + ls;
    const char* src = s + FUN_00213120(L, -10004);
    if (src > ms.src_end)
        return 0;
    const char* e;
    for (;;) {
        ms.level = 0;
        e = FUN_0033c7e0(&ms, src, p);
        if (e)
            break;
        ++src;
        if (src > ms.src_end)
            return 0;
    }
    int newstart = (int)(e - s);
    if (e == src)
        ++newstart;
    FUN_00213360(L, newstart);
    FUN_00212e60(L, -10004);
    return FUN_0033cb70(&ms, src, e);
}


// 0x0033ce80 FUN_0033ce80 (64 B): matches/0x0033ce80.cpp
// sym: _FUN_0033ce80
// string.gfind
extern "C" int __cdecl FUN_0033ce80(LuaVMState* L) {
    FUN_00339df0(L, 1, 0);
    FUN_00339df0(L, 2, 0);
    FUN_00212d80(L, 2);
    FUN_00213360(L, 0);
    FUN_002134a0(L, FUN_0033cdb0, 3);
    return 1;
}


// 0x0033cec0 FUN_0033cec0 (296 B): equivalent/0x0033cec0.cpp
// sym: ?FUN_0033cec0@fn_f0814e11@@YAXPAULuaVMMatchState@@PAULuaVMLBuffer@@PBD2@Z
// STATUS: equivalent (tools/equiv.py level 3: 2485 inputs, branch coverage 22/22)
// FUN_0033cec0 @ 0x0033cec0
// lstrlib add_s (gsub's replacement: a string with %n captures, or a function)
// equiv-conv: FUN_0033cb10 eax esi
// equiv-conv: FUN_0033cb70 esi ecx eax
// equiv-conv: FUN_0033cec0 eax ebx stack stack
void FUN_0033cec0(LuaVMMatchState* ms, LuaVMLBuffer* b, const char* s, const char* e) {
    LuaVMState* L = ms->L;
    if (FUN_00212fb0(L, 3)) {
        const unsigned char* news = (const unsigned char*)FUN_00213190(L, 3);
        unsigned int l = FUN_002131f0(L, 3);
        for (unsigned int i = 0; i < l; ++i) {
            if (news[i] != '%') {
                if (b->p >= b->buffer + LUAVM_BUFFERSIZE)
                    FUN_00339470(b);
                *b->p = news[i];
                ++b->p;
            } else {
                ++i;
                if (!_isdigit(news[i])) {
                    if (b->p >= b->buffer + LUAVM_BUFFERSIZE)
                        FUN_00339470(b);
                    *b->p = news[i];
                    ++b->p;
                } else {
                    int index = (signed char)news[i] - '1';
                    if (index < 0 || index >= ms->level || ms->capture[index].len == LUAVM_CAP_UNFINISHED)
                        index = FUN_00338e20(ms->L, "invalid capture index");
                    FUN_0033cb10(index, ms);
                    FUN_00339590(b);
                }
            }
        }
    } else {
        FUN_00212ed0(L, 3);
        int n = FUN_0033cb70(ms, s, e);
        FUN_002139a0(L, n, 1);
        if (FUN_00212fb0(L, -1))
            FUN_00339590(b);
        else
            FUN_00212d80(L, -2);
    }
}


// 0x0033d1c0 FUN_0033d1c0 (219 B): equivalent/0x0033d1c0.cpp
// sym: ?FUN_0033d1c0@fn_f0814e11@@YAXPAULuaVMLBuffer@@PAULuaVMState@@H@Z
// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 19/19)
// FUN_0033d1c0 @ 0x0033d1c0
// lstrlib addquoted (format's %q)
// equiv-conv: FUN_0033d1c0 esi edx ecx
void FUN_0033d1c0(LuaVMLBuffer* b, LuaVMState* L, int arg) {
    unsigned l;
    const char* s = FUN_00339df0(L, arg, &l);
    char* end = b->buffer + LUAVM_BUFFERSIZE;
    if (b->p >= end) FUN_00339470(b);
    *b->p = '"';
    ++b->p;
    while (l) {
        --l;
        signed char ch = *s;
        if (ch == '"' || ch == '\\' || ch == '\n') {
            if (b->p >= end) FUN_00339470(b);
            *b->p = '\\';
            ++b->p;
            if (b->p >= end) FUN_00339470(b);
            *b->p = *s;
            ++b->p;
        } else if (ch == 0) {
            FUN_003394b0(b, "\\000", 4);
        } else {
            if (b->p >= end) FUN_00339470(b);
            *b->p = *s;
            ++b->p;
        }
        ++s;
    }
    if (b->p >= end) FUN_00339470(b);
    *b->p = '"';
    ++b->p;
}


// 0x0033d310 FUN_0033d310 (235 B): equivalent/0x0033d310.cpp
// sym: ?FUN_0033d310@fn_f0814e11@@YAPBDPBDPAULuaVMState@@PADPAH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2655 inputs, branch coverage 18/18)
// FUN_0033d310 @ 0x0033d310
// lstrlib scanformat
// equiv-conv: FUN_0033d310 ebx stack stack stack
const char* FUN_0033d310(const char* strfrmt, LuaVMState* L, char* form, int* hasprecision)
{
    const char* p = strfrmt;
    while (strchr("-+ #0", (signed char)*p)) ++p;
    if (isdigit((unsigned char)*p)) ++p;
    if (isdigit((unsigned char)*p)) ++p;
    if (*p == '.') {
        ++p;
        *hasprecision = 1;
        if (isdigit((unsigned char)*p)) ++p;
        if (isdigit((unsigned char)*p)) ++p;
    }
    if (isdigit((unsigned char)*p))
        FUN_00338e20(L, "invalid format (width or precision too long)");
    int length = (int)(p - strfrmt);
    if (length + 2 > 20)
        FUN_00338e20(L, "invalid format (too long)");
    *form = '%';
    strncpy(form + 1, strfrmt, (unsigned int)(length + 1));
    form[length + 2] = 0;
    return p;
}


// 0x0033d6c0 FUN_0033d6c0 (31 B): matches/0x0033d6c0.cpp
// sym: _FUN_0033d6c0
// data: libname = DAT_003fd600, the luaL_reg list = DAT_00434af8
extern "C" int __cdecl FUN_0033d6c0(LuaVMState* L) {
    FUN_003390d0(L, DAT_003fd600, (const LuaVMReg*)&DAT_00434af8, 0);
    return 1;
}

} // namespace fn_f0814e11
