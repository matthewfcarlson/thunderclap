// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x000301b0
#include "gen/global.h"

struct Vector_301b0 { float x, y, z; };
struct CActorManager_301b0 { bool FUN_000301b0(const char *, Vector_301b0); };

template <> void Closure2<CActorManager, bool, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { const void * data = (const void *)__p1; bool * result = (bool *)__p2;

    struct Arguments { const char *name; Vector_301b0 position; };
    const Arguments *args = (const Arguments *)data;
    bool value = ((*(CActorManager_301b0 * *)&this->f_20)->*(*(bool (CActorManager_301b0::**)(const char *, Vector_301b0))&this->f_1c))(args->name, args->position);
    if (result) *result = value;
}
