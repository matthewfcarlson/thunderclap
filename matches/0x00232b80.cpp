#include "compat/ptr.h"
struct B_232b80 {
    int f();
};
struct A_232b80 {
    int g(int, hulk_intptr, int, int);
    int target(int, hulk_intptr, int);
};
int A_232b80::target(int a, hulk_intptr b, int c) {
    B_232b80* x = (B_232b80*)b;
    int r = x->f();
    return g(a, b, r, c);
}