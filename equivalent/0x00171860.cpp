// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 8/8)
// hulkfight::motion::ChargeAction::vfunc_3 @ 0x00171860
// Charge action update: track which action step is running and publish its progress ratio.
#include "gen/hulkfight.h"

class ActionDef {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetLength();
    char pad4[0x14 - 4];
    int step;
    char restart;
    char pad19[3];
    float elapsed;
};

class Fighter_171860 {
public:
    char pad0[0x1e58];
    float baseline;
    int lastStep;
};

class FighterRef_171860 {
public:
    Fighter_171860* FUN_00059a30();
};

class Owner_171860 {
public:
    FighterRef_171860* FUN_000592a0();
};

bool hulkfight::motion::ChargeAction::vfunc_3(int a, int b) {
    Fighter_171860* fighter = (*(Owner_171860 * *)&this->f_20)->FUN_000592a0()->FUN_00059a30();
    int step = (*(ActionDef * *)&this->f_1c)->step;
    if ((*(ActionDef * *)&this->f_1c)->restart != 0 || step != fighter->lastStep) {
        fighter->baseline = 0;
    }
    fighter->lastStep = step;

    float length = (*(ActionDef * *)&this->f_1c)->GetLength();
    float elapsed = (*(ActionDef * *)&this->f_1c)->elapsed;
    if (length > 0.0f) {
        if (elapsed < 1.0f) {
            elapsed -= fighter->baseline;
        }
        this->f_24 = elapsed / length;
    } else {
        this->f_24 = elapsed;
    }
    return true;
}
