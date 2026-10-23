// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CCameraManager,math::Vector>::vfunc_2 @ 0x0009cc60
#include "gen/global.h"

namespace math { struct Vector_9cc60 { float x,y,z; }; }
struct CCameraManager_9cc60 { math::Vector_9cc60 *FUN_0009cc60(math::Vector_9cc60 *out); };

template <> void Closure0<CCameraManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused0 = (int)__p0; int unused1 = (int)__p1; math::Vector_9cc60 * result = (math::Vector_9cc60 *)__p2;

    math::Vector_9cc60 temporary;
    math::Vector_9cc60 *value = ((*(CCameraManager_9cc60 * *)&this->f_20)->*(*(math::Vector_9cc60 *(CCameraManager_9cc60::**)(math::Vector_9cc60 *))&this->f_1c))(&temporary);
    math::Vector_9cc60 copy = *value;
    if (result) *result = copy;
}
