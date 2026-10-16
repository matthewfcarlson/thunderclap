#include "gen/global.h"

class FEDoAction_e1830 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
};
class Other_e1830 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void vfunc_3();
};

void FEDoAnimation::vfunc_5() {
    if ((*(Other_e1830 * *)&this->f_34))
        (*(Other_e1830 * *)&this->f_34)->vfunc_3();
}
