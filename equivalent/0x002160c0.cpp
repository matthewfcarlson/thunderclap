// STATUS: equivalent (tools/equiv.py level 3: 146 inputs, branch coverage 18/18)
// FUN_002160c0 @ 0x002160c0
extern "C" char *__cdecl strchr(const char *, int);
extern "C" unsigned int __cdecl strlen(const char *);

struct TString {
    char hdr[0x10];
    char str[1];
};

struct TValue {
    int tt;
    union {
        TString *ts;
        float n;
    } value;
};

struct lua_State {
    char pad0[8];
    TValue *top;
    TValue *base;
    char pad10[8];
    TValue *stack_last;
};

TString *__cdecl FUN_00219430(lua_State *L, const char *s, unsigned int len);
void __cdecl FUN_00215460(lua_State *L, int n);
void __cdecl FUN_00217f20(lua_State *L, int total, int last);
// equiv-conv: FUN_00216060 esi edx
void FUN_00216060(lua_State *L, const char *s);

// Lua 5.0 luaO_pushvfstring: fmt supports %s %c %d %f %%, arguments come from the va_list pointer.
const char *FUN_002160c0(lua_State *L, const char *fmt, char *argp)
{
    struct Frame {
        char buff[4];
        char *ap2;      // second copy of the va_list cursor (minus 8) that the original keeps in this slot
        const char *e;
        int n;
    } f;

    f.n = 1;
    FUN_00216060(L, "");
    f.e = strchr(fmt, '%');
    if (f.e != 0) {
        f.ap2 = argp - 8;
        while (f.e != 0) {
            TValue *o = L->top;
            TString *ts = FUN_00219430(L, fmt, f.e - fmt);
            o->value.ts = ts;
            o->tt = 4;
            if ((char *)L->stack_last - (char *)L->top <= 8)
                FUN_00215460(L, 1);
            L->top++;
            TValue *slot = L->top;
            switch (f.e[1]) {
            case 's': {
                const char *s = *(const char **)argp;
                argp += 4;
                f.ap2 += 4;
                FUN_00216060(L, s);
                break;
            }
            case 'c': {
                char buff[2];
                buff[0] = (char)*(int *)argp;
                argp += 4;
                f.ap2 += 4;
                buff[1] = 0;
                FUN_00216060(L, buff);
                break;
            }
            case 'd': {
                slot->value.n = (float)*(int *)argp;
                argp += 4;
                f.ap2 += 4;
                slot->tt = 3;
                if ((char *)L->stack_last - (char *)L->top <= 8)
                    FUN_00215460(L, 1);
                L->top++;
                break;
            }
            case 'f': {
                slot->value.n = (float)*(double *)(f.ap2 + 8);
                argp += 8;
                f.ap2 += 8;
                slot->tt = 3;
                if ((char *)L->stack_last - (char *)L->top <= 8)
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
                TString *ds = FUN_00219430(L, f.buff, strlen(f.buff));
                slot->value.ts = ds;
                slot->tt = 4;
                if ((char *)L->stack_last - (char *)L->top <= 8)
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
    return L->top[-1].value.ts->str;
}
