// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 14/14)
// hulkfight::ai::TargetInvincibleCondition::vfunc_6 @ 0x001249b0
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Invincible {
    char FUN_00036170();
};

struct Body {
    char pad0[8];
    Invincible *invincible;
    int state;
};

struct Res {
    char pad00[0x328];
    Body *body;
};

struct Resolver {
    Res *FUN_00059a30();
};

struct Target {
    Resolver *FUN_000592a0();
};

class TargetInvincibleCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, void *obj, int c);
    char pad04[8];
    char wanted;
};

bool TargetInvincibleCondition::vfunc_6(int a, void *obj, int c) {
    if (!FUN_00344e74(obj, 0, DAT_00494b44, DAT_00494b60, 0)) {
        return false;
    }
    Body *body = ((Target *)obj)->FUN_000592a0()->FUN_00059a30()->body;
    if (body == 0) {
        return false;
    }
    if (body->state == 1) {
        if (body->invincible == 0) {
            return false;
        }
        return body->invincible->FUN_00036170() == wanted;
    }
    if (body->state == 5) {
        return wanted == 0;
    }
    return false;
}
