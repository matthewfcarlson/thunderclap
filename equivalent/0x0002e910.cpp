// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CActorManager,void,const_char_*,float,bool>::vfunc_2 @ 0x0002e910
#include "gen/global.h"

struct CActorManager_2e910 { void FUN_00000000(const char *, float, bool); };
struct Arguments { const char *name; float value; bool flag; };

template <> void Closure3<CActorManager, void, const char *, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { const Arguments * args = (const Arguments *)__p1;

    ((*(CActorManager_2e910 * *)&this->f_20)->*(*(void (CActorManager_2e910::**)(const char *, float, bool))&this->f_1c))(args->name, args->value, args->flag);
}
