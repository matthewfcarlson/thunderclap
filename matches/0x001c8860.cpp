#include "gen/owners.h"
void owners::C_1c8860::FUN_001c8860(int value) {
    unsigned int n = count;
    unsigned int i = 0;
    if (n > 0) {
        int* p = items;
        do {
            if (*p == value) {
                unsigned int m = n - 1;
                count = m;
                items[i] = items[m];
                return;
            }
            ++i;
            ++p;
        } while (i < count);
    }
}
