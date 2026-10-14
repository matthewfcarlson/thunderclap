// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001f9040 @ 0x001f9040
struct V3 {
    float x, y, z;
};

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(V3 *out);
};

struct Tracker {
    bool FUN_00059a50(V3 *out);
};

struct Source {
    char pad0[0x10];
    Tracker *tracker;       // 0x10
};

class Area {
public:
    char pad0[0x458];
    int enabled;            // 0x458
    float FUN_001f8890();
    bool FUN_001f9040(Source *src, Target *target);
};

bool Area::FUN_001f9040(Source *src, Target *target)
{
    if (enabled == 0)
        return false;
    struct Frame {
        V3 other;
        V3 pos;
    } fr;
    if (!src->tracker->FUN_00059a50(&fr.pos))
        return false;
    float radius = FUN_001f8890();
    if (radius <= 0.0f)
        return false;
    if (target == 0)
        return false;
    target->v8(&fr.other);
    float dx = fr.other.x - fr.pos.x;
    float dy = fr.other.y - fr.pos.y;
    float dz = fr.other.z - fr.pos.z;
    if ((dz * dz + dy * dy) + dx * dx <= radius * radius)
        return true;
    return false;
}
