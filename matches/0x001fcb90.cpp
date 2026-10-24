#include "gen/global.h"

struct CTriggerVolumeManager_1fcb90 {
    char pad[0xcd];
    unsigned char a;
    unsigned char b;
};
struct CTriggerVolumeManager_nv_1fcb90 {
    CTriggerVolumeManager_1fcb90* Find(int);
};

unsigned char CTriggerVolumeManager::FUN_001fcb90(int n) {
    CTriggerVolumeManager_1fcb90* p = ((CTriggerVolumeManager_nv_1fcb90*)(this))->Find(n);
    if (p && p->b && p->a)
        return 1;
    return 0;
}
