// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f10d0
#include "gen/global.h"

struct CSoundSystem_1f10d0 {
    void FUN_001f10d0(char *, float, float);
};
struct SoundArguments {
    char *name;
    float first;
    float second;
};
struct Function_1f10d0 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CSoundSystem, void, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundSystem_1f10d0 * system = (CSoundSystem_1f10d0 *)__p0; SoundArguments * arguments = (SoundArguments *)__p1; void * unused = (void *)__p2;

    (system->*(*(void (CSoundSystem_1f10d0::**)(char *, float, float))&this->f_1c))(arguments->name, arguments->first, arguments->second);
}
