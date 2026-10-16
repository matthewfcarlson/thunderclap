#include "gen/core.h"

class Foo_2773f0 {
  public:
    virtual void f();
};

void core::CementLibrary::vfunc_5(void* __p0, int param_3) { Foo_2773f0 * param_2 = (Foo_2773f0 *)__p0;

    (*(Foo_2773f0 * *)&this->f_6c) = param_2;
    this->f_70 = param_3;
    param_2->f();
}
