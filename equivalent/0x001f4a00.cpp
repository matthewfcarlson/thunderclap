// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method3<CSoundVoiceManager,void,bool,bool,bool>::vfunc_2 @ 0x001f4a00
#include "compat/ptr.h"
#include "gen/global.h"

struct CSoundVoiceManager_1f4a00 {
    void FUN_001f4a00(unsigned int, unsigned int, unsigned int);
};
struct Args { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; };
struct Function_1f4a00 {
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method3<CSoundVoiceManager, void, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSoundVoiceManager_1f4a00 * manager = (CSoundVoiceManager_1f4a00 *)__p0; Args * args = (Args *)__p1; void * unused = (void *)__p2;

    unsigned int first = ((hulk_uintptr)args & ~255u) | args->first;
    (manager->*(*(void (CSoundVoiceManager_1f4a00::**)(unsigned int, unsigned int, unsigned int))&this->f_1c))(first, args->second, args->third);
}
