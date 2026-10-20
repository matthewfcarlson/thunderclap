// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,int>::vfunc_2 @ 0x0002f580
#include "gen/global.h"

struct CActorManager_2f580 { bool callback(const char *, int); };
struct ActorArgs { const char *name; int value; };

template <> void Closure2<CActorManager, bool, const char *, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const ActorArgs * args = (const ActorArgs *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2f580 * *)&this->f_20)->*(*(bool (CActorManager_2f580::**)(const char *, int))&this->f_1c))(args->name, args->value);
    if (result) *result = value;
}
