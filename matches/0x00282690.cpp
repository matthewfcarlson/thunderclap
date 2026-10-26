#include "compat/ptr.h"
#include "gen/pure3d.h"

class Obj_282690 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class Helper_282690 {
  public:
    void helper(void*, int, int, int);
};

void pure3d::prop::CMotionTrailQueue::vfunc_8(hulk_intptr a, int b) {
    for (int i = 0; i < 6; ++i) {
        if ((*(char * *)&this->f_5c)[i * 8 + 4]) {
            if (a) {
                ((Helper_282690*)a)->helper(this, i, 0, b);
            } else {
                Obj_282690* o = *(Obj_282690**)((*(char * *)&this->f_48) + i * 16);
                o->f6();
            }
        }
    }
}
