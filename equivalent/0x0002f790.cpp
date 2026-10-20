// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,float,float,float>::vfunc_2 @ 0x0002f790
#include "gen/global.h"

struct CActorManager_2f790 { void FUN_00000000(const char *, float, float, float); };
struct ActorArgs { const char *name; float a; float b; float c; };

template <> void Closure4<CActorManager, void, const char *, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; ActorArgs * args = (ActorArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CActorManager_2f790 * *)&this->f_20)->*(*(void (CActorManager_2f790::**)(const char *, float, float, float))&this->f_1c))(args->name, args->a, args->b, args->c);
}
