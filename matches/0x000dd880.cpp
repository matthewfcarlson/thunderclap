#include "gen/global.h"

class IDollyControllerState_dd880 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual float vfunc_5(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};

float ControllerState::vfunc_5(int index) {
    return (*(float * *)&this->f_10)[index];
}
