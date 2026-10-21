// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 8/8)
// FUN_00029f20 @ 0x00029f20
// Distance between two named pawns (-1 when either is missing or has no position).
#include "decls/address.h"
#include "compat/ptr.h"

struct Vec3_29f20 {
    float x, y, z;
};

struct Body_29f20 {
    bool FUN_00059a50(Vec3_29f20 *out);
};

struct Pawn_29f20 {
    char pad[0x10];
    Body_29f20 *body;
};

float __cdecl FUN_00025990(Vec3_29f20 *a, Vec3_29f20 *b);

struct Group_29f20 {
    Pawn_29f20 *FUN_00024280(unsigned __int64 key);
    hulk_freg FUN_00029f20(const char *nameA, const char *nameB);
};

hulk_freg Group_29f20::FUN_00029f20(const char *nameA, const char *nameB)
{
    struct Frame {
        Vec3_29f20 b;
        Vec3_29f20 a;
    } fr;
    Pawn_29f20 *pa = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (pa) {
        Pawn_29f20 *pb = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (pb && pa->body->FUN_00059a50(&fr.a) && pb->body->FUN_00059a50(&fr.b))
            return FUN_00025990(&fr.a, &fr.b);
    }
    return -1.0f;
}
