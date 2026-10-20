#include "compat/ptr.h"
#include "gen/pure3d.h"

class Helper_2974d0 {
  public:
    hulk_intptr call(pure3d::scenegraph::TransformNode*);
};
extern void* __cdecl alloc(int);

void* pure3d::scenegraph::TransformNode::vfunc_4() {
    void* p = alloc(0xb0);
    if (p)
        return (void*)(((Helper_2974d0*)p)->call(this));
    return (void*)(0);
}
