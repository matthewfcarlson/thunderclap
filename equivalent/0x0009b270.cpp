// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 @ 0x0009b270
#include "gen/global.h"

namespace math { struct Vector_9b270 { float x, y, z; }; }
struct CCameraManager_9b270 { void FUN_0009b270(math::Vector_9b270, math::Vector_9b270); };
struct Function_9b270 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method2<CCameraManager, void,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9b270 * manager = (CCameraManager_9b270 *)__p0; const math::Vector_9b270 * args = (const math::Vector_9b270 *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CCameraManager_9b270::**)(math::Vector_9b270, math::Vector_9b270))&this->f_1c))(args[0], args[1]);
}
