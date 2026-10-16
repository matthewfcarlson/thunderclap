// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 6/6)
// FUN_00078ee0 @ 0x00078ee0
#include "decls/data/game/global.h"

struct Vec3_78ee0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Anchor_78ee0 {
    void FUN_00059a50(Vec3_78ee0 *out);
};

struct Ref124 {
    char pad0[0x10];
    Anchor_78ee0 *anchor;
};

struct Ref20_78ee0 {
    char pad0[0x124];
    Ref124 *ref;
};

struct Ref382c {
    char pad0[0x20];
    Ref20_78ee0 *ref;
};

char FUN_0022d550(Vec3_78ee0 *p0, Vec3_78ee0 *dir, Vec3_78ee0 *a, Vec3_78ee0 *b, float *outA, float *outB);

class Walker_78ee0 {
public:
    char pad0[0x382c];
    Ref382c *owner;
    void FUN_00078ee0(Vec3_78ee0 *a, Vec3_78ee0 *b);
};

void Walker_78ee0::FUN_00078ee0(Vec3_78ee0 *argA, Vec3_78ee0 *argB)
{
    // the argument slots double as scratch floats in the original frame
    float *slotA = (float *)&argA;
    float *slotB = (float *)&argB;
    Vec3_78ee0 *a = argA;
    Vec3_78ee0 *b = argB;
    Vec3_78ee0 cur;
    owner->ref->ref->anchor->FUN_00059a50(&cur);

    Vec3_78ee0 da;
    da.x = cur.x - a->x;
    da.y = 0;
    da.z = cur.z - a->z;
    float lenA = da.FUN_0022d110();

    Vec3_78ee0 db;
    db.x = cur.x - b->x;
    db.y = 0;
    db.z = cur.z - b->z;
    float lenB = db.FUN_0022d110();

    if (lenB > DAT_0049b898 && lenA > DAT_0049b898) {
        Vec3_78ee0 t;
        t.x = b->x - a->x;
        t.y = b->y - a->y;
        t.z = b->z - a->z;
        t.FUN_0022d110();
        a->x = b->x;
        a->y = b->y;
        a->z = b->z;
        a->x = a->x - t.x;
        a->y = a->y - t.y;
        a->z = a->z - t.z;
        return;
    }

    Vec3_78ee0 dir;
    if (lenB > lenA) {
        dir.x = -db.x;
        dir.y = -db.y;
        dir.z = -db.z;
    } else {
        dir.x = -da.x;
        dir.y = -da.y;
        dir.z = -da.z;
    }

    Vec3_78ee0 p0;
    p0.x = dir.x * DAT_0049b898 + cur.x;
    p0.y = dir.y * DAT_0049b898 + cur.y;
    p0.z = dir.z * DAT_0049b898 + cur.z;

    // dir x (0, 1, 0)
    Vec3_78ee0 side;
    *slotA = dir.y * 0.0f;
    side.x = *slotA - dir.z;
    side.y = dir.z * 0.0f - dir.x * 0.0f;
    side.z = dir.x * 1.0f - dir.y * 0.0f;

    FUN_0022d550(&p0, &side, a, b, slotB, slotA);
    float t = *slotA;

    Vec3_78ee0 w;
    w.x = b->x - a->x;
    w.y = b->y - a->y;
    w.z = b->z - a->z;
    w.FUN_0022d110();
    a->x = w.x * t + a->x;
    a->y = w.y * t + a->y;
    a->z = w.z * t + a->z;
}
