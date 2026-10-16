#include "gen/pure3d.h"

class Helper_297080 {
  public:
    int run(pure3d::scenegraph::DrawableNode*);
};
extern void* __cdecl alloc(int);

void* pure3d::scenegraph::DrawableNode::vfunc_4() {
    void* p = alloc(0x20);
    if (p)
        return (void*)(((Helper_297080*)p)->run(this));
    return (void*)(0);
}
