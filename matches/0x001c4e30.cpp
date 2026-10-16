#include "gen/Render.h"

class ResultThing {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int f5();
};

void* Render::Object::vfunc_8() {
    if ((*(ResultThing * *)&this->f_10)->f5() == 4)
        return (void*)((*(ResultThing * *)&this->f_10));
    return (void*)(0);
}
