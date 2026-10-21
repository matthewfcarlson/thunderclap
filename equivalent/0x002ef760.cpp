// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 2/2)
// FUN_002ef760 @ 0x002ef760
#include "compat/ptr.h"
struct Vec3_2ef760 {
    float x, y, z;
};

struct Pose {
    char pad00[0x30];
    Vec3_2ef760 pos;                // 0x30
};

struct Motion_2ef760 {
    Vec3_2ef760 delta;              // 0x00
    Vec3_2ef760 aux;                // 0x0c
};

void __cdecl FUN_00305630(Vec3_2ef760 *out, Pose *a, Pose *b, float dt);

void __cdecl FUN_002ef760(Pose *from, Pose *to, float scale, float dt, Motion_2ef760 *out) {
    out->delta.x = to->pos.x - from->pos.x;
    out->delta.y = to->pos.y - from->pos.y;
    out->delta.z = to->pos.z - from->pos.z;
    hulk_freg inv = 1.0f / dt;
    out->delta.x = inv * out->delta.x;
    out->delta.y = inv * out->delta.y;
    out->delta.z = inv * out->delta.z;
    FUN_00305630(&out->aux, from, to, dt);
    if (scale != 1.0f) {
        hulk_freg k = 1.0f / (scale * scale);
        out->aux.x = k * out->aux.x;
        out->aux.y = k * out->aux.y;
        out->aux.z = k * out->aux.z;
    }
}
