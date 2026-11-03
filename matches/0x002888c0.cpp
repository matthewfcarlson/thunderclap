#include "gen/owners.h"
hulk_intptr owners::C_2888c0::FUN_002888c0(unsigned n, unsigned x) {
    if (n > 0) {
        unsigned i = (x != 7);
        unsigned t = (a[i] + x) & ~x;
        unsigned r = b[i] + t;
        a[i] = t + n;
        return r;
    }
    return 0;
}