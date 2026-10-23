// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CGameFlowManager,math::Vector>::vfunc_2 @ 0x0008b1b0
#include "gen/global.h"

namespace math { struct Vector_8b1b0 { float x, y, z; }; }
struct CGameFlowManager_8b1b0 { math::Vector_8b1b0* run(math::Vector_8b1b0* result); };
struct Function_8b1b0 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Closure0<CGameFlowManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused1 = (void *)__p0; void * unused2 = (void *)__p1; math::Vector_8b1b0 * output = (math::Vector_8b1b0 *)__p2;

    math::Vector_8b1b0 temporary;
    math::Vector_8b1b0 result = ((*(CGameFlowManager_8b1b0 * *)&this->f_20)->*(*(math::Vector_8b1b0 *(CGameFlowManager_8b1b0::**)(math::Vector_8b1b0 *))&this->f_1c))(&temporary)[0];
    if (output) *output = result;
}
