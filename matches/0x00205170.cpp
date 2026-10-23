#include "gen/global.h"

struct CWorldStreamManager_205170 {
    bool FUN_00205170(float, float, float);
};

template <> void Method3<CWorldStreamManager, bool, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CWorldStreamManager_205170 * object = (CWorldStreamManager_205170 *)__p0; const float * args = (const float *)__p1; bool * result = (bool *)__p2;

    bool (CWorldStreamManager_205170::*fn)(float, float, float) = (*(bool (CWorldStreamManager_205170::**)(float, float, float))&this->f_1c);
    float a = args[0], b = args[1], c = args[2];
    bool value = (object->*fn)(a, b, c);
    if (result)
        *result = value;
}
