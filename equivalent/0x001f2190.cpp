// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CSoundSystem,void,char_*,float,float>::vfunc_2 @ 0x001f2190
#include "gen/global.h"

struct CSoundSystem_1f2190 {};
struct SoundArgs { char *name; float first; float second; };

template <> void Closure3<CSoundSystem, void, char *, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; SoundArgs * args = (SoundArgs *)__p1; void * unused2 = (void *)__p2;

    ((*(CSoundSystem_1f2190 * *)&this->f_20)->*(*(void (CSoundSystem_1f2190::**)(char *, float, float))&this->f_1c))(args->name, args->first, args->second);
}
