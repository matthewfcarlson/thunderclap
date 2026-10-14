// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0002a0e0 @ 0x0002a0e0
// Group method: look up a named pawn and run a collision sweep between two points, caching the result.
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Vec3_2a0e0 {
    float x, y, z;
};

struct HitExtra_2a0e0 {
    int b, c, d, e;
};

struct Pawn_2a0e0 {
    char FUN_00038de0(Vec3_2a0e0 *from, Vec3_2a0e0 *to, int a, int foreign, HitExtra_2a0e0 *outB, Vec3_2a0e0 *outN, int *outC, int hit);
};

// The name pointer's argument slot is reused as an out-int for the sweep.
union NameSlot_2a0e0 {
    const char *name;
    int out;
};

struct Group_2a0e0 {
    char pad000[0x124];
    Pawn_2a0e0 *current;              // 0x124
    char pad128[0x353 - 0x128];
    char active;                // 0x353
    Vec3_2a0e0 from;                  // 0x354
    Vec3_2a0e0 to;                    // 0x360
    char hit;                   // 0x36c
    char pad36d[3];
    HitExtra_2a0e0 extra;             // 0x370

    Pawn_2a0e0 *FUN_00024280(unsigned __int64 key);
    char FUN_0002a0e0(NameSlot_2a0e0 name, float fx, float fy, float fz, float tx, float ty, float tz);
};

char Group_2a0e0::FUN_0002a0e0(NameSlot_2a0e0 name, float fx, float fy, float fz, float tx, float ty, float tz)
{
    Pawn_2a0e0 *pawn = FUN_00024280(FUN_002672f0(name.name, 0, 0));
    if (!pawn)
        return 0;
    active = 1;
    from.x = fx;
    from.y = fy;
    from.z = fz;
    to.x = tx;
    to.y = ty;
    to.z = tz;
    int foreign = 0;
    if (pawn != current)
        foreign = 1;
    Vec3_2a0e0 normal;
    name.out = 0;
    hit = pawn->FUN_00038de0(&from, &to, 0, foreign, &extra, &normal, &name.out, 0);
    return hit;
}
