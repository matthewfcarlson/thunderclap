// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,char_*,float>::vfunc_2 @ 0x001f1de0
#include "gen/global.h"

struct CSoundSystem_1f1de0 {
    void FUN_001f1de0(char *, char *, float);
};
struct SoundArgs { char *first; char *second; float volume; };

template <> void Closure3<CSoundSystem, void, char *, char *, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { SoundArgs * args = (SoundArgs *)__p1;

    ((*(CSoundSystem_1f1de0 * *)&this->f_20)->*(*(void (CSoundSystem_1f1de0::**)(char *, char *, float))&this->f_1c))(args->first, args->second, args->volume);
}
