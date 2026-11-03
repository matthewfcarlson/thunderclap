#include "gen/owners.h"
void owners::Obj_2f2cb0::FUN_002f2cb0() {
    int* q = data;
    int n = 64;
    do {
        q[-3] = 0;
        q[-2] = 0;
        q[-1] = 0;
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q += 8;
    } while (--n);
    end = 0;
    finish();
}