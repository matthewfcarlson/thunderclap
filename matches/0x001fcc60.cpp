#include "gen/global.h"

struct CTriggerVolumeManager_1fcc60 {
    char pad[0xcd];
    unsigned char flag;
};
struct CTriggerVolumeManager_nv_1fcc60 {
    CTriggerVolumeManager_1fcc60* findObj(int);
};

void CTriggerVolumeManager::FUN_001fcc60(int id) {
    CTriggerVolumeManager_1fcc60* p = ((CTriggerVolumeManager_nv_1fcc60*)(this))->findObj(id);
    if (p)
        p->flag = 1;
}
