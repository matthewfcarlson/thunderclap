// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 28/28)
// hulkfight::ai::TargetDirectionYCondition::vfunc_6 @ 0x00126450
#include "gen/hulkfight.h"

#include "compat/ptr.h"
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Vec3_126450 {
    float x, y, z;
};

struct Locator_126450 {
    void FUN_00059a50(Vec3_126450 *out);
};

struct Target_126450 {
    char pad0[0x40];
    Vec3_126450 pos;
    char pad4c[0x54 - 0x4c];
    float scale;
};

struct Actor_126450 {
    char pad0[0x10];
    Locator_126450 *locator;
    char pad14[0x328 - 0x14];
    Target_126450 *target;
};

struct Chain_126450 {
    Actor_126450 *FUN_00059a30();
};

struct Owner_126450 {
    Chain_126450 *FUN_000592a0();
};

bool hulkfight::ai::TargetDirectionYCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int unused1 = (int)__p0; Owner_126450 * owner = (Owner_126450 *)__p1; int unused3 = (int)__p2;

    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return (bool)(0);
    Actor_126450 *actor = owner->FUN_000592a0()->FUN_00059a30();
    Target_126450 *t = actor->target;
    if (!t)
        return (bool)(0);

    Vec3_126450 v;
    v.x = 0;
    v.y = 0;
    v.z = 0;
    actor->locator->FUN_00059a50(&v);

    hulk_freg d = (v.y - t->pos.y) * t->scale;
    float s;
    if (d < 0.0f)
        s = -1.0f;
    else if (d > 0.0f)
        s = 1.0f;
    else
        s = 0.0f;
    int dir = (int)s;

    switch (this->f_0c) {
    case 0:
        return (bool)(dir < this->f_10);
    case 1:
        return (bool)(dir <= this->f_10);
    case 2:
        return (bool)(dir == this->f_10);
    case 3:
        return (bool)(dir != this->f_10);
    case 4:
        return (bool)(dir >= this->f_10);
    case 5:
        return (bool)(dir > this->f_10);
    }
    return (bool)(0);
}
