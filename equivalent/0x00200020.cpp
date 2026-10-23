// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_2 @ 0x00200020
#include "gen/global.h"

class CTriggerVolumeManager_200020 {};

template <> void Closure2<CTriggerVolumeManager, bool, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** arguments = (const char **)__p1; bool * result = (bool *)__p2;

    bool value = ((*(CTriggerVolumeManager_200020 * *)&this->f_20)->*(*(bool (CTriggerVolumeManager_200020::**)(const char *, const char *))&this->f_1c))(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
