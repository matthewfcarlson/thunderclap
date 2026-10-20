// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CAmbientsManager,void,const_char_*,unsigned_int,float>::vfunc_2 @ 0x0007e4b0
#include "gen/global.h"

struct CAmbientsManager_7e4b0 {};
struct AmbientArguments {
    const char *name;
    unsigned int id;
    float volume;
};

template <> void Closure3<CAmbientsManager, void, const char *, unsigned int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; AmbientArguments * arguments = (AmbientArguments *)__p1; void * unused2 = (void *)__p2;

    ((*(CAmbientsManager_7e4b0 * *)&this->f_20)->*(*(void (CAmbientsManager_7e4b0::**)(const char *, unsigned int, float))&this->f_1c))(arguments->name, arguments->id, arguments->volume);
}
