// STATUS: equivalent (tools/equiv.py level 3: 16564 inputs, branch coverage 18/18)
// FUN_002160c0 @ 0x002160c0
#include "compat/ptr.h"
extern "C" char *__cdecl strchr(const char *, int);
static inline hulk_uintptr strlen_inline(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}

struct TString_2160c0 {
    char hdr[0x10];
    char str[1];
};

struct TValue_2160c0 {
    int tt;
    union {
        TString_2160c0 *ts;
        float n;
    } value;
};

struct lua_State_2160c0 {
    char pad0[8];
    TValue_2160c0 *top;
    TValue_2160c0 *base;
    char pad10[8];
    TValue_2160c0 *stack_last;
};

TString_2160c0 *__cdecl FUN_00219430(lua_State_2160c0 *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_00215460(void *, int);
extern "C" void __cdecl FUN_00217f20(void *, int, int);
// equiv-conv: FUN_00216060 esi edx
extern "C" void __cdecl FUN_00216060(void *, const char *);

// Lua 5.0 luaO_pushvfstring: fmt supports %s %c %d %f %%, arguments come from the va_list pointer.
extern "C" const char *FUN_002160c0(void *L, const char *fmt, char *argp)
{
    struct Frame {
        char buff[4];
        char *ap2;      // second copy of the va_list cursor (minus 8) that the original keeps in this slot
        const char *e;
        int n;
    } f;

    f.n = 1;
    FUN_00216060((lua_State_2160c0 *)((lua_State_2160c0 *)L), "");
    f.e = strchr(fmt, '%');
    if (f.e != 0) {
        f.ap2 = argp - 8;
        while (f.e != 0) {
            TValue_2160c0 *o = ((lua_State_2160c0 *)L)->top;
            TString_2160c0 *ts = FUN_00219430(((lua_State_2160c0 *)L), fmt, f.e - fmt);
            o->value.ts = ts;
            o->tt = 4;
            if ((char *)((lua_State_2160c0 *)L)->stack_last - (char *)((lua_State_2160c0 *)L)->top <= 8)
                FUN_00215460((lua_State_2160c0 *)((lua_State_2160c0 *)L), 1);
            ((lua_State_2160c0 *)L)->top++;
            TValue_2160c0 *slot = ((lua_State_2160c0 *)L)->top;
            switch (f.e[1]) {
            case 's': {
                const char *s = *(const char **)argp;
                argp += 4;
                f.ap2 += 4;
                FUN_00216060((lua_State_2160c0 *)((lua_State_2160c0 *)L), s);
                break;
            }
            case 'c': {
                char buff[2];
                buff[0] = (char)*(int *)argp;
                argp += 4;
                f.ap2 += 4;
                buff[1] = 0;
                FUN_00216060((lua_State_2160c0 *)((lua_State_2160c0 *)L), buff);
                break;
            }
            case 'd': {
                slot->value.n = (hulk_freg)*(int *)argp;
                argp += 4;
                f.ap2 += 4;
                slot->tt = 3;
                if ((char *)((lua_State_2160c0 *)L)->stack_last - (char *)((lua_State_2160c0 *)L)->top <= 8)
                    FUN_00215460((lua_State_2160c0 *)((lua_State_2160c0 *)L), 1);
                ((lua_State_2160c0 *)L)->top++;
                break;
            }
            case 'f': {
                slot->value.n = (hulk_freg)*(double *)(f.ap2 + 8);
                argp += 8;
                f.ap2 += 8;
                slot->tt = 3;
                if ((char *)((lua_State_2160c0 *)L)->stack_last - (char *)((lua_State_2160c0 *)L)->top <= 8)
                    FUN_00215460((lua_State_2160c0 *)((lua_State_2160c0 *)L), 1);
                ((lua_State_2160c0 *)L)->top++;
                break;
            }
            case '%':
                FUN_00216060((lua_State_2160c0 *)((lua_State_2160c0 *)L), "%");
                break;
            default: {
                f.buff[0] = '%';
                f.buff[1] = f.e[1];
                f.buff[2] = 0;
                TString_2160c0 *ds = FUN_00219430(((lua_State_2160c0 *)L), f.buff, strlen_inline(f.buff));
                slot->value.ts = ds;
                slot->tt = 4;
                if ((char *)((lua_State_2160c0 *)L)->stack_last - (char *)((lua_State_2160c0 *)L)->top <= 8)
                    FUN_00215460((lua_State_2160c0 *)((lua_State_2160c0 *)L), 1);
                ((lua_State_2160c0 *)L)->top++;
                break;
            }
            }
            f.n += 2;
            fmt = f.e + 2;
            f.e = strchr(fmt, '%');
        }
    }
    FUN_00216060((lua_State_2160c0 *)((lua_State_2160c0 *)L), fmt);
    FUN_00217f20((lua_State_2160c0 *)((lua_State_2160c0 *)L), f.n + 1, (int)(((lua_State_2160c0 *)L)->top - ((lua_State_2160c0 *)L)->base) - 1);
    ((lua_State_2160c0 *)L)->top -= f.n;
    return ((lua_State_2160c0 *)L)->top[-1].value.ts->str;
}
