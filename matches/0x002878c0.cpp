#include "gen/pure3d.h"

struct Arg_2878c0 {
    char pad[0x1c];
    int tag;
    char pad2[8];
    int count;
};

bool pure3d::PoseAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && ((Arg_2878c0*)p)->count > 0)
        return ((Arg_2878c0*)p)->tag == 0x4e525450;
    return false;
}
