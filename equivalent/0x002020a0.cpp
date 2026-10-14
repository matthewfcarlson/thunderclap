// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 18/18)
// FUN_002020a0 @ 0x002020a0
extern "C" double sqrt(double);

struct Thing {
    bool FUN_00035a90();
};

struct Actor {
    char pad0[0x114];
    int busy;           // 0x114
    char pad118[0x148 - 0x118];
    Thing *thing;       // 0x148
    bool FUN_001d6980();
    int FUN_001d64a0();
};

struct Target {
    char pad0[8];
    Actor *actor;       // 0x8
    int kind;           // 0xc
    char pad10[0x40];
    float x;            // 0x50
    float y;            // 0x54
    float z;            // 0x58
};

bool FUN_002020a0(Target *t)
{
    if (t == 0)
        return false;
    if (sqrt(t->x * t->x + t->y * t->y + t->z * t->z) > 5.0f)
        return false;
    if (t->kind != 5)
        return false;
    Actor *a = t->actor;
    if (a == 0)
        return false;
    if (a->FUN_001d6980())
        return false;
    if (a->busy != 0)
        return false;
    if (a->thing != 0)
        return !a->thing->FUN_00035a90();
    switch (a->FUN_001d64a0()) {
    case 1: case 5: case 12: case 13: case 15: case 16: case 20: case 21:
        return false;
    case 0: case 2: case 3: case 4: case 6: case 7: case 8: case 9: case 10: case 11:
    case 14: case 17: case 18: case 19: case 22:
        return true;
    default:
        return false;
    }
}
