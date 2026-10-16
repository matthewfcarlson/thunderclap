#include "gen/core.h"

class Target_268760 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(unsigned int);
};

void core::ControllerXBox::vfunc_20(unsigned int a, unsigned int b) {
    (*(Target_268760 * *)&this->f_454)->f4(a / b + 2);
}
