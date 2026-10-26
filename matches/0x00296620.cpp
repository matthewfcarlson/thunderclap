#include "compat/ptr.h"
#include "gen/pure3d.h"

class Obj_296620 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int, int);
};

void pure3d::scenegraph::BranchNode::vfunc_8(hulk_intptr a, int b, int c) {
    if (((*(unsigned int *)&this->f_10) & 1) == 0) {
        for (unsigned int i = 0; i < this->f_18; ++i)
            (*(Obj_296620 ** *)&this->f_1c)[i]->f8(a, b, c);
        (*(unsigned int *)&this->f_10) &= 0xfffffff9;
    }
}
