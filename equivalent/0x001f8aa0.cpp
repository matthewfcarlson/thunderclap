// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 8/8)
// FUN_001f8aa0 @ 0x001f8aa0
#include "compat/ptr.h"
struct Vec3_1f8aa0 {
    float x, y, z;
};

struct Owner_1f8aa0 {
    bool FUN_00059a50(Vec3_1f8aa0 *out);
};

struct Source_1f8aa0 {
    char pad0[0x10];
    Owner_1f8aa0 *owner;           // 0x10
};

class Target_1f8aa0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPosition(Vec3_1f8aa0 *out);        // slot 8
};

class Sensor_1f8aa0 {
public:
    char pad0[0x1c];
    float radius;           // 0x1c

    bool FUN_001f8aa0(Source_1f8aa0 *src, Target_1f8aa0 *target);
};

// True when the target lies within `radius` of the source owner's position.
bool Sensor_1f8aa0::FUN_001f8aa0(Source_1f8aa0 *src, Target_1f8aa0 *target)
{
    Vec3_1f8aa0 origin;
    if (!src->owner->FUN_00059a50(&origin))
        return false;
    hulk_freg r = radius;
    if (r <= 0.0f)
        return false;
    if (target == 0)
        return false;

    Vec3_1f8aa0 pos;
    target->GetPosition(&pos);
    hulk_freg dx = pos.x - origin.x;
    hulk_freg dy = pos.y - origin.y;
    hulk_freg dz = pos.z - origin.z;
    hulk_freg sum = dz * dz + dy * dy + dx * dx;
    return sum <= r * r;
}
