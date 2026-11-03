#include "gen/owners.h"
extern "C" int FUN_000969d0(int);
bool owners::Thing_35c30::FUN_00035c30(hulk_intptr x) {
    int v = FUN_000969d0(((int)x));
    int i = 0;
    if (count > 0) {
        do {
            if (values[i] == v)
                return true;
            ++i;
        } while (i < count);
    }
    return false;
}