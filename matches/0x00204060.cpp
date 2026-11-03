#include "gen/owners.h"
short* owners::Owner_204060::FUN_00204060(int a, int b) {
    if (a < 0 || b < 0)
        return 0;
    int i = 0;
    if (count > 0) {
        short* p = items;
        do {
            if (a == p[0] && b == p[1])
                return items + i * 0x2b;
            ++i;
            p += 0x2b;
        } while (i < count);
    }
    return 0;
}