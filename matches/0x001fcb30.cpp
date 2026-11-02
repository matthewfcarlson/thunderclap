#include "gen/global.h"
// a..c and d..f: two vectors passed by value.
struct Vec3_1fcb30 {
    float x, y, z;
};
struct CTriggerVolumeManager_nv_1fcb30 {
    void Set(Vec3_1fcb30*, Vec3_1fcb30*, float);
};
struct ThisWrap_001fcb30 {
    CTriggerVolumeManager* Find(int);
    bool Target(int id, Vec3_1fcb30 a, Vec3_1fcb30 d, float angle);
};
bool ThisWrap_001fcb30::Target(int id, Vec3_1fcb30 a, Vec3_1fcb30 d, float angle) {
    CTriggerVolumeManager* o = this->Find(id);
    if (!o)
        return false;
    ((CTriggerVolumeManager_nv_1fcb30*)(o))->Set(&a, &d, angle * 0.017453292519943295f);
    return true;
}