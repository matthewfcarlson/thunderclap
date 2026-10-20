// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,float>::vfunc_2 @ 0x0002f9a0
#include "gen/global.h"

struct CActorManager_2f9a0 { char placeholder; };
struct Args { const char* name; float first; float second; };

template <> void Closure3<CActorManager, void, const char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Args * args = (Args *)__p1; void * unused2 = (void *)__p2;

    ((*(CActorManager_2f9a0 * *)&this->f_20)->*(*(void (CActorManager_2f9a0::**)(const char *, float, float))&this->f_1c))(args->name, args->first, args->second);
}
