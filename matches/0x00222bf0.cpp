#include "gen/owners.h"
int owners::A_222bf0::FUN_00222bf0(hulk_intptr key) {
    unsigned n = count;
    unsigned i = 0;
    if (n > 0) {
        int k = ((int)key);
        int* p = (int*)((char*)this + 0x6c);
        do {
            if (*p == k)
                return p[5];
            ++i;
            p += 10;
        } while (i < n);
    }
    return 0;
}