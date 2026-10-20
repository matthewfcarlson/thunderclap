// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure2<CActorManager,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x0002fd40
#include "gen/global.h"

class CActorManager_2fd40 {
public:
    int FUN_0002fd40(const char *, const char *);
};

template <> void Closure2<CActorManager, const char *, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** arguments = (const char **)__p1; int * result = (int *)__p2;

    int value = ((*(CActorManager_2fd40 * *)&this->f_20)->*(*(int (CActorManager_2fd40::**)(const char *, const char *))&this->f_1c))(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
