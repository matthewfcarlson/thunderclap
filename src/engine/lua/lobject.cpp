// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00215f50..0x002164b0 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f19d9cff {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f19d9cff {} using namespace fn_f19d9cff;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f19d9cff {
double __cdecl FUN_003472cb(const char*, const char**);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
static inline int strlen_inline(const char* s) {
    const char* p = s;
    while (*p)
        p++;
    return (int)(p - s);
}
extern "C" void __cdecl FUN_00217f20(LuaVMState* L, int total, int last);
extern "C" void __cdecl FUN_00216060(LuaVMState* L, const char* str);
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);
extern "C" unsigned int strcspn(const char *s, const char *set);


// 0x00215f50 FUN_00215f50 (31 B): matches/0x00215f50.cpp
// sym: _FUN_00215f50
extern "C" unsigned int FUN_00215f50(unsigned int value) {
    unsigned int exponent = 0;
    if (value >= 8) {
        do {
            value = (value + 1) >> 1;
            ++exponent;
        } while (value >= 8);
    }
    return (exponent << 3) | value;
}


// 0x00215f70 FUN_00215f70 (39 B): matches/0x00215f70.cpp
// sym: _FUN_00215f70
// luaO_log2: floor(log2(x)) through the byte table at 0x00426830.
// data: gTable_215f70 = DAT_00426830
extern "C" int __cdecl FUN_00215f70(unsigned int value) {
    int count = -1;
    while (value >= 0x100) {
        value >>= 8;
        count += 8;
    }
    return ((unsigned char*)&DAT_00426830)[value] + count;
}


// 0x00215fa0 FUN_00215fa0 (62 B): equivalent/0x00215fa0.cpp
// sym: _FUN_00215fa0 @5d7b647674a3 @w5408c710f1da
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 10/10)
// luaO_rawequalObj: same type and the same value (numbers compare as floats).
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2) {
    if ((unsigned int)t1->tt != (unsigned int)t2->tt)
        return 0;
    switch ((unsigned int)t1->tt) {
    case LUAVM_TNIL:
        return 1;
    case LUAVM_TNUMBER:
        return t1->value.n == t2->value.n;
    case LUAVM_TBOOLEAN:
        return t1->value.b == t2->value.b;
    default:
        return t1->value.p == t2->value.p;  // light userdata, or the same collectable object
    }
}


// 0x00215ff0 FUN_00215ff0 (103 B): equivalent/0x00215ff0.cpp
// sym: _FUN_00215ff0 @ac752779859e @w2a740fbda35f
// STATUS: equivalent (tools/equiv.py level 3: 2576 inputs, branch coverage 8/8)
// luaO_str2d: a whole string (trailing spaces allowed) as a number.
extern "C" int __cdecl FUN_00215ff0(const char* str, float* out) {
    const char* end = str;
    float value = (float)FUN_003472cb(str, &end);
    if (end != str) {
        while (_isspace((unsigned char)*end))
            end++;
        if (*end == 0) {
            *out = value;
            return 1;
        }
    }
    return 0;
}


// 0x00216060 FUN_00216060 (82 B): equivalent/0x00216060.cpp
// sym: _FUN_00216060 @fe8ef7391c0d @w3c251d931e5b
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 4/4)
// pushstr: push the string str (luaO_pushvfstring's helper).
// equiv-conv: FUN_00216060 esi edx
extern "C" void __cdecl FUN_00216060(LuaVMState* L, const char* str) {
    const char* p = str;
    while (*p)
        ++p;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)FUN_00219430(L, str, (unsigned int)(p - str));
    o->tt = LUAVM_TSTRING;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
}


// 0x002160c0 FUN_002160c0 (500 B): equivalent/0x002160c0.cpp
// sym: _FUN_002160c0 @d0fa77a1b057 @w32ea8d3793bd
// STATUS: equivalent (tools/equiv.py level 3: 2297 inputs, branch coverage 18/18)
// luaO_pushvfstring: fmt supports %s %c %d %f %%, the arguments come from the va_list pointer
// (4-byte slots on the 32-bit builds; va_arg over the 64-bit builds' 8-byte slots, HULK_PTR64).
// equiv-conv: FUN_00216060 esi edx
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp) {
    struct Frame {
        char buff[4];
        char* ap2;  // second copy of the va_list cursor (minus 8) that the original keeps in this slot
        const char* e;
        int n;
    } f;

    f.n = 1;
    FUN_00216060(L, "");
    f.e = strchr(fmt, '%');
    if (f.e != 0) {
        f.ap2 = argp - 8;
        while (f.e != 0) {
            LuaVMTObject* o = L->top;
            LuaVMString* ts = FUN_00219430(L, fmt, (unsigned int)(f.e - fmt));
            o->value.gc = (LuaVMGCObject*)ts;
            o->tt = LUAVM_TSTRING;
            if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
                FUN_00215460(L, 1);
            L->top++;
            LuaVMTObject* slot = L->top;
            switch (f.e[1]) {
            case 's': {
#if defined(HULK_PTR64)
                const char* s = __builtin_va_arg(argp, const char*);
#else
                const char* s = *(const char**)argp;
                argp += 4;
                f.ap2 += 4;
#endif
                FUN_00216060(L, s);
                break;
            }
            case 'c': {
                char buff[2];
#if defined(HULK_PTR64)
                buff[0] = (char)__builtin_va_arg(argp, int);
#else
                buff[0] = (char)*(int*)argp;
                argp += 4;
                f.ap2 += 4;
#endif
                buff[1] = 0;
                FUN_00216060(L, buff);
                break;
            }
            case 'd': {
#if defined(HULK_PTR64)
                slot->value.n = (hulk_freg)__builtin_va_arg(argp, int);
#else
                slot->value.n = (hulk_freg)*(int*)argp;
                argp += 4;
                f.ap2 += 4;
#endif
                slot->tt = LUAVM_TNUMBER;
                if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
                    FUN_00215460(L, 1);
                L->top++;
                break;
            }
            case 'f': {
#if defined(HULK_PTR64)
                slot->value.n = (hulk_freg)__builtin_va_arg(argp, double);
#else
                slot->value.n = (hulk_freg)*(double*)(f.ap2 + 8);
                argp += 8;
                f.ap2 += 8;
#endif
                slot->tt = LUAVM_TNUMBER;
                if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
                    FUN_00215460(L, 1);
                L->top++;
                break;
            }
            case '%':
                FUN_00216060(L, "%");
                break;
            default: {
                f.buff[0] = '%';
                f.buff[1] = f.e[1];
                f.buff[2] = 0;
                LuaVMString* ds = FUN_00219430(L, f.buff, (unsigned int)strlen_inline(f.buff));
                slot->value.gc = (LuaVMGCObject*)ds;
                slot->tt = LUAVM_TSTRING;
                if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
                    FUN_00215460(L, 1);
                L->top++;
                break;
            }
            }
            f.n += 2;
            fmt = f.e + 2;
            f.e = strchr(fmt, '%');
        }
    }
    FUN_00216060(L, fmt);
    FUN_00217f20(L, f.n + 1, (int)(L->top - L->base) - 1);
    L->top -= f.n;
    return LUAVM_GETSTR(L->top[-1].value.gc);
}


// 0x00216320 FUN_00216320 (24 B): matches/0x00216320.cpp
// sym: _FUN_00216320
// luaO_pushfstring.
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    return FUN_002160c0(L, fmt, args);
#else
    return FUN_002160c0(L, fmt, (char*)(&fmt + 1));
#endif
}


// 0x00216340 FUN_00216340 (334 B): equivalent/0x00216340.cpp
// sym: _FUN_00216340 @639aaf730ed2 @wf84fe6394228
// STATUS: equivalent (tools/equiv.py level 3: 3108 inputs, branch coverage 25/26, incomplete)
// luaO_chunkid: a printable chunk id for error messages.
extern "C" void __cdecl FUN_00216340(char *out, const char *source, int bufflen)
{
    if (*source == '=') {
        strncpy(out, source + 1, bufflen);
        out[bufflen - 1] = '\0';
        return;
    }
    if (*source == '@') {
        source++;
        int room = bufflen - 8;
        hulk_intptr l = strlen(source);
        *out = '\0';
        if (l > room) {
            source += l - room;
            strcat(out, "...");
        }
        strcat(out, source);
        return;
    }
    int len = strcspn(source, "\n");
    int room = bufflen - 17;
    if (len > room)
        len = room;
    strcpy(out, "[string \"");
    if (source[len] != '\0') {
        strncat(out, source, len);
        strcat(out, "...");
    } else {
        strcat(out, source);
    }
    strcat(out, "\"]");
}

} // namespace fn_f19d9cff
