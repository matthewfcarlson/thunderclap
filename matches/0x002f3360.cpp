#include "gen/owners.h"
unsigned char owners::Box_2f3360::FUN_002f3360(owners::Box_2f3360* b) {
    return b->v[3] >= v[0] && b->v[0] <= v[3] && b->v[4] >= v[1] && b->v[1] <= v[4] && b->v[5] >= v[2] &&
           b->v[2] <= v[5];
}
