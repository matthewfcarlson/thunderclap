#include "gen/pure3d.h"

typedef unsigned int uint;
class Child_2965e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual bool f7();
};

bool pure3d::scenegraph::BranchNode::vfunc_7() {
    if (((*(unsigned char *)&this->f_10) & 1) == 0) {
        uint i = 0;
        if ((*(uint *)&this->f_18) > 0) {
            do {
                if (!(*(Child_2965e0 ** *)&this->f_1c)[i]->f7())
                    return false;
                ++i;
            } while (i < (*(uint *)&this->f_18));
        }
    }
    return true;
}
