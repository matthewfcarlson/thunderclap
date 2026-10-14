// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// hulkfight::motion::HealthAction::vfunc_3 @ 0x0014ff20
struct Stats_14ff20 {
    char pad0[0x1b0c];
    float offset;       // 0x1b0c
    void FUN_0003b1c0(float value, int flag);
};

struct Info_14ff20 {
    char pad0[0x10];
    float value;        // 0x10
    char negate;        // 0x14
    char useOffsetA;    // 0x15
    char useOffsetB;    // 0x16
};

class Owner;
Owner *__fastcall FUN_000592a0(Owner *owner);
Stats_14ff20 *__fastcall FUN_00059a30(Owner *ctx);

namespace hulkfight {
namespace motion {

class HealthAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    char pad04[0x18];
    Info_14ff20 *info;     // 0x1c
    Owner *owner;   // 0x20
};

bool HealthAction::vfunc_3(int a, int b)
{
    if (owner == 0)
        return false;
    Stats_14ff20 *stats = FUN_00059a30(FUN_000592a0(owner));
    if (stats == 0)
        return false;
    int flag = info->negate != 0;
    if (info->useOffsetB)
        stats->FUN_0003b1c0(stats->offset - info->value, flag);
    else if (info->useOffsetA)
        stats->FUN_0003b1c0(info->value + stats->offset, flag);
    else
        stats->FUN_0003b1c0(info->value, flag);
    return false;
}

}
}
