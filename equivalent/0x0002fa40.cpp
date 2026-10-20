// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,float>::vfunc_2 @ 0x0002fa40
#include "gen/global.h"

struct CActorManager_2fa40 { bool FUN_00000000(const char *, float); };
struct CallArgs { const char *name; float value; };

template <> void Closure2<CActorManager, bool, const char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; CallArgs * args = (CallArgs *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2fa40 * *)&this->f_20)->*(*(bool (CActorManager_2fa40::**)(const char *, float))&this->f_1c))(args->name, args->value);
    if (result) *result = value;
}
