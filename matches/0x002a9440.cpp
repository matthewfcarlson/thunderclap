#include "gen/pure3d.h"

struct Anim {
    char pad[0x1c];
    int type;
    char pad2[8];
    int count;
};

bool pure3d::TextureAnimationController::vfunc_26(void* __p0) { Anim * a = (Anim *)__p0;

    if (a && a->count > 0)
        return a->type == 0x584554;
    return false;
}
