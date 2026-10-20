// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSoundSystem,void,char_*,char_*,float,float>::vfunc_2 @ 0x001f0da0
#include "gen/global.h"

struct CSoundSystem_1f0da0 {
};
struct Function_1f0da0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSoundSystem_1f0da0 *, void *, void *);
};
struct Arguments {
    char *first;
    char *second;
    float third;
    float fourth;
};

template <> void Method4<CSoundSystem, void, char *, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSystem_1f0da0 * sound = (CSoundSystem_1f0da0 *)__p0; void * args = (void *)__p1; void * unused = (void *)__p2;

    Arguments *a = (Arguments *)args;
    (sound->*(*(void (CSoundSystem_1f0da0::**)(char *, char *, float, float))&this->f_1c))(a->first, a->second, a->third, a->fourth);
}
