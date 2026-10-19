// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 54/62, incomplete)
// hulkfight::ai::MotionLocatorAction::vfunc_5 @ 0x00117480
#include "decls/address.h"
struct V3_117480 {
    float x, y, z;
    float FUN_0022d110();
};

class Target_117480 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void getPosition(V3_117480 *out);
};

struct Registry_117480 {
    Target_117480 *FUN_001fc8c0(unsigned __int64 id);
};
struct World {
    char pad[0x28];
    Registry_117480 *registry;
};

struct Strings_117480 {
    const char *FUN_001d3030(const char *name, const char *tag);
};
Strings_117480 *FUN_001d4c90();

struct Info_117480 {
    char pad0[0x14];
    float f14;
    float rangeMin;
    float rangeMax;
    float f20;
    float f24;
    char flag28;
    char flag29;
    char flag2a;
    char flag2b;
    unsigned __int64 id2c;
};

struct Anchor_117480 {
    char pad0[0xa0];
    unsigned __int64 id;
};

struct Pos_117480 {
    void FUN_00059a50(V3_117480 *out);
};

struct Owner_117480;
struct Inner_117480 {
    Owner_117480 *FUN_00059a30();
};

struct Owner_117480 {
    char pad0[0x10];
    Pos_117480 *pos;
    char pad14[0x1ca0 - 0x14];
    Anchor_117480 *anchor;
    char pad1ca4[0x1d70 - 0x1ca4];
    unsigned __int64 id1d70;
    char pad1d78[0x2064 - 0x1d78];
    V3_117480 dir;
    float strength;
    const char *FUN_00036d00();
};

struct Source_117480 {
    Inner_117480 *FUN_000592a0();
};

union Arg1_117480 {
    int v;
    float len;
};

class MotionLocatorAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(Arg1_117480 a1, int a2);
    char pad04[0x1c - 4];
    Info_117480 *info;
    Source_117480 *source;
    float f24;
    float distance;
    float height;
    char FUN_001173f0();
};

char MotionLocatorAction::v5(Arg1_117480 a1, int a2)
{
    if (a1.v)
        return 1;
    if (!source)
        return 0;
    Inner_117480 *inner = source->FUN_000592a0();
    Owner_117480 *owner = inner->FUN_00059a30();
    if (!owner || !inner)
        return 0;
    unsigned __int64 id;
    Info_117480 *inf = info;
    if (inf->flag2b) {
        id = inf->id2c;
    } else if (inf->flag2a && owner->anchor) {
        id = owner->anchor->id;
    } else if (inf->flag29) {
        id = owner->id1d70;
    } else if (inf->flag28) {
        id = FUN_002672f0(FUN_001d4c90()->FUN_001d3030(owner->FUN_00036d00(), "locator"), 0, 0);
        if (id == 0) {
            id = owner->id1d70;
            if (id == 0)
                return 0;
        }
    } else {
        return 0;
    }
    Target_117480 *target = DAT_004dd700->registry->FUN_001fc8c0(id);
    if (!target)
        return 0;
    V3_117480 pos;
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    V3_117480 tp;
    target->getPosition(&tp);
    owner->pos->FUN_00059a50(&pos);
    V3_117480 d;
    d.x = tp.x - pos.x;
    d.y = 0;
    float dy = tp.y - pos.y;
    d.z = tp.z - pos.z;
    float ny = -dy;
    a1.len = d.FUN_0022d110();
    distance = a1.len;
    height = ny;
    V3_117480 out;
    out.x = 0;
    out.y = 0;
    out.z = 0;
    inf = info;
    float rangeMin = inf->rangeMin;
    float rangeMax = inf->rangeMax;
    float s = 0.0f;
    if (a1.len < rangeMin) {
        out.x = d.x * -1.0f;
        out.y = d.y * -1.0f;
        out.z = d.z * -1.0f;
        s = inf->f14;
    } else if (a1.len > rangeMax) {
        out.x = d.x;
        out.y = d.y;
        out.z = d.z;
        s = inf->f14;
    }
    float f24v = inf->f24;
    if (ny < inf->f20) {
        if (a1.len >= rangeMin && a1.len <= rangeMax) {
            out.y = 1.0f;
            out.FUN_0022d110();
            s = info->f14;
        } else if (a1.len < rangeMin && rangeMin > 0.0f) {
            out.y = 1.0f - (rangeMin - a1.len) / rangeMin;
            out.FUN_0022d110();
            s = info->f14;
        } else {
            float twice = rangeMax + rangeMax;
            if (a1.len > rangeMax && a1.len < twice && rangeMax > 0.0f) {
                out.y = (twice - a1.len) / twice;
                out.FUN_0022d110();
                s = info->f14;
            } else {
                out.y = 0.0f;
            }
        }
    } else if (ny > f24v) {
        if (a1.len >= rangeMin && a1.len <= rangeMax) {
            out.y = -1.0f;
            out.FUN_0022d110();
            s = info->f14;
        } else if (a1.len < rangeMin && rangeMin > 0.0f) {
            out.y = (rangeMin - a1.len) / rangeMin - 1.0f;
            out.FUN_0022d110();
            s = info->f14;
        } else {
            float twice = rangeMax + rangeMax;
            if (a1.len > rangeMax && a1.len < twice && rangeMax > 0.0f) {
                out.y = -((twice - a1.len) / twice);
                out.FUN_0022d110();
                s = info->f14;
            } else {
                out.y = 0.0f;
            }
        }
    }
    owner->dir = out;
    owner->strength = s;
    f24 = s;
    return FUN_001173f0() == 0;
}
