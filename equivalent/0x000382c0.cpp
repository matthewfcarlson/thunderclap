// STATUS: equivalent (tools/equiv.py level 3: 20028 inputs, branch coverage 15/15)
// FUN_000382c0 @ 0x000382c0
// cl-flags: /GS
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
struct Vec3_382c0 {
    float x, y, z;
};

struct Bias {
    float p0;
    float p4;
    float p8;
};

struct Limits_382c0 {
    char pad0[0x18];
    float minY;
};

struct World {
    char pad0[0x24];
    Limits_382c0 *limits;
};

struct Anchor_382c0 {
    // equiv-conv: FUN_00059a50 ecx stack
    bool FUN_00059a50(Vec3_382c0 *out);
};


class Camera {
public:
    char pad0[8];
    int f8;
    int fc;
    Anchor_382c0 *anchor;
    char pad14[0x12c];
    int mode;

    bool FUN_000352b0(Vec3_382c0 *out);
    bool FUN_00035550(Vec3_382c0 *out);
    bool FUN_000382c0(Vec3_382c0 *out);
};

bool Camera::FUN_000382c0(Vec3_382c0 *out)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    Vec3_382c0 pos;
    Vec3_382c0 off;

    if (!anchor->FUN_00059a50(&pos)) {
        return false;
    }
    if (f8 != (*(int*)&DAT_004dc0e0) || fc != (*(int*)((char*)&DAT_004dc0e0 + 4))) {
        if (!FUN_000352b0(out))
            *out = pos;
        return true;
    }
    *out = pos;
    Bias *b = 0;
    switch (mode) {
    case 1:
    case 2:
        b = ((Bias*)&DAT_0048f5d4);
        break;
    case 3:
        FUN_000352b0(out);
        break;
    case 4:
        b = ((Bias*)&DAT_0048f5e0);
        break;
    }
    if (b != 0) {
        FUN_00035550(&off);
        out->x = off.x * b->p8 + out->x;
        out->z = off.z * b->p8 + out->z;
        out->y = off.y * b->p8 + out->y + b->p4;
    }
    float limit = DAT_004dd700->limits->minY;
    if (limit > out->y)
        out->y = limit;
    return true;
}
