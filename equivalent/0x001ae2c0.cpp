// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 12/12)
// FUN_001ae2c0 @ 0x001ae2c0
#include "decls/address.h"
struct Vec3_1ae2c0 {
    float x, y, z;
};

struct Query_1ae2c0 {
    void *obj;
    int kind;
    int size;
    int param;

    unsigned FUN_001ad8c0(Vec3_1ae2c0 *pos, int a3, unsigned region, int a4, int a5, int a6, int a7, int a8, int a9,
                          int a10, int a11, int a12, int a13);
};

struct Zone_1ae2c0 {
    Vec3_1ae2c0 *FUN_001b5a20(Query_1ae2c0 *q, unsigned id);
};

struct Locator {
    void FUN_001b6000(Vec3_1ae2c0 *pos, Zone_1ae2c0 **zone, unsigned *region);
};

struct World {
    char pad[0x10];
    Locator *locator;
};


struct Recent {
    char pad[8];
    unsigned ids[2];
    int next;

    bool FUN_001ae2c0(Vec3_1ae2c0 *out, Vec3_1ae2c0 *pos, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10,
                      int a11, int a12, int a13);
};

bool Recent::FUN_001ae2c0(Vec3_1ae2c0 *out, Vec3_1ae2c0 *pos, int a3, int a4, int a5, int a6, int a7, int a8, int a9,
                          int a10, int a11, int a12, int a13)
{
    Zone_1ae2c0 *zone = 0;
    unsigned region = (unsigned)-1;
    Vec3_1ae2c0 p;
    p.x = pos->x;
    p.y = pos->y;
    p.z = pos->z;

    DAT_004dd700->locator->FUN_001b6000(&p, &zone, &region);
    if (zone == 0)
        return false;
    if (region == 0)
        return false;

    Query_1ae2c0 q;
    q.obj = zone;
    q.kind = 2;
    q.size = 0x4c;
    q.param = a10;

    unsigned id = q.FUN_001ad8c0(pos, a3, region, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
    if (id == 0)
        return false;
    if ((char)a11 == 0 && id == region)
        return false;

    Vec3_1ae2c0 *r = zone->FUN_001b5a20(&q, id);
    out->x = r->x;
    out->y = r->y;
    out->z = r->z;

    ids[next] = id;
    next++;
    if (next >= 2)
        next = 0;
    return true;
}
