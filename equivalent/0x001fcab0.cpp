// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fcab0 @ 0x001fcab0
struct Vec3_1fcab0 {
    float x, y, z;
};
struct Actor_1fcab0 {
    char pad0[0xb0];
    Vec3_1fcab0 a;
    Vec3_1fcab0 b;
    void FUN_001fbb80(Vec3_1fcab0 *a, Vec3_1fcab0 *b, float angle);
};
Actor_1fcab0 *__stdcall FUN_001fc7f0(int id);

bool __stdcall FUN_001fcab0(int id, float degrees)
{
    Actor_1fcab0 *actor = FUN_001fc7f0(id);
    if (actor == 0)
        return false;
    Vec3_1fcab0 a = actor->a;
    Vec3_1fcab0 b = actor->b;
    actor->FUN_001fbb80(&a, &b, degrees * 0.01745329238474369f);
    return true;
}
