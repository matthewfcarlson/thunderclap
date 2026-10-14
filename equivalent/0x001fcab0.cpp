// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001fcab0 @ 0x001fcab0
struct Vec3 {
    float x, y, z;
};
struct Actor {
    char pad0[0xb0];
    Vec3 a;
    Vec3 b;
    void FUN_001fbb80(Vec3 *a, Vec3 *b, float angle);
};
Actor *__stdcall FUN_001fc7f0(int id);

bool __stdcall FUN_001fcab0(int id, float degrees)
{
    Actor *actor = FUN_001fc7f0(id);
    if (actor == 0)
        return false;
    Vec3 a = actor->a;
    Vec3 b = actor->b;
    actor->FUN_001fbb80(&a, &b, degrees * 0.01745329238474369f);
    return true;
}
