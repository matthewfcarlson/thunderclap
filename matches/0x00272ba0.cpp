#include "compat/ptr.h"
struct C_272ba0 {
    void g(int);
};
struct D {
    char pad[0x14];
    C_272ba0 c;
    void f(hulk_intptr);
};
void D::f(hulk_intptr a0) {
    c.g(a0);
}