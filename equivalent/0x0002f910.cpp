// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure3<CActorManager,bool,const_char_*,float,float>::vfunc_2 @ 0x0002f910
#include "gen/global.h"

struct CActorManager_2f910 { bool FUN_0002f910(const char *, float, float); };
struct Arguments { const char *name; float first; float second; };

template <> void Closure3<CActorManager, bool, const char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2f910 * *)&this->f_20)->*(*(bool (CActorManager_2f910::**)(const char *, float, float))&this->f_1c))(args->name, args->first, args->second);
    if (result) *result = value;
}
