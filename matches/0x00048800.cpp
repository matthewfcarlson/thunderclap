// Same code shape as 0x00048590 (propagated; names are from that function)
#include "gen/global.h"

bool CAxisDownCondition::vfunc_10(void* __p0, int __p1) { int * p = (int *)__p0; int * out = (int *)__p1;

    switch (*p) {
    case 1:
        *out = 0;
        return true;
    case 2:
        *out = p[1];
        return true;
    default:
        return false;
    }
}
