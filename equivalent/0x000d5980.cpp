// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 13/16, incomplete)
// MessageOverlay::vfunc_3 @ 0x000d5980
#include "decls/data/game/global.h"

extern "C" double sin(double);
extern "C" double fabs(double);


struct Slot_d5980 {
    float from[3];
    float to[3];
    float cur;
    float limit;
    char pad0[0x34 - 0x20];
    char active;
    char pad1[0x23c - 0x35];
};

class Overlay {
public:
    virtual void vfunc_0();
};

class MessageOverlay : public Overlay {
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(float dt);
    virtual void vfunc_4();
    virtual void vfunc_5();

    void FUN_000d49b0(float *a, float *b);
    void FUN_000d5290(float dt);

    // The slot array and the timers overlap in the original layout, so
    // fields are reached through typed accessors on the raw bytes.
    char raw[0x808 - 4];

    Slot_d5980 *slot(int i) { return (Slot_d5980 *)(raw + (0x214 - 4) + i * 0x23c); }
    float *floatAt(int off) { return (float *)(raw + (off - 4)); }
    char *byteAt(int off) { return raw + (off - 4); }
};

void MessageOverlay::vfunc_3(float dt)
{
    float margin = DAT_004a06b8 + DAT_004a06ac + DAT_004a06a8;
    if (*byteAt(0x7bc))
        return;
    for (int i = 0; i < 2; i++) {
        Slot_d5980 *s = slot(i);
        if (s->active) {
            FUN_000d49b0(s->to, s->from);
            float d = *floatAt(0x7cc) - DAT_004a06d4;
            if (fabs(d) <= 1e-5f)
                s->cur += dt;
            if (margin + s->limit < s->cur)
                s->active = 0;
        }
    }
    *floatAt(0x590) += dt;
    *floatAt(0x69c) += dt;
    *floatAt(0x7a8) += dt;
    FUN_000d5290(dt);
    float phase = dt * 6.2831855f + *floatAt(0x804);
    *floatAt(0x7fc) = ((float)sin(phase) + 1.0f) * 0.5f;
    int turns = (int)(phase * 0.15915494f);
    *floatAt(0x804) = phase - (float)turns * 6.2831855f;
    float v = *floatAt(0x804);
    if (v >= 0.0f && v <= 6.2831855f)
        *floatAt(0x804) = v;
    else if (!(v > 6.2831855f))
        *floatAt(0x804) = 0.0f;
    else
        *floatAt(0x804) = 6.2831855f;
}
