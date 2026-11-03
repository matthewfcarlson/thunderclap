#include "gen/owners.h"
void owners::Obj_2988e0::FUN_002988e0() {
    unsigned int n = (end - start) / 12;
    unsigned int i = 0;
    if (n != 0) {
        do {
            a[i] = 0xff;
            b[i] = 0xff;
            ++i;
        } while (i < n);
    }
    flag = 0;
}