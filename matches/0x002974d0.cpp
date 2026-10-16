#include "gen/pure3d.h"

class Helper_2974d0 {
  public:
    int call(pure3d::scenegraph::TransformNode*);
};
extern void* __cdecl alloc(int);

void* pure3d::scenegraph::TransformNode::vfunc_4() {
    void* p = alloc(0xb0);
    if (p)
        return (void*)(((Helper_2974d0*)p)->call(this));
    return (void*)(0);
}
