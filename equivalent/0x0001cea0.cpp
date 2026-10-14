// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 16/16)
// CWeaponCollisionAction::vfunc_4 @ 0x0001cea0
void *__fastcall FUN_000592a0(void *owner);

struct Fx_1cea0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void SetScale(float s);
};
struct Attach_1cea0 { char pad[0x20]; Fx_1cea0 *fx; };
struct Target_1cea0 { void FUN_001d7330(int a); };
struct Thing_1cea0 {
    virtual void v0();
    virtual void Release();
    char pad04[4];
    Target_1cea0 *target;
    int kind;
    char pad10[0x74 - 0x10];
    Attach_1cea0 *attach;
};
struct RefObj_1cea0 {
    virtual void v0();
    virtual void Release();
};
struct Weapon_1cea0 { char pad[0x24]; char active; };
struct Hero_1cea0 {
    char pad0[0x1b49];
    char flag;
    char pad1b4a[0x1e48 - 0x1b4a];
    int f1e48;
    bool FUN_00035ab0();
    void FUN_0003b580(int a, int b, int c);
};
Hero_1cea0 *__fastcall FUN_00059a30(void *x);

class CWeaponCollisionAction {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4();
    char pad04[0x18];
    void *owner;
    Weapon_1cea0 *weapon;
    Thing_1cea0 *thing;
    char pad28[0x7c - 0x28];
    RefObj_1cea0 *extra;
};

void CWeaponCollisionAction::vfunc_4()
{
    Hero_1cea0 *hero = FUN_00059a30(FUN_000592a0(owner));
    if (weapon->active && hero->FUN_00035ab0())
        hero->FUN_0003b580(0, 0, 0);
    hero->flag = 0;
    if (thing != 0) {
        hero->f1e48 = 0;
        if (thing->attach != 0) {
            Fx_1cea0 *fx = thing->attach->fx;
            if (fx != 0)
                fx->SetScale(1.0f);
        }
        if (thing->kind == 5)
            thing->target->FUN_001d7330(0);
        if (thing != 0) {
            thing->Release();
            thing = 0;
        }
        if (extra != 0) {
            extra->Release();
            extra = 0;
        }
    }
}
