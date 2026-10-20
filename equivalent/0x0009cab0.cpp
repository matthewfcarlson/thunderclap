// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 @ 0x0009cab0
#include "compat/ptr.h"
#include "gen/global.h"

namespace math { struct Vector_9cab0 { float x,y,z; }; }
struct CCameraManager_9cab0 { void FUN_0009cab0(math::Vector_9cab0, math::Vector_9cab0); };
struct VectorPair { math::Vector_9cab0 first, second; };

template <> void Closure2<CCameraManager, void,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused1 = (hulk_intptr)__p0; VectorPair * args = (VectorPair *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    ((*(CCameraManager_9cab0 * *)&this->f_20)->*(*(void (CCameraManager_9cab0::**)(math::Vector_9cab0, math::Vector_9cab0))&this->f_1c))(args->first, args->second);
}
