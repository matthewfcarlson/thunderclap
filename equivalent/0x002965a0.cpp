// STATUS: equivalent (tools/equiv.py level 3: 18240 inputs, branch coverage 6/6)
// pure3d::scenegraph::BranchNode::vfunc_6 @ 0x002965a0
#include "compat/ptr.h"
#include "gen/pure3d.h"

namespace pure3d { namespace scenegraph {
struct Node_2965a0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(void*, void*);
};

}}
void pure3d::scenegraph::BranchNode::vfunc_6(hulk_intptr __p0, hulk_intptr __p1) { void * a = (void *)__p0; void * b = (void *)__p1;

    if (!((*(char (*)[20])&this->f_04)[12] & 1)) {
        for (unsigned int i = 0; i < this->f_18; ++i)
            (*(Node_2965a0 ** *)&this->f_1c)[i]->vfunc_6(a,b);
    }
}
