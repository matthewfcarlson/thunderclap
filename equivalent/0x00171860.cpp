// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 8/8)
// hulkfight::motion::ChargeAction::vfunc_3 @ 0x00171860
// Charge action update: track which action step is running and publish its progress ratio.
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

class ChargeAction {
public:
    char pad0[0x1c];
    ActionDef* def;
    Owner_171860* owner;
    float progress;

    bool FUN_00171860(int a, int b);
};

bool ChargeAction::FUN_00171860(int a, int b)
{
    Fighter_171860* fighter = owner->FUN_000592a0()->FUN_00059a30();
    int step = def->step;
    if (def->restart != 0 || step != fighter->lastStep) {
        fighter->baseline = 0;
    }
    fighter->lastStep = step;

    float length = def->GetLength();
    float elapsed = def->elapsed;
    if (length > 0.0f) {
        if (elapsed < 1.0f) {
            elapsed -= fighter->baseline;
        }
        progress = elapsed / length;
    } else {
        progress = elapsed;
    }
    return true;
}
