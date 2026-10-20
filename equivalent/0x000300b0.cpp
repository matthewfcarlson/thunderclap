// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,int,int,int>::vfunc_2 @ 0x000300b0
#include "gen/global.h"

struct CActorManager_300b0 { void FUN_000300b0(int, int, int); };
struct Triple { int first; int second; int third; };

template <> void Closure3<CActorManager, void, int, int, int>::vfunc_2(void* __p0, void* __p1, void* __p2) { Triple * args = (Triple *)__p1;

    ((*(CActorManager_300b0 * *)&this->f_20)->*(*(void (CActorManager_300b0::**)(int, int, int))&this->f_1c))(args->first, args->second, args->third);
}
