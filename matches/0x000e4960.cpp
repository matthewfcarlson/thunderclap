#include "gen/global.h"

void FEContainer::vfunc_20(int value) {
    int i = 0;
    int* p = &(*(int (*)[128])&this->f_64c)[1];
    do {
        if (p[-1] == 0)
            break;
        if (p[0] == 0) {
            ++i;
            break;
        }
        if (p[1] == 0) {
            i += 2;
            break;
        }
        if (p[2] == 0) {
            i += 3;
            break;
        }
        i += 4;
        p += 4;
    } while (i < 0x80);
    if (i != 0x80)
        (*(int (*)[128])&this->f_64c)[i] = value;
}
