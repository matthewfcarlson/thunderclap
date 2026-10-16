#include "gen/pure3d.h"

class Child_2960b0 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void vfunc_9();
};

void pure3d::scenegraph::DrawableNode::vfunc_9() {
    (*(unsigned int *)&this->f_10) &= 1;
    if ((*(Child_2960b0 * *)&this->f_18))
        (*(Child_2960b0 * *)&this->f_18)->vfunc_9();
}
