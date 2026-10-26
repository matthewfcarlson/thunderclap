#include "compat/ptr.h"
#include "gen/pure3d.h"

void pure3d::scenegraph::DrawableNode::vfunc_6(hulk_intptr x, hulk_intptr y) {
    if (!((*(unsigned char *)&this->f_10) & 1) && (*(void * *)&this->f_18))
        ((pure3d::scenegraph::DrawableNode*)(*(void * *)&this->f_18))->vfunc_6(x, y);
}
