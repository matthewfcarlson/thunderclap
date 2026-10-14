// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// CStageCondition::vfunc_7 @ 0x00048350
struct Fighter;
struct Owner;

struct Actor {
    char pad0[0x1e44];
    int stage;                // 0x1e44
};

Fighter *__fastcall FUN_000592a0(Owner *owner);
Actor *__fastcall FUN_00059a30(Fighter *f);

class CStageCondition {
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
    int op;                   // 0xc
    int value;                // 0x10
};

bool CStageCondition::vfunc_7(Owner *owner)
{
    Actor *actor = FUN_00059a30(FUN_000592a0(owner));
    switch (op) {
    case 0: return actor->stage < value;
    case 1: return actor->stage <= value;
    case 2: return actor->stage == value;
    case 3: return actor->stage != value;
    case 4: return actor->stage >= value;
    case 5: return actor->stage > value;
    }
    return false;
}
