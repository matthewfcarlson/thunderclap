// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,const_char_*,const_char_*>::vfunc_2 @ 0x002004b0
#include "gen/global.h"

struct CTriggerVolumeManager_2004b0 {};
typedef const char* (CTriggerVolumeManager_2004b0::*TriggerMethod)(const char*);

template <> void Closure1<CTriggerVolumeManager, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** argument = (const char **)__p1; const char ** result = (const char **)__p2;

    const char* value = ((*(CTriggerVolumeManager_2004b0 * *)&this->f_20)->*(*(TriggerMethod *)&this->f_1c))(*argument);
    if (result) *result = value;
}
