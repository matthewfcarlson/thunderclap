#include "gen/global.h"

struct X_1fcbc0 {
    char pad[0xce];
    char m;
};
struct CTriggerVolumeManager_nv_1fcbc0 {
    X_1fcbc0* FUN_001fc7f0(void* p);
};

void CTriggerVolumeManager::FUN_001fcbc0(void* p, char c) {
    X_1fcbc0* q = ((CTriggerVolumeManager_nv_1fcbc0*)(this))->FUN_001fc7f0(p);
    if (q)
        q->m = c;
}
