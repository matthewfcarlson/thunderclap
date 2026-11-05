#include "compat/ptr.h"
struct A_1c59d0 {
    char pad[8];
};
struct B_1c59d0 {
    int F(int);
};
struct X_1c59d0 : A_1c59d0, B_1c59d0 {
    int G(hulk_intptr);
};
int X_1c59d0::G(hulk_intptr a0) {
    return B_1c59d0::F(a0);
}