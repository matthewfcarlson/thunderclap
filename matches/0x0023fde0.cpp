#include "compat/ptr.h"
typedef unsigned short ushort;
extern int Fmt(char* buf, int n, const char* fmt, char* va);
extern "C" void __cdecl FUN_0023fa40(int *, char *, unsigned int, int);
struct Out_23fde0 {
    int p;
    ushort flag;
    ushort pad;
    ushort len;
};
Out_23fde0* Fn(Out_23fde0* out, int x, const char* fmt, ...) {
    char buf[0x1000];
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
#else
    char* va = (char*)&fmt + 4;
#endif
    int n = Fmt(buf, 0x1000, fmt, va);
    out->len = (ushort)n;
    buf[0xfff] = 0;
    out->flag = 2;
    int tmp;
    FUN_0023fa40(&tmp, buf, (unsigned)n, n);
    out->p = tmp;
    return out;
}
