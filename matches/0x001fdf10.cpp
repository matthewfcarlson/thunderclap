#include "gen/global.h"
class CTriggerVolumeManager_1fdf10 {
  public:
    char pad[0x234];
    char* data;
    char check(int x);
};
struct CTriggerVolumeManager_nv_1fdf10 {
    int FUN_001fcff0(int);
};
char CTriggerVolumeManager_1fdf10::check(int x) {
    int i = ((CTriggerVolumeManager_nv_1fdf10*)(((CTriggerVolumeManager*)this)))->FUN_001fcff0(x);
    if (i == -1)
        return 0;
    return *(int*)(data + i * 0xc70 + 0x458) == 2;
}