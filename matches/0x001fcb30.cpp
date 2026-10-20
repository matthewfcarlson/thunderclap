#include "gen/global.h"
struct CTriggerVolumeManager_nv_1fcb30 {
    void Set(float*, float*, float);
};
struct ThisWrap_001fcb30 {
    CTriggerVolumeManager* Find(int);
    bool Target(int id, float a, float b, float c, float d, float e, float f, float angle);
};
bool ThisWrap_001fcb30::Target(int id, float a, float b, float c, float d, float e, float f, float angle) {
    CTriggerVolumeManager* o = this->Find(id);
    if (!o)
        return false;
    ((CTriggerVolumeManager_nv_1fcb30*)(o))->Set(&a, &d, angle * 0.017453292519943295f);
    return true;
}