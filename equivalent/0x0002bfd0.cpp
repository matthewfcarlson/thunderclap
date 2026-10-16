// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0002bfd0 @ 0x0002bfd0

// Components are plain ints: the original copies them with integer moves.
#include "decls/address.h"
struct Vec3_2bfd0 {
    int x, y, z;
};

struct Pawn_2bfd0 {
    void FUN_000359c0(int mode);
};

struct Group_2bfd0 {
    Pawn_2bfd0 *FUN_00024280(unsigned __int64 key);
    bool FUN_0002b970(int a1, Vec3_2bfd0 pos, int a5, int a6, int a7, int a8, const char *name, int zero);
    bool FUN_0002bfd0(int a1, int x, int y, int z, int a5, int a6, int a7, int a8, const char *name);
};

bool Group_2bfd0::FUN_0002bfd0(int a1, int x, int y, int z, int a5, int a6, int a7, int a8, const char *name)
{
    Vec3_2bfd0 pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;
    bool result = FUN_0002b970(a1, pos, a5, a6, a7, a8, name, 0);
    Pawn_2bfd0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn)
        pawn->FUN_000359c0(3);
    return result;
}
