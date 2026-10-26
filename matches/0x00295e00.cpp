#include "gen/pure3d.h"
#include "decls/data/engine/pure3d/scenegraph.h"


void* pure3d::scenegraph::Node::vfunc_16() {
    if ((*(pure3d::scenegraph::Node * *)&this->f_14))
        return (void*)((*(pure3d::scenegraph::Node * *)&this->f_14)->vfunc_16());
    return (void*)(((float*)&DAT_004c9f38));
}
