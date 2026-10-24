#include "gen/global.h"

int CWorldStreamManager::FUN_002042a0(int param_2, int param_3) {
    int n = this->f_594;
    int found = 0;
    int i = 0;
    if (n > 0) {
        short* base = (*(short * *)&this->f_58c);
        short* p = base;
        do {
            if (*p == param_3) {
                if (found == param_2)
                    return base[i * 0x2b + 1];
                ++found;
            }
            ++i;
            p += 0x2b;
        } while (i < n);
    }
    return -1;
}
