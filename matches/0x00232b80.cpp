#include "compat/ptr.h"
#include "gen/owners.h"
struct B_232b80 {
    int f();
};
int owners::A_232b80::FUN_00232b80(hulk_intptr a, hulk_intptr b, int c) {
    B_232b80* x = (B_232b80*)((hulk_intptr)b);
    int r = x->f();
    return g(((int)a), ((hulk_intptr)b), r, c);
}