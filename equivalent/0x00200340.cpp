// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,int,const_char_*>::vfunc_2 @ 0x00200340
#include "gen/global.h"

class CTriggerVolumeManager_200340 { public: int FUN_00200340(const char *); };

template <> void Closure1<CTriggerVolumeManager, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const char ** value = (const char **)__p1; int * result = (int *)__p2;

    int answer = ((*(CTriggerVolumeManager_200340 * *)&this->f_20)->*(*(int (CTriggerVolumeManager_200340::**)(const char *))&this->f_1c))(*value);
    if (result)
        *result = answer;
}
