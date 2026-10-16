// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00226250 @ 0x00226250
#include "decls/data/engine/choreo2.h"

struct V3_226250 {
    float x, y, z;
};


void __cdecl FUN_00224d70(void *transform, V3_226250 *vec);

class Emitter_226250 {
public:
    void FUN_00226250(V3_226250 *out);

    char pad0[0x12e4];
    void *transform;    // +0x12e4
    float speed;        // +0x12e8
};

// Transforms the default direction by the emitter's transform and scales it by its speed.
void Emitter_226250::FUN_00226250(V3_226250 *out) {
    V3_226250 dir;
    dir.x = (*(float*)&DAT_004c9e74);
    dir.y = (*(float*)&DAT_004c9e78);
    dir.z = (*(float*)&DAT_004c9e7c);
    FUN_00224d70(transform, &dir);
    float s = speed;
    dir.x = dir.x * s;
    out->x = dir.x;
    dir.y = dir.y * s;
    out->y = dir.y;
    dir.z = dir.z * s;
    out->z = dir.z;
}
