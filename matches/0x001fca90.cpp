#include "gen/global.h"

struct Info {
    char pad[0xc8];
    float value;
};
extern float DEFAULT_VALUE;
struct CTriggerVolumeManager_nv_1fca90 {
    Info* GetInfo(int);
};

float CTriggerVolumeManager::FUN_001fca90(int arg) {
    Info* p = ((CTriggerVolumeManager_nv_1fca90*)(this))->GetInfo(arg);
    if (!p)
        return DEFAULT_VALUE;
    return p->value;
}
