#include "gen/pure3d.h"

struct Param_2a7790 {
    char pad[0x1c];
    int tag;
    char pad2[8];
    int count;
};

bool pure3d::SceneGraphTransformAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && ((Param_2a7790*)p)->count > 0)
        return ((Param_2a7790*)p)->tag == 0x4e525453;
    return false;
}
