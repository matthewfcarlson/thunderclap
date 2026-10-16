#include "gen/global.h"

class FELayout_e9010 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class Obj_e9010 {
  public:
    void run(int, int, int);
};

void VScroll::vfunc_10(int param_2) {
    Obj_e9010* p = (*(Obj_e9010 * *)&this->f_244);
    if (p && param_2 == 0)
        p->run(0, -1, -1);
}
