// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 22/22)
// CPropActorStateCondition::vfunc_7 @ 0x00049bb0
struct Counter {
    char pad0[0x40];
    int value;      // 0x40
};

struct Stats {
    char pad0[0x128];
    Counter *counter;
};

class Owner;
Owner *__fastcall FUN_000592a0(Owner *owner);
Stats *__fastcall FUN_00059a30(Owner *ctx);

class CPropActorStateCondition {
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
    unsigned int op;    // 0xc
    int threshold;      // 0x10
};

bool CPropActorStateCondition::vfunc_7(Owner *owner)
{
    Stats *stats = FUN_00059a30(FUN_000592a0(owner));
    if (stats->counter == 0)
        return false;
    int value = stats->counter->value;
    switch (op) {
    case 0: return value < threshold;
    case 1: return value <= threshold;
    case 2: return value == threshold;
    case 3: return value != threshold;
    case 4: return value >= threshold;
    case 5: return value > threshold;
    }
    return false;
}
