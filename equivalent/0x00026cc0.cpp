// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00026cc0 @ 0x00026cc0
#include "decls/address.h"

struct Vec3_26cc0 {
    float x, y, z;
};

struct Pawn_26cc0 {
    void FUN_00035660(Vec3_26cc0 *out);
};

struct Group_26cc0 {
    Pawn_26cc0 *FUN_00024280(unsigned __int64 key);
    Vec3_26cc0 *FUN_00026cc0(Vec3_26cc0 *out, const char *name);
};

Vec3_26cc0 *Group_26cc0::FUN_00026cc0(Vec3_26cc0 *out, const char *name)
{
    Pawn_26cc0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (!pawn) {
        out->x = 0;
        out->y = 0;
        out->z = 0;
        return out;
    }
    Vec3_26cc0 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    pawn->FUN_00035660(&v);
    out->x = v.x;
    out->y = v.y;
    out->z = v.z;
    return out;
}
