#include "gen/global.h"

void FEContainer::vfunc_19(int p) {
    if (p) {
        int i = 0;
        int* q = (int*)((char*)this + 0x50);
        do {
            if (q[-1] == p)
                break;
            if (q[0] == p) {
                i += 1;
                break;
            }
            if (q[1] == p) {
                i += 2;
                break;
            }
            if (q[2] == p) {
                i += 3;
                break;
            }
            i += 4;
            q += 4;
        } while (i < 0x80);
        if (i < 0x80)
            *(int*)((char*)this + 0x48) = p;
    }
}
