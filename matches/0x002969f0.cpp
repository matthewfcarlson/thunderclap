#include "gen/pure3d.h"

class Obj_2969f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual bool f22();
};

bool pure3d::scenegraph::VisibilityNode::vfunc_7() {
    if (!((*(unsigned char *)&this->f_10) & 1) && (*(Obj_2969f0 * *)&this->f_2c) && !(*(Obj_2969f0 * *)&this->f_2c)->f22())
        return false;
    if (!((*(unsigned char *)&this->f_10) & 1)) {
        for (unsigned i = 0; i < this->f_18; ++i)
            if (!(*(Obj_2969f0 ** *)&this->f_1c)[i]->f7())
                return false;
    }
    return true;
}
