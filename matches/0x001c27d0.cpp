#include "compat/ptr.h"
#include "gen/owners.h"
bool owners::C_1c27d0::FUN_001c27d0(float* p) {
    int i = count - 1;
    if (i >= 0) {
        float* q = data + i * 4 + 1;
        do {
            hulk_freg s = q[0] * p[1] + q[1] * p[2] + q[-1] * p[0];
            if (!(s <= -q[2]))
                return false;
            --i;
            q -= 4;
        } while (i >= 0);
    }
    return true;
}