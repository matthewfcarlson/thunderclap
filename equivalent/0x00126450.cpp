// STATUS: equivalent (tools/equiv.py level 3: 112 inputs, branch coverage 28/28)
// hulkfight::ai::TargetDirectionYCondition::vfunc_6 @ 0x00126450
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Vec3 {
    float x, y, z;
};

struct Locator {
    void FUN_00059a50(Vec3 *out);
};

struct Target {
    char pad0[0x40];
    Vec3 pos;
    char pad4c[0x54 - 0x4c];
    float scale;
};

struct Actor {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x328 - 0x14];
    Target *target;
};

struct Chain {
    Actor *FUN_00059a30();
};

struct Owner {
    Chain *FUN_000592a0();
};

class TargetDirectionYCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner *owner, int unused3);
    char pad4[8];
    int mode;
    int value;
};

char TargetDirectionYCondition::vfunc_6(int unused1, Owner *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor *actor = owner->FUN_000592a0()->FUN_00059a30();
    Target *t = actor->target;
    if (!t)
        return 0;

    Vec3 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    actor->locator->FUN_00059a50(&v);

    float d = (v.y - t->pos.y) * t->scale;
    float s;
    if (d < 0.0f)
        s = -1.0f;
    else if (d > 0.0f)
        s = 1.0f;
    else
        s = 0.0f;
    int dir = (int)s;

    switch (mode) {
    case 0:
        return dir < value;
    case 1:
        return dir <= value;
    case 2:
        return dir == value;
    case 3:
        return dir != value;
    case 4:
        return dir >= value;
    case 5:
        return dir > value;
    }
    return 0;
}
