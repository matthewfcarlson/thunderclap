#include "gen/core.h"

class IControllerOutputPoint_268c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(float);
};

void core::ControllerOutputPointXBox::vfunc_6(float x) {
    if (x < 0.0f)
        this->f_0c = 0.0f;
    else if (x > 1.0f)
        this->f_0c = 1.0f;
    else
        this->f_0c = x;
}
