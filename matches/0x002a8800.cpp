#include "gen/pure3d.h"

struct Obj_2a8800 {
    char pad[0x1c];
    int tag;
    char pad2[8];
    int count;
};

bool pure3d::LightAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && ((Obj_2a8800*)p)->count > 0)
        return ((Obj_2a8800*)p)->tag == 0x4554494c;
    return false;
}
