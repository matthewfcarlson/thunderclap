// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_2 @ 0x00200210
#include "gen/global.h"

struct Arguments { const char *name; bool value; };
struct CTriggerVolumeManager_200210 { bool invoke(const char *, bool); };

template <> void Closure2<CTriggerVolumeManager, bool, const char *, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; Arguments * arguments = (Arguments *)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CTriggerVolumeManager_200210 * *)&this->f_20)->*(*(bool (CTriggerVolumeManager_200210::**)(const char *, bool))&this->f_1c))(arguments->name, arguments->value);
    if (result) *result = value;
}
