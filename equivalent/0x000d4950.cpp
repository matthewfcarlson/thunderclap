// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_000d4950 @ 0x000d4950
#include "compat/ptr.h"
struct Interface {
    virtual void unused0(); virtual void unused1(); virtual void unused2();
    virtual void unused3(); virtual void unused4(); virtual void unused5();
    virtual void unused6(); virtual float getDivisor();
    virtual void unused8(); virtual void unused9();
    virtual float evaluate(float value);
};
struct Record { float weight; char unused[12]; };
struct Owner {
    Interface **entries;
    char unused[4];
    Record records[8];
    int active;
    double FUN_000d4950(float value, int index);
};
double Owner::FUN_000d4950(float value, int index)
{
    Interface *selected = entries[9 + index];
    float *weight = &records[active].weight;
    hulk_freg divisor = entries[9]->getDivisor();
    hulk_freg ratio = 14.0f / divisor;
    return (double)selected->evaluate(value) * *weight * ratio;
}