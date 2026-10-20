#include "compat/ptr.h"
struct S_1e1150 {
    int a, b, c, d;
    short e, f;
};
struct T_1e1150 {
    int a, b, c, d, e;
};
extern "C" void __cdecl FUN_001e1040(S_1e1150*, int, hulk_intptr, T_1e1150);
extern "C" void __cdecl FUN_001e1150(S_1e1150* src, S_1e1150* end, S_1e1150* dst, T_1e1150 t) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    FUN_001e1040(src, 0, end - src, t);
}
