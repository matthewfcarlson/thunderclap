#include "gen/owners.h"
int owners::V_22d2b0::FUN_0022d2b0(owners::V_22d2b0* other, float limit) {
    float d = x - other->x;
    *(int*)&d &= 0x7fffffff;
    if (d <= limit) {
        d = y - other->y;
        *(int*)&d &= 0x7fffffff;
        if (d <= limit) {
            d = z - other->z;
            *(int*)&d &= 0x7fffffff;
            if (d <= limit)
                return 1;
        }
    }
    return 0;
}