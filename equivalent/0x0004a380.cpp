// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CMotionHitCondition::vfunc_7 @ 0x0004a380
struct Fighter {
    char pad0[0x144];
    unsigned int hits;
};

struct Anchor {
    Fighter *FUN_00059a30();
};

struct FightHandle {
    Anchor *FUN_000592a0();
};

class CMotionHitCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(FightHandle *h);
    char pad04[0xc - 4];
    int mode;
    unsigned int index;
};

bool CMotionHitCondition::vfunc_7(FightHandle *h)
{
    Fighter *f = h->FUN_000592a0()->FUN_00059a30();
    unsigned int mask = 0;
    if (index != 0)
        mask = 1u << (index - 1);
    unsigned int hits = f->hits;
    if (mask == 0) {
        if (mode == 0)
            return hits == 0;
        if (mode == 1)
            return hits != 0;
        return false;
    }
    if (mode == 0)
        return (hits & mask) != 0;
    if (mode == 1)
        return (hits & mask) == 0;
    return false;
}
