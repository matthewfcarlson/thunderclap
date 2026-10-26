#include "compat/ptr.h"
#include "gen/global.h"

class Obj_e1440 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(int, int);
};

void FEAnimation::vfunc_4(hulk_intptr ) {
    if ((*(Obj_e1440 * *)&this->f_0c))
        (*(Obj_e1440 * *)&this->f_0c)->g(0, 0);
}
