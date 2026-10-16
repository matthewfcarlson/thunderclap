#include "gen/pure3d.h"

bool pure3d::SceneGraphVisibilityAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && *(int*)((char*)p + 0x28) > 0)
        return *(int*)((char*)p + 0x1c) == 0x53495653;
    return false;
}
