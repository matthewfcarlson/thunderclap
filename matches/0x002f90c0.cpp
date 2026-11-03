#include "gen/owners.h"
bool owners::Vec_2f90c0::FUN_002f90c0(owners::Vec_2f90c0* b) {
    if (!(b->f[3] <= f[3]) || !(b->f[0] >= f[0]) || !(b->f[4] <= f[4]) || !(b->f[1] >= f[1]) ||
        !(b->f[5] <= f[5]) || !(b->f[2] >= f[2]))
        return false;
    return true;
}
