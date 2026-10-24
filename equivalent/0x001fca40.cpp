// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 2/2)
// FUN_001fca40 @ 0x001fca40
#include "gen/global.h"

struct Vec3 { unsigned int x, y, z; };
struct Object_1fca40 { char padding[0xbc]; Vec3 position; };
struct CTriggerVolumeManager_nv_1fca40 {
    Object_1fca40* FUN_001fc7f0(unsigned int id);
};

void CTriggerVolumeManager::FUN_001fca40(void* __p0, unsigned int id) { Vec3 * output = (Vec3 *)__p0;

    Object_1fca40* object = ((CTriggerVolumeManager_nv_1fca40*)(this))->FUN_001fc7f0(id);
    if (object) *output = object->position;
    else { output->x = 0; output->y = 0; output->z = 0; }
}
