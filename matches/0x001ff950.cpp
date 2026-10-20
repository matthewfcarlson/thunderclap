#include "gen/global.h"
struct Triple {
    int a, b, c;
};
struct CTriggerVolumeManager_nv_1ff950 {
    int FUN_001fba60();
};
struct Factory {
    CTriggerVolumeManager* FUN_001fe080(Triple a, int b, int c, int d, int e);
    int FUN_001ff950(Triple a, int b, int c, int d, int e);
};
int Factory::FUN_001ff950(Triple a, int b, int c, int d, int e) {
    CTriggerVolumeManager* p = FUN_001fe080(a, b, c, d, e);
    if (p)
        return ((CTriggerVolumeManager_nv_1ff950*)(p))->FUN_001fba60();
    return 0;
}