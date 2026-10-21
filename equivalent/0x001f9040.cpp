// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 10/10)
// FUN_001f9040 @ 0x001f9040
#include "compat/ptr.h"
struct V3_1f9040 {
    float x, y, z;
};

class Target_1f9040 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(V3_1f9040 *out);
};

struct Tracker_1f9040 {
    bool FUN_00059a50(V3_1f9040 *out);
};

struct Source_1f9040 {
    char pad0[0x10];
    Tracker_1f9040 *tracker;       // 0x10
};

class Area {
public:
    char pad0[0x458];
    int enabled;            // 0x458
    float FUN_001f8890();
    bool FUN_001f9040(Source_1f9040 *src, Target_1f9040 *target);
};

bool Area::FUN_001f9040(Source_1f9040 *src, Target_1f9040 *target)
{
    if (enabled == 0)
        return false;
    struct Frame {
        V3_1f9040 other;
        V3_1f9040 pos;
    } fr;
    if (!src->tracker->FUN_00059a50(&fr.pos))
        return false;
    hulk_freg radius = FUN_001f8890();
    if (radius <= 0.0f)
        return false;
    if (target == 0)
        return false;
    target->v8(&fr.other);
    hulk_freg dx = fr.other.x - fr.pos.x;
    hulk_freg dy = fr.other.y - fr.pos.y;
    hulk_freg dz = fr.other.z - fr.pos.z;
    if ((dz * dz + dy * dy) + dx * dx <= radius * radius)
        return true;
    return false;
}
