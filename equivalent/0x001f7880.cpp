// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CEffectManager,bool,int,math::Vector>::vfunc_2 @ 0x001f7880
#include "gen/global.h"

namespace math { struct Vector_1f7880 { float x, y, z; }; }
struct CEffectManager_1f7880 { bool effect(int id, math::Vector_1f7880 position); };
struct Arguments { int id; math::Vector_1f7880 position; };
struct Function_1f7880 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };

template <> void Method2<CEffectManager, bool, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f7880 * object = (CEffectManager_1f7880 *)__p0; Arguments * args = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = (object->*(*(bool (CEffectManager_1f7880::**)(int, math::Vector_1f7880))&this->f_1c))(args->id, args->position);
    if (result) *result = value;
}
