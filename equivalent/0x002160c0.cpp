// STATUS: equivalent (tools/equiv.py level 3: 2297 inputs, branch coverage 18/18)
// luaO_pushvfstring: fmt supports %s %c %d %f %%, the arguments come from the va_list pointer
// (4-byte slots on the 32-bit builds; va_arg over the 64-bit builds' 8-byte slots, HULK_PTR64).
#include "decls/data/lua.h"

extern "C" char* __cdecl strchr(const char*, int);
static inline int strlen_inline(const char* s) {
    const char* p = s;
    while (*p)
        p++;
    return (int)(p - s);
}

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00217f20(LuaVMState* L, int total, int last);
// equiv-conv: FUN_00216060 esi edx
extern "C" void __cdecl FUN_00216060(LuaVMState* L, const char* str);

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
