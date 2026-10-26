#include "gen/global.h"
#include "decls/data/game/global.h"

struct Info {
    char pad[0xc8];
    float value;
};
struct CTriggerVolumeManager_nv_1fca90 {
    Info* GetInfo(int);
};

float CTriggerVolumeManager::FUN_001fca90(int arg) {
    Info* p = ((CTriggerVolumeManager_nv_1fca90*)(this))->GetInfo(arg);
    if (!p)
        return (*(float*)&DAT_003f32e0);
    return p->value;
}
