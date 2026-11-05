#include "compat/ptr.h"
struct Y_244a0 {
    void g(int);
};
struct X_244a0 {
    char pad[4];
    Y_244a0* p;
    void f(hulk_intptr);
};
void X_244a0::f(hulk_intptr a0) {
    p->g(a0);
}