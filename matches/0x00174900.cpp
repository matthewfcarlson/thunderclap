#include "compat/ptr.h"
extern "C" char DAT_00417ea0[];
extern "C" void _ReadWriteBarrier();
class Action {
  public:
    virtual void A();
    virtual void B();
};
class Base_174900 {
  public:
    void Finish();
};
class PushOutAction : public Base_174900 {
  public:
    volatile int vptr;
    char pad[0x18];
    int* m1;
    Action* m2;
    void Clear();
};
void PushOutAction::Clear() {
    vptr = ((hulk_intptr)DAT_00417ea0);
    _ReadWriteBarrier();
    if (m2) {
        m2->B();
        m2 = 0;
    }
    if (m1)
        m1 = 0;
    Finish();
}