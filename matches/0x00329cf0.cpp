#include "gen/owners.h"
extern int gFlags_329cf0;
extern int gCache_329cf0[4096];
void owners::C_329cf0::FUN_00329cf0(int index, int value1, int value2) {
    if (a[index] != value1) {
        a[index] = value1;
        gFlags_329cf0 |= 0x800;
        gCache_329cf0[index * 32] = value1;
    }
    if (b[index] != value2) {
        b[index] = value2;
        gFlags_329cf0 |= 0x800;
        gCache_329cf0[index * 32 + 2] = value2;
    }
}