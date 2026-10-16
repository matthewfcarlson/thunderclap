#include "gen/pure3d.h"

bool pure3d::CompDrawVisibilityAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p != 0) {
        int* q = (int*)p;
        if (q[10] > 0) {
            return q[7] == 0x53495650;
        }
    }
    return false;
}
