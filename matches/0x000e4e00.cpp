#include "gen/global.h"

void FEContainer::vfunc_18(int item, int index) {
    if (!item)
        return;
    if (index >= 128)
        return;
    int found = 0;
    int* p = (*(int (*)[128])&this->f_4c) + 1;
    while (found < 128) {
        if (p[-1] == item)
            break;
        if (p[0] == item) {
            ++found;
            break;
        }
        if (p[1] == item) {
            found += 2;
            break;
        }
        if (p[2] == item) {
            found += 3;
            break;
        }
        found += 4;
        p += 4;
    }
    if (found >= 128)
        return;
    int tmp = (*(int (*)[128])&this->f_4c)[index];
    (*(int (*)[128])&this->f_4c)[index] = item;
    (*(int (*)[128])&this->f_4c)[found] = tmp;
}
