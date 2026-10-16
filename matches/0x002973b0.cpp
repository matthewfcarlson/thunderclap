#include "gen/pure3d.h"

struct Helper_2973b0 {
    int f(pure3d::scenegraph::BranchNode*);
};
extern "C" void* __cdecl thunk_FUN_0008d690(int);

void* pure3d::scenegraph::BranchNode::vfunc_4() {
    Helper_2973b0* p = (Helper_2973b0*)thunk_FUN_0008d690(0x28);
    if (p)
        return (void*)(p->f(this));
    return (void*)(0);
}
