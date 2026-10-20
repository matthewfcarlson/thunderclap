// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 @ 0x001ff340
#include "gen/global.h"

struct CTriggerVolumeManager_1ff340 {};
struct TriggerArguments {
    const char *name;
    int value;
    bool enabled;
};

template <> void Method3<CTriggerVolumeManager, void, const char *, int, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CTriggerVolumeManager_1ff340 * manager = (CTriggerVolumeManager_1ff340 *)__p0; TriggerArguments * args = (TriggerArguments *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CTriggerVolumeManager_1ff340::**)(const char *, int, bool))&this->f_1c))(args->name, args->value, args->enabled);
}
