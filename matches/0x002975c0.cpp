#include "gen/pure3d.h"

class Other_2975c0 {
  public:
    int helper(pure3d::scenegraph::VisibilityNode*);
};
extern void* alloc(int);

void* pure3d::scenegraph::VisibilityNode::vfunc_4() {
    void* p = alloc(0x30);
    if (p)
        return (void*)(((Other_2975c0*)p)->helper(this));
    return (void*)(0);
}
