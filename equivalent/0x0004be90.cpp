// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CCollisionDirectionCondition::vfunc_7 @ 0x0004be90
struct Fighter;

struct Actor {
    float FUN_000354c0();
};

struct Target {
    char pad0[0x18];
    float x;                  // 0x18
    char pad1c[4];
    float y;                  // 0x20
};

struct Owner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Target *v3();
};

Fighter *__fastcall FUN_000592a0(Owner *owner);
Actor *__fastcall FUN_00059a30(Fighter *f);
extern "C" float __cdecl FUN_00224ea0(float a, float b);
extern "C" float __cdecl FUN_00224fc0(float a, float b);

class CCollisionDirectionCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(Owner *owner);
    char pad04[8];
    float offset;             // 0xc
    float tolerance;          // 0x10
};

bool CCollisionDirectionCondition::vfunc_7(Owner *owner)
{
    Actor *actor = FUN_00059a30(FUN_000592a0(owner));
    Target *target = owner->v3();
    if (target == 0)
        return false;
    actor->FUN_000354c0();
    float dir = FUN_00224ea0(target->x, target->y);
    float cur = actor->FUN_000354c0() + offset;
    float diff = FUN_00224fc0(dir, cur);
    union {
        float f;
        unsigned int u;
    } a;
    a.f = diff;
    a.u &= 0x7fffffff;
    return tolerance * 0.5f > a.f;
}
