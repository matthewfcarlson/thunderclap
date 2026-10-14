// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::PropIsAttachedCondition::vfunc_6 @ 0x001819f0
namespace fight {
class Params {
public:
    virtual void v0();
};
}

class CFightParams : public fight::Params {
public:
    virtual void v1();
};

struct Fighter_1819f0 {
    char pad0[0x128];
    void *f128;
    void *FUN_00035ef0(int slot);
};

struct Anchor_1819f0 {
    Fighter_1819f0 *FUN_00059a30();
};

struct FightHandle {
    Anchor_1819f0 *FUN_000592a0();
};

namespace hulkfight {
namespace motion {
class PropIsAttachedCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0xc - 4];
    int slot;
    unsigned char expected;
};
}
}

bool hulkfight::motion::PropIsAttachedCondition::vfunc_6(int a, fight::Params *params, int c)
{
    CFightParams *fp = dynamic_cast<CFightParams *>(params);
    if (fp == 0)
        return false;
    Fighter_1819f0 *f = ((FightHandle *)params)->FUN_000592a0()->FUN_00059a30();
    void *prop = 0;
    if (f != 0) {
        if (slot < 0)
            prop = f->f128;
        else if (slot < 8)
            prop = f->FUN_00035ef0(slot);
    }
    return (prop != 0) == expected;
}
