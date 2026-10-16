#include "gen/pure3d.h"

extern float gOne_295e00;

void* pure3d::scenegraph::Node::vfunc_16() {
    if ((*(pure3d::scenegraph::Node * *)&this->f_14))
        return (void*)((*(pure3d::scenegraph::Node * *)&this->f_14)->vfunc_16());
    return (void*)(&gOne_295e00);
}
