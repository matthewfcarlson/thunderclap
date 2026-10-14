// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 2/2)
// FUN_00028400 @ 0x00028400
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Vec3_28400 {
    float x, y, z;
    float FUN_0022d110();
};

struct Pawn_28400 {
    char pad[0x1b68];
    Vec3_28400 aimDir;
};

struct Group_28400 {
    Pawn_28400 *FUN_00024280(unsigned __int64 key);
    void FUN_00028400(const char *name, float x, float y, float z);
};

void Group_28400::FUN_00028400(const char *name, float x, float y, float z)
{
    Pawn_28400 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn) {
        Vec3_28400 v;
        v.x = x;
        v.y = y;
        v.z = z;
        v.FUN_0022d110();
        pawn->aimDir = v;
    }
}
