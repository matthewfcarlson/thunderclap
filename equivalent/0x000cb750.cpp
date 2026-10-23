// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 2/2)
// FUN_000cb750 @ 0x000cb750
#include "compat/ptr.h"
class Curve_cb750 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    virtual void v8();
    virtual void v9();
    virtual float v10(int value);
};

struct Bank {
    char pad00[0x24];
    Curve_cb750* curves[1];         // 0x24
    int FUN_000f7220(int a);
};

struct Slot_cb750 { float value; float pad[3]; };

struct Sampler_cb750 {
    Bank* bank;               // 0x00
    char pad04[4];
    Slot_cb750 slots[1];            // 0x08 (16 bytes each)
    char pad18[0x88 - 0x18];
    int current;              // 0x88
    hulk_freg Sample(int a, int b);
};

hulk_freg Sampler_cb750::Sample(int a, int b)
{
    if (a < 0)
        return 0.0f;
    Curve_cb750* curve = bank->curves[b];
    Curve_cb750* first = bank->curves[0];
    Slot_cb750* slot = &slots[current];
    float inv = 14.0f / first->v7();
    // the original loads the curve's vptr before the bank lookup call and the slot after it
    typedef float (__fastcall *EvalFn)(Curve_cb750*, int, int);
    void** vtable = *(void***)curve;
    int arg = bank->FUN_000f7220(a);
    return ((EvalFn)vtable[10])(curve, 0, arg) * slot->value * inv;
}
