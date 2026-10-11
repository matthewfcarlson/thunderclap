// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 22/24, incomplete)
// hulkfight::ai::KeyWordWaitCondition::vfunc_6 @ 0x0010f630
extern "C" int atexit(void (*)());

struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(int word);
};

extern unsigned DAT_004e0c20;
extern Key DAT_004e0c18;
void FUN_00363ef0();

struct Fighter {
    float FUN_00037290(unsigned lo, unsigned hi);
};

struct Holder {
    Fighter *FUN_00059a30();
};

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    Holder *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v2();
};

class KeyWordWaitCondition {
  public:
    char pad0[0xc];
    unsigned mode;
    int keyword;
    float threshold;

    bool FUN_0010f630(int a1, fight::Params *params, int a3);
};

bool KeyWordWaitCondition::FUN_0010f630(int a1, fight::Params *params, int a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Fighter *fighter = params->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;

    if ((DAT_004e0c20 & 1) == 0) {
        DAT_004e0c20 |= 1;
        DAT_004e0c18.FUN_0027af00();
        atexit(FUN_00363ef0);
    }
    DAT_004e0c18.FUN_0027b040(keyword);

    float limit = threshold;
    float value = fighter->FUN_00037290(DAT_004e0c18.lo, DAT_004e0c18.hi);

    switch (mode) {
    case 0:
        return value < limit;
    case 1:
        return value <= limit;
    case 2:
        return value == limit;
    case 3:
        return value != limit;
    case 4:
        return value >= limit;
    case 5:
        return value > limit;
    }
    return false;
}
