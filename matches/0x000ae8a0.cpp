// Same code shape as 0x000244a0 (propagated; names are from that function)
#include "compat/ptr.h"
struct CController_ae8a0 {
    void g(int);
};
struct X_ae8a0 {
    char pad[4];
    CController_ae8a0* p;
    void f(hulk_intptr);
};
void X_ae8a0::f(hulk_intptr a0) {
    p->g(a0);
}