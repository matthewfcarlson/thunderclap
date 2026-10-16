#include "gen/pure3d.h"

extern "C" char DAT_00475142[];

bool pure3d::BillboardQuadGroupAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p) {
        unsigned int x = *(unsigned int*)((char*)p + 0x1c);
        int r = (x == ((int)DAT_00475142));
        return r != 0;
    }
    return false;
}
