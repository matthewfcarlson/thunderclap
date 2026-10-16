// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 12/12)
// pure3d::scenegraph::BranchNode::vfunc_19 @ 0x002967a0
#include "gen/pure3d.h"

class Node_2967a0 {
public:
    virtual void v0();
    virtual void Release();
};

namespace pure3d {
namespace scenegraph {

}
}
void pure3d::scenegraph::BranchNode::vfunc_19(int __p0) { Node_2967a0 * child = (Node_2967a0 *)__p0;

    int i = (int)this->f_18 - 1;
    if (i < 0)
        return;
    Node_2967a0** list = (*(Node_2967a0 ** *)&this->f_1c);
    while (list[i] != child) {
        i--;
        if (i < 0)
            return;
    }
    if (list[i] != 0) {
        list[i]->Release();
        list[i] = 0;
    }
    for (unsigned int j = i + 1; j < this->f_18; j++) {
        (*(Node_2967a0 ** *)&this->f_1c)[j - 1] = (*(Node_2967a0 ** *)&this->f_1c)[j];
        (*(Node_2967a0 ** *)&this->f_1c)[j] = 0;
    }
    this->f_18--;
}
