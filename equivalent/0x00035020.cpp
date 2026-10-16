// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 6/6)
// FUN_00035020 @ 0x00035020
#include "decls/address.h"
struct Vec3 { int x; int y; int z; };

struct BoneEntry {
    char pad0[0x30];
    Vec3 pos;
    char pad1[0x40 - 0x3c];
};

struct Skeleton {
    char pad0[0x1c];
    BoneEntry* bones;
    int FUN_002843a0(__int64 key);
};

struct Handler {
    void FUN_00059a50(Vec3* out);
};


struct Character {
    char pad0[0x10];
    Handler* handler;
    char pad1[0x120 - 0x14];
    Skeleton* skeleton;
    bool FUN_00035020(Vec3* out);
};

bool Character::FUN_00035020(Vec3* out)
{
    // the skeleton pointer is re-read after every call, as in the original
    Skeleton* volatile* slot = &skeleton;
    Skeleton* sk = *slot;
    if (sk == 0)
        return false;
    int bone = sk->FUN_002843a0(FUN_002672f0("Head", 0, 0));
    if (bone == 0xffff) {
        sk = *slot;
        bone = sk->FUN_002843a0(FUN_002672f0("Neck", 0, 0));
        if (bone == 0xffff) {
            handler->FUN_00059a50(out);
            return false;
        }
    }
    sk = *slot;
    *out = sk->bones[bone].pos;
    return true;
}
