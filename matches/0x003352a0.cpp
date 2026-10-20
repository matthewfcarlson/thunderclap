#include "compat/ptr.h"
extern "C" char DAT_00434300[];
class X_3352a0 {
  public:
    virtual void f0();
    virtual void f1();
    char pad[8];
    int field;
    X_3352a0* Init();
};

X_3352a0* X_3352a0::Init() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00434300);
    field = 0;
    return this;
}
