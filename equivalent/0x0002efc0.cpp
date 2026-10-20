// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CActorManager,bool,const_char_*,const_char_*>::vfunc_2 @ 0x0002efc0
#include "gen/global.h"

struct CActorManager_2efc0 { bool FUN_0002efc0(const char *, const char *); };
struct Function_2efc0 { virtual void vfunc_0(); virtual void vfunc_1(); };

template <> void Closure2<CActorManager, bool, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** args = (const char **)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CActorManager_2efc0 * *)&this->f_20)->*(*(bool (CActorManager_2efc0::**)(const char *, const char *))&this->f_1c))(args[0], args[1]);
    if (result) *result = value;
}
