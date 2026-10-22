// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 14/14)
// FUN_00035b70 @ 0x00035b70
#include "compat/ptr.h"
struct State_35b70 {
    char pad[0x308];
    float start, duration, end;
    void FUN_00035b70(float a, float b, float c);
};
void State_35b70::FUN_00035b70(float a, float b, float c) {
    if (b <= 0.0f)
        return;
    hulk_freg len = b;
    hulk_freg stop = c;
    if (start > 0.0f && a > start) {
        len = len - (a - start);
    } else
        start = a;
    if (duration > 0.0f && len < duration) {
        stop = stop - (duration - len);
    } else
        duration = len;
    if (!(end > 0.0f) || !(stop > end))
        end = stop;
}
