// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000d4900 @ 0x000d4900
#include "decls/data/game/global.h"

struct Curve {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
    virtual float slot7(); virtual void slot8(); virtual float slot9(float);
};
struct Sample { float gain; char padding[12]; };
struct Player {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9();
    char padding[4];
    Sample samples[8];
    int activeSample;
    float FUN_000d4900(float input, int index);
};
float Player::FUN_000d4900(float input, int index)
{
    void **table = *(void ***)this;
    Curve *first = (Curve *)table[9];
    Curve *chosen = (Curve *)table[9 + index];
    Sample *sample = &samples[activeSample];
    float factor = DAT_0040cc38 / first->slot7();
    float output = chosen->slot9(input);
    return output * sample->gain * factor;
}
