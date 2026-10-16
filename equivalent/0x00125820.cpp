// STATUS: equivalent (tools/equiv.py level 3: 104 inputs, branch coverage 27/30, incomplete)
// hulkfight::ai::TargetDistanceYCondition::vfunc_6 @ 0x00125820
#include "decls/address.h"
extern "C" double sqrt(double);
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float epsilon);

union FloatBits_125820 {
    float f;
    unsigned int u;
};

struct Vec3_125820 {
    float x, y, z;
};

struct TargetObj {
    char pad0[0x1a60];
    float x;
    float y;
    float z;
};

struct Target_125820 {
    char pad0[8];
    TargetObj *obj;
    int kind;
    char pad10[0x30];
    Vec3_125820 pos;
};

struct Locator {
    char pad0[0x12c];
    Target_125820 *target;
};

struct Slot_125820 {
    char pad0[0x124];
    Locator *locator;
};

struct World {
    char pad0[0x20];
    Slot_125820 *slot;
};


struct Position_125820 {
    void FUN_00059a50(Vec3_125820 *out);
};

struct Actor_125820 {
    char pad0[0x10];
    Position_125820 *position;
    char pad14[0x314];
    Target_125820 *target;
};

struct Chain_125820 {
    Actor_125820 *FUN_00059a30();
};

struct Owner_125820 {
    Chain_125820 *FUN_000592a0();
};

class TargetDistanceYCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner_125820 *owner, int unused3);
    char pad4[8];
    int mode;
    float threshold;
    char absolute;
    char useLocator;
    char useObj;
};

char TargetDistanceYCondition::vfunc_6(int unused1, Owner_125820 *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor_125820 *actor = owner->FUN_000592a0()->FUN_00059a30();
    Vec3_125820 origin;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    actor->position->FUN_00059a50(&origin);
    Target_125820 *t = actor->target;
    if (useLocator) {
        Locator *loc = DAT_004dd700->slot->locator;
        if (loc)
            t = loc->target;
    }
    if (!t)
        return 0;
    float ty;
    if (t->kind == 1 && t->obj && useObj)
        ty = t->obj->y;
    else
        ty = t->pos.y;
    float dist = ty - origin.y;
    if (absolute == 1) {
        FloatBits_125820 bits;
        bits.f = dist;
        bits.u &= 0x7fffffff;
        dist = bits.f;
    }
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
