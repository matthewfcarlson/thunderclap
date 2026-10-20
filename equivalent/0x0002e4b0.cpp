// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x0002e4b0
#include "gen/global.h"

namespace math { struct Vector_2e4b0 { float x,y,z; }; }
class CActorManager_2e4b0 {};
struct Arguments { const char* text; math::Vector_2e4b0 position; };
class Function_2e4b0 { public: virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Method2<CActorManager, bool, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e4b0 * actor = (CActorManager_2e4b0 *)__p0; const Arguments * args = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = (actor->*(*(bool (CActorManager_2e4b0::**)(const char *, math::Vector_2e4b0))&this->f_1c))(args->text, args->position);
    if (result) *result = value;
}
