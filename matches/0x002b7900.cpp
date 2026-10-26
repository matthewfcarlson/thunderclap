#include "compat/ptr.h"
#include "gen/pure3d.h"

class Ref_2b7900 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class H {
  public:
    void one(int);
    void two(void*, void*);
};
struct PolySkin_nv_2b7900 {
    void last(hulk_intptr, int);
};

void pure3d::PolySkin::vfunc_8(hulk_intptr a, int b) {
    if ((*(Ref_2b7900 * *)&this->f_6c))
        (*(Ref_2b7900 * *)&this->f_6c)->f6(0, 1);
    if ((*(Ref_2b7900 * *)&this->f_70))
        (*(Ref_2b7900 * *)&this->f_70)->f6(0, 1);
    ((H*)(*(void * *)&this->f_60))->one(0);
    ((H*)(*(H * *)&this->f_58))->two((*(void * *)&this->f_5c), (*(void * *)&this->f_60));
    ((PolySkin_nv_2b7900*)this)->last(a, b);
}
