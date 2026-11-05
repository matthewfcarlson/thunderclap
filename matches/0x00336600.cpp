#include "compat/ptr.h"
typedef unsigned int U_336600;
struct Inner_336600 {
    U_336600 call(U_336600);
};
struct Obj_336600 {
    int pad;
    Inner_336600* p;
    U_336600 second(U_336600, U_336600, U_336600, U_336600);
    U_336600 target(hulk_uintptr, hulk_uintptr, hulk_uintptr, hulk_uintptr);
};
U_336600 Obj_336600::target(hulk_uintptr a, hulk_uintptr b, hulk_uintptr c, hulk_uintptr d) {
    return second(p->call(a), b, c, d);
}