#include "gen/global.h"

bool CButtonUpCondition::vfunc_10(void* __p0, int __p1) { int * p = (int *)__p0; int * out = (int *)__p1;

    int n = *p;
    if (n != 0) {
        if (n != 3)
            return (bool)(false);
        *out = 0;
    } else {
        *out = p[1];
    }
    return (bool)(true);
}
