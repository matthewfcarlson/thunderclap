// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 14/14)
// hulkfight::ai::TargetInvincibleCondition::vfunc_6 @ 0x001249b0
#include "gen/hulkfight.h"

extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Invincible {
    char FUN_00036170();
};

struct Body_1249b0 {
    char pad0[8];
    Invincible *invincible;
    int state;
};

struct Res_1249b0 {
    char pad00[0x328];
    Body_1249b0 *body;
};

struct Resolver_1249b0 {
    Res_1249b0 *FUN_00059a30();
};

struct Target_1249b0 {
    Resolver_1249b0 *FUN_000592a0();
};

bool hulkfight::ai::TargetInvincibleCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; void * obj = (void *)__p1; int c = (int)__p2;

    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0)) {
        return false;
    }
    Body_1249b0 *body = ((Target_1249b0 *)obj)->FUN_000592a0()->FUN_00059a30()->body;
    if (body == 0) {
        return false;
    }
    if (body->state == 1) {
        if (body->invincible == 0) {
            return false;
        }
        return body->invincible->FUN_00036170() == this->f_0c;
    }
    if (body->state == 5) {
        return this->f_0c == 0;
    }
    return false;
}
