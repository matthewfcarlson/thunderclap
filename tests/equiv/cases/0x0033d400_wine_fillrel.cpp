// STATUS: equivalent (tools/equiv.py level 3: 2000 inputs, branch coverage 30/30)
// FUN_0033d400 @ 0x0033d400
// checked with equiv.py --time-budget 3600 (at the defaults most inputs hit the time budget)
// cl-flags: /GS
extern "C" int __cdecl isdigit(int c);
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);

// lstrlib str_format
#include "decls/data/lua.h"

extern "C" const char *__cdecl FUN_00339df0(LuaVMState *L, int narg, unsigned int *len);
extern "C" void __cdecl FUN_00339630(LuaVMState *L, LuaVMLBuffer *B);
extern "C" char *__cdecl FUN_00339470(LuaVMLBuffer *B);
// equiv-conv: FUN_0033d310 ebx stack stack stack
const char *FUN_0033d310(const char *strfrmt, LuaVMState *L, char *form, int *hasprecision);
extern "C" float __cdecl FUN_00339ec0(LuaVMState *L, int narg);
extern "C" int __cdecl FUN_00339f70(LuaVMState *L, int narg);
// equiv-conv: FUN_0033d1c0 esi edx ecx
void FUN_0033d1c0(LuaVMLBuffer *b, LuaVMState *L, int arg);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00339590(LuaVMLBuffer *B);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer *B, const char *s, unsigned int l);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer *B);
extern "C" int __cdecl FUN_00338e20(LuaVMState *L, const char *fmt, ...);

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
