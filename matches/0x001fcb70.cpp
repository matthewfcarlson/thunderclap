#include "gen/global.h"

#include "compat/ptr.h"
struct R {
    char pad[0xcd];
    char f;
};
struct CTriggerVolumeManager_nv_1fcb70 {
    hulk_intptr FUN_001fc7f0(unsigned int);
};

char CTriggerVolumeManager::FUN_001fcb70(unsigned int x) {
    R* p = (R*)((CTriggerVolumeManager_nv_1fcb70*)(this))->FUN_001fc7f0(x);
    if (p == 0)
        return 0;
    return p->f;
}
