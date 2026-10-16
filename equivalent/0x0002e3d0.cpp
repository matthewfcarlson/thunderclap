// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method3<CActorManager,bool,const_char_*,math::Vector,math::Vector>::vfunc_2 @ 0x0002e3d0
#include "gen/global.h"

namespace math {
struct Vector_2e3d0 {
    float x, y, z;
};
}
class CActorManager_2e3d0 {
public:
    bool Dummy(const char* name, math::Vector_2e3d0 a, math::Vector_2e3d0 b);
};
typedef bool (CActorManager_2e3d0::*ActorFn_2e3d0)(const char* name, math::Vector_2e3d0 a, math::Vector_2e3d0 b);
struct Args_2e3d0 {
    const char* name;
    math::Vector_2e3d0 a;
    math::Vector_2e3d0 b;
};
class Function_2e3d0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CActorManager, bool, const char *,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e3d0 * owner = (CActorManager_2e3d0 *)__p0; Args_2e3d0 * args = (Args_2e3d0 *)__p1; bool * result = (bool *)__p2;

    bool r = (owner->*(*(ActorFn_2e3d0 *)&this->f_1c))(args->name, args->a, args->b);
    if (result)
        *result = r;
}
