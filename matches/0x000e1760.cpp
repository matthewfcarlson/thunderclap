#include "gen/global.h"

class FEDoAction_e1760 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class Obj_e1760 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(float);
    virtual float g();
};
struct FEDoAnimation_nv_e1760 {
    void helper();
};

void FEDoAnimation::vfunc_3() {
    if ((*(Obj_e1760 * *)&this->f_34)) {
        if (this->f_3c < 0.0f) {
            this->f_3c = (*(Obj_e1760 * *)&this->f_34)->g();
            ((FEDoAnimation_nv_e1760*)this)->helper();
            return;
        }
        if (this->f_3c > -1.0f)
            (*(Obj_e1760 * *)&this->f_34)->e(this->f_3c);
        else
            (*(Obj_e1760 * *)&this->f_34)->e(0.0f);
    }
}
