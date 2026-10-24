// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 2/2)
// FUN_001fc9f0 @ 0x001fc9f0
#include "gen/global.h"

struct Result { int x, y, z; };
struct Object_1fc9f0 { char pad[0xb0]; Result value; };
struct CTriggerVolumeManager_nv_1fc9f0 {
    Object_1fc9f0* FUN_001fc7f0(int id);
};

void CTriggerVolumeManager::FUN_001fc9f0(void* __p0, int id) { Result * out = (Result *)__p0;

    Object_1fc9f0* object = ((CTriggerVolumeManager_nv_1fc9f0*)(this))->FUN_001fc7f0(id);
    if (object) *out = object->value;
    else { out->x = 0; out->y = 0; out->z = 0; }
}
