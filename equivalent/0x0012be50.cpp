// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 16/18, incomplete)
// hulkfight::ai::ThreatDistanceCondition::vfunc_6 @ 0x0012be50
extern "C" double sqrt(double);
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern char FUN_00018960(float a, float b, float eps);

struct Vec3 {
    float x, y, z;
};

struct Locator {
    void FUN_00059a50(Vec3 *out);
};

struct Actor {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x22a0 - 0x14];
    Vec3 pos;
    char FUN_00037080(char *a, int b);
};

struct Chain {
    Actor *FUN_00059a30();
};

struct Owner {
    Chain *FUN_000592a0();
};

class ThreatDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner *owner, int unused3);
    char pad4[8];
    unsigned int mode;
    float threshold;
    char pad14[4];
    char key[8];
    unsigned char keyFlag;
};

char ThreatDistanceCondition::vfunc_6(int unused1, Owner *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor *actor = owner->FUN_000592a0()->FUN_00059a30();
    if (!actor->FUN_00037080(key, keyFlag))
        return 0;

    Vec3 target = actor->pos;
    Vec3 mine;
    mine.x = 0;
    mine.y = 0;
    mine.z = 0;
    actor->locator->FUN_00059a50(&mine);

    float dx = target.x - mine.x;
    float dy = target.y - mine.y;
    float dz = target.z - mine.z;
    float dist = (float)sqrt((double)(dz * dz + dy * dy + dx * dx));

    switch (mode) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 1e-5f);
    case 3:
        return !FUN_00018960(dist, threshold, 1e-5f);
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return 0;
}
