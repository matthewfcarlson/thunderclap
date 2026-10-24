// FUN_001fcab0 @ 0x001fcab0
#include "gen/global.h"

struct Vec3_1fcab0 {
    float x, y, z;
};
struct Actor_1fcab0 {
    char pad0[0xb0];
    Vec3_1fcab0 a;
    Vec3_1fcab0 b;
    void FUN_001fbb80(Vec3_1fcab0 *a, Vec3_1fcab0 *b, float angle);
};
struct CTriggerVolumeManager_nv_1fcab0 {
    Actor_1fcab0 * FUN_001fc7f0(int id);
};

bool CTriggerVolumeManager::FUN_001fcab0(int id, float degrees) {
    Actor_1fcab0 *actor = ((CTriggerVolumeManager_nv_1fcab0*)(this))->FUN_001fc7f0(id);
    if (actor == 0)
        return false;
    Vec3_1fcab0 a = actor->a;
    Vec3_1fcab0 b = actor->b;
    actor->FUN_001fbb80(&a, &b, degrees * 0.01745329238474369f);
    return true;
}
