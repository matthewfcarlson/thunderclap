// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 22/22)
// hulkfight::ai::HulkActionCountCondition::vfunc_6 @ 0x0010ec90
#include "decls/data/game/hulkfight/ai.h"

extern "C" int atexit(void (*)());

struct Key_10ec90 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(int word);
};

void FUN_00363e70();
bool __cdecl FUN_00018960(float a, float b, float eps);

struct Fighter_10ec90 {
};

struct Holder_10ec90 {
    Fighter_10ec90 *FUN_00059a30();
};

struct Stats_10ec90 {
    void FUN_00067730();
    float FUN_00067110(Key_10ec90 *k);
};

Stats_10ec90 *FUN_000678d0();

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    Holder_10ec90 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v2();
};

class HulkActionCountCondition {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual bool FUN_0010ec90(int a1, fight::Params *params, int a3);
    char pad4[8];
    unsigned mode;
    int keyword;
    float threshold;
};

bool HulkActionCountCondition::FUN_0010ec90(int a1, fight::Params *params, int a3)
{
    if (((*(unsigned*)&DAT_004e0bb8) & 1) == 0) {
        (*(unsigned*)&DAT_004e0bb8) |= 1;
        (*(Key_10ec90*)&DAT_004e0bb0).FUN_0027af00();
        atexit(FUN_00363e70);
    }
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Fighter_10ec90 *fighter = params->FUN_000592a0()->FUN_00059a30();
    if (fighter == 0)
        return false;

    FUN_000678d0()->FUN_00067730();

    (*(Key_10ec90*)&DAT_004e0bb0).FUN_0027b040(keyword);

    Key_10ec90 k;
    k.lo = (*(Key_10ec90*)&DAT_004e0bb0).lo;
    k.hi = (*(Key_10ec90*)&DAT_004e0bb0).hi;
    float value = FUN_000678d0()->FUN_00067110(&k);

    if (threshold < 0.0f)
        return true;

    switch (mode) {
    case 0:
        return value < threshold;
    case 1:
        return value <= threshold;
    case 2:
        return FUN_00018960(value, threshold, 1e-05f);
    case 3:
        return !FUN_00018960(value, threshold, 1e-05f);
    case 4:
        return value >= threshold;
    case 5:
        return value > threshold;
    }
    return false;
}
