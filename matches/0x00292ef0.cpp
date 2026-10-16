#include "gen/pure3d.h"

extern "C" char DAT_004d4143[];

bool pure3d::CameraAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p != 0) {
        if (*(int*)((char*)p + 0x28) > 0) {
            return *(int*)((char*)p + 0x1c) == ((int)DAT_004d4143);
        }
    }
    return false;
}
