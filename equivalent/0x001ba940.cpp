// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CRenderManager,math::Vector>::vfunc_2 @ 0x001ba940
#include "gen/global.h"

namespace math { struct Vector_1ba940 { float x,y,z; }; }
struct CRenderManager_1ba940 {};
struct Function_1ba940 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(int, int, math::Vector_1ba940 *); };

template <> void Closure0<CRenderManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; math::Vector_1ba940 * result = (math::Vector_1ba940 *)__p2;

    math::Vector_1ba940 value = ((*(CRenderManager_1ba940 * *)&this->f_20)->*(*(math::Vector_1ba940 (CRenderManager_1ba940::**)())&this->f_1c))();
    if (result) *result = value;
}
