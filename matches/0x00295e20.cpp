#include "gen/pure3d.h"

void* pure3d::scenegraph::Node::vfunc_17() {
    this->f_10 &= ~4;
    if ((*(pure3d::scenegraph::Node * *)&this->f_14))
        return (void*)((*(pure3d::scenegraph::Node * *)&this->f_14)->vfunc_17());
    extern float one;
    return (void*)(&one);
}
