// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// hulkfight::motion::CSMPropIsCharacterCondition::vfunc_6 @ 0x00181a70
extern char DAT_00494b44[];
extern char DAT_00494b60[];
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Stats;

struct Ctx {
    Stats *FUN_00059a30();
};

class Owner {
public:
    Ctx *FUN_000592a0();
};

struct Target {
    char pad0[0x148];
    int f148;
};

struct Stats {
    char pad0[0x3a4];
    struct Slot {
        char pad0[8];
        Target *f8;
        int fc;
    } *f3a4;
};

class CSMPropIsCharacterCondition {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(int a1, Owner *owner, int a3);
    char pad4[8];
    unsigned char fc_flag;
};

bool CSMPropIsCharacterCondition::vfunc_6(int a1, Owner *owner, int a3)
{
    if (FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    Stats::Slot *slot = owner->FUN_000592a0()->FUN_00059a30()->f3a4;
    if (slot == 0 || slot->fc != 5)
        return false;
    return (slot->f8->f148 != 0) == (int)fc_flag;
}
