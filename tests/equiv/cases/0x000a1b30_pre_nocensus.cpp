// FUN_000a1b30 @ 0x000a1b30
// (integ4, D152b) must not pass: the same contract without `// pre-callers:`: no drop (the census is the bar), L2 pre_census
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "compat/pre.h"
extern "C" int DAT_0049ec8c;
extern "C" float DAT_0049eca4;
struct Counter_a1b30 {
    int FUN_00026e30(float radius, void *list, int max);
};
struct Owner_a1b30 {
    char pad0[0x20];
    Counter_a1b30 *counter;
};
hulk_freg __cdecl FUN_0009faa0(float cur, float target, float dt, float rate);
class Smoother {
public:
    char pad0[0x345];
    char active;
    char pad346[2];
    char locked;
    char pad349[0x424 - 0x349];
    char list[4];
    int count;
    int nearA;
    int nearB;
    char pad434[8];
    float timer;
    float base;
    float value;
    float ratio;
    void FUN_000a1b30(Owner_a1b30 *owner, float dt, bool snap);
};
// (integ4, D152) a range contract: dt is the frame time (>= 0). It passes dt on to 0x0009faa0 as its frame time a, whose
// contract is ge(a, 0); a fuzzed negative dt made this block's original break that contract (pre_violation_in_original).
// pre: ge(arg2, 0) ge(*0x0049ec8c.f32, 0)
// pre-writers: 0x000a1c21 (the global's only reference, this block's read: nothing stores it; the XBE's .data holds 2.0)
void Smoother::FUN_000a1b30(Owner_a1b30 *owner, float dt, bool snap)
{
    HULK_PRE_GE(dt, 0.0f);
    HULK_PRE_GE(*(float*)&DAT_0049ec8c, 0.0f);
    if (snap)
        timer = 0.0f;

    if (active) {
        int n = owner->counter->FUN_00026e30(20.0f, list, 6);
        if (locked || (n > 0 && (nearA != 0 || nearB != 0 || count >= 3))) {
            timer = 3.0f;
        } else {
            timer = timer - dt;
            if (timer < 0.0f)
                timer = 0.0f;
        }
    } else {
        timer = 0.0f;
    }

    float target = base;
    if (timer > 0.0f)
        target = DAT_0049eca4 * base;

    if (snap) {
        value = target;
    } else if (!(target == value)) {
        value = FUN_0009faa0(value, target, dt, (*(float*)&DAT_0049ec8c));
        union { float f; unsigned int u; } d;
        d.f = value - target;
        d.u &= 0x7fffffff;
        if (d.f <= 0.00001f)
            value = target;
    }
    ratio = (value - base) / base * 10.0f;
}

