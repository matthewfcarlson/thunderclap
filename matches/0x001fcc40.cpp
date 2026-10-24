#include "gen/global.h"

struct Obj_1fcc40 {
    char pad[0xcd];
    char flag;
};

struct CTriggerVolumeManager_nv_1fcc40 {
    Obj_1fcc40* Helper(void*);
};

void CTriggerVolumeManager::FUN_001fcc40(void* p) {
    Obj_1fcc40* r = ((CTriggerVolumeManager_nv_1fcc40*)(this))->Helper(p);
    if (r) {
        r->flag = 0;
    }
}
