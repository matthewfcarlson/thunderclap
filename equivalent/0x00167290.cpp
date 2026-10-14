// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 14/14)
// hulkfight::motion::TargetMotionStateCondition::vfunc_6 @ 0x00167290
struct Stats;

struct Ctx {
    Stats *FUN_00059a30();
};

class Owner {
public:
    Ctx *FUN_000592a0();
};

struct Target {
    char pad0[0x140];
    unsigned int f140;
};

struct Stats {
    char pad0[0x328];
    struct Slot {
        char pad0[8];
        Target *f8;
        int fc;
    } *f328;
};

class TargetMotionStateCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(int a1, Owner *owner, int a3);
    char pad4[8];
    int fc;
    unsigned int f10;
};

char TargetMotionStateCondition::vfunc_6(int a1, Owner *owner, int a3)
{
    Stats *st = owner->FUN_000592a0()->FUN_00059a30();
    Stats::Slot *slot = st->f328;
    if (slot == 0 || slot->f8 == 0 || slot->fc != 1)
        return 1;
    unsigned int want = f10;
    unsigned int cur = slot->f8->f140;
    if (fc == 0)
        return cur == want;
    if (fc == 1)
        return cur != want;
    return 0;
}
