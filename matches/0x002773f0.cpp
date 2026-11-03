#include "gen/core.h"

class Foo_2773f0 {
  public:
    virtual void f();
};

void core::CementLibrary::vfunc_5(void* __p0, int value) { Foo_2773f0 * object = (Foo_2773f0 *)__p0;

    (*(Foo_2773f0 * *)&this->f_6c) = object;
    this->f_70 = value;
    object->f();
}
