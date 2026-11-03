#include "gen/owners.h"
class B_86da0 {
  public:
    void a();
};
bool b80();
extern "C" void FUN_0008db90();
void thunk();
void f656a0();
class C_86da0 {
  public:
};
class A_86da0 {
  public:
    char pad[0x1c];
    B_86da0* x;
    char pad2[0x10];
    C_86da0* y;
    void tail();
    void run();
};
void A_86da0::run() {
    if (x)
        x->a();
    else {
        thunk();
        f656a0();
    }
    if (y)
        ((owners::Thing_1eb2a0 *)y)->FUN_001eb2a0(0, 0);
    if (x) {
        while (b80()) {
            FUN_0008db90();
            x->a();
        }
    }
    tail();
}