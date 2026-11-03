#include "gen/owners.h"
extern const float limit = -1.0f;
void owners::Obj_e86a0::FUN_000e86a0(float x) {
    input = x;
    if (value > limit && x > limit) {
        int r;
        if (value <= x)
            r = 1;
        else
            r = 0;
        flag = (unsigned char)r;
    }
}
