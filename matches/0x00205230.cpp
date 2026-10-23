#include "gen/global.h"

struct CWorldStreamManager_205230 {};

template <> void Method3<CWorldStreamManager, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205230 * manager = (CWorldStreamManager_205230 *)__p0; const float * args = (const float *)__p1; int * result = (int *)__p2;

    int (CWorldStreamManager_205230::*fn)(float, float, float) = (*(int (CWorldStreamManager_205230::**)(float, float, float))&this->f_1c);
    float a = args[0], b = args[1], c = args[2];
    int value = (manager->*fn)(a, b, c);
    if (result)
        *result = value;
}
