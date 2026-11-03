// cl-flags: /O2
#include "gen/owners.h"

char owners::C_192df0::FUN_00192df0(const void* p) {
    const unsigned int* q = (const unsigned int*)p;
    *(unsigned int*)m100 = q[0];
    *(unsigned int*)m104 = q[1];
    *(unsigned int*)m108 = q[2];
    return 1;
}
