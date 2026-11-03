#include "gen/owners.h"
void owners::Bag_1c8810::FUN_001c8810(hulk_intptr value) {
    if (((int)value) != 0) {
        unsigned int n = count;
        unsigned int i = 0;
        if (n > 0) {
            int* p = items;
            do {
                if (*p == ((int)value))
                    return;
                ++i;
                ++p;
            } while (i < count);
        }
        if (n < 0x100) {
            count = n + 1;
            items[n] = ((int)value);
        }
    }
}