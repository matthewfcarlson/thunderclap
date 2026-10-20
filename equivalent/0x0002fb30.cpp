// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CActorManager,void,const_char_*,const_char_*,float,float>::vfunc_2 @ 0x0002fb30
#include "gen/global.h"

struct CActorManager_2fb30 {
    void FUN_0002fb30(const char *, const char *, float, float);
};

template <> void Closure4<CActorManager, void, const char *, const char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const void * arguments = (const void *)__p1;

    struct Args {
        const char *first;
        const char *second;
        float third;
        float fourth;
    };
    const Args *args = (const Args *)arguments;
    ((*(CActorManager_2fb30 * *)&this->f_20)->*(*(void (CActorManager_2fb30::**)(const char *, const char *, float, float))&this->f_1c))(args->first, args->second, args->third, args->fourth);
}
