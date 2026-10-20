#include "compat/ptr.h"
extern "C" char DAT_004193ec[];
struct Sub_180fc0 {
    void A();
    void B();
};
struct X_180fc0 {
    int* v;
    char pad[0x64];
    void f();
    void C();
};
void X_180fc0::f() {
    v = (int*)((hulk_intptr)DAT_004193ec);
    ((Sub_180fc0*)((char*)this + 0x78))->A();
    ((Sub_180fc0*)((char*)this + 0x68))->B();
    C();
}
