// STATUS: equivalent (tools/equiv.py level 3: 111 inputs, branch coverage 26/26)
// hulkfight::motion::PropMassCondition::vfunc_6 @ 0x001837e0
#include "decls/address.h"
struct Scaler_1837e0 {
    float FUN_001dd190(int lo, int hi);
};

struct World {
    char pad0[0xc];
    Scaler_1837e0 *scaler;
};

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v2();
};

struct Meter_1837e0 {
    float FUN_001d8160();
};

struct Fighter_1837e0 {
    char pad0[0x128];
    Meter_1837e0 *defaultMeter;
    Meter_1837e0 *FUN_00035ef0(int index);
};


void *__fastcall FUN_000592a0(void *owner);
Fighter_1837e0 *__fastcall FUN_00059a30(void *holder);
bool __cdecl FUN_00018960(float a, float b, float eps);

class PropMassCondition {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual bool vfunc_6(void *unused, fight::Params *params, int unused2);
    char pad04[0xc - 4];
    int slot;
    unsigned int mode;
    char pad14[4];
    int keyLo;
    int keyHi;
    float scale;
};

bool PropMassCondition::vfunc_6(void *unused, fight::Params *params, int unused2)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;
    Fighter_1837e0 *fighter = FUN_00059a30(FUN_000592a0(params));
    if (!fighter)
        return false;

    Meter_1837e0 *meter;
    if (slot < 0) {
        meter = fighter->defaultMeter;
    } else {
        if (slot >= 8)
            return false;
        meter = fighter->FUN_00035ef0(slot);
    }
    if (!meter)
        return false;

    float cur = meter->FUN_001d8160();
    float factor = 1.0f;
    if ((keyLo | keyHi) != 0)
        factor = DAT_004dd700->scaler->FUN_001dd190(keyLo, keyHi);
    float thr = factor * scale;
    switch (mode) {
    case 0:
        return cur < thr;
    case 1:
        return cur <= thr;
    case 2:
        return FUN_00018960(cur, thr, 1e-5f);
    case 3:
        return !FUN_00018960(cur, thr, 1e-5f);
    case 4:
        return cur > thr;
    case 5:
        return cur > thr;
    }
    return false;
}
