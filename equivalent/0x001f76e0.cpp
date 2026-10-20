// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CEffectManager,int,const_char_*,math::Vector>::vfunc_2 @ 0x001f76e0
#include "gen/global.h"

namespace math { struct Vector_1f76e0 { float x, y, z; }; }
struct CEffectManager_1f76e0 {
    int FUN_001f76e0(const char *, math::Vector_1f76e0);
};
struct EffectArguments {
    const char *name;
    math::Vector_1f76e0 position;
};
struct Function_1f76e0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method2<CEffectManager, int, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CEffectManager_1f76e0 * manager = (CEffectManager_1f76e0 *)__p0; const EffectArguments * args = (const EffectArguments *)__p1; int * result = (int *)__p2;

    int value = (manager->*(*(int (CEffectManager_1f76e0::**)(const char *, math::Vector_1f76e0))&this->f_1c))(args->name, args->position);
    if (result) *result = value;
}
