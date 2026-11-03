#include "gen/owners.h"
struct Item_adc30 {
};
struct Obj_adc30 {
    char pad[0x10];
    int count;
    Item_adc30** items;
    int run();
};
int Obj_adc30::run() {
    int n = count;
    int i = 0;
    if (n > 0) {
        Item_adc30** base = items;
        Item_adc30** p = base;
        do {
            if (*p != 0)
                return ((int)((owners::C_b0ef0 *)(base[i]))->FUN_000b0ef0());
            ++i;
            ++p;
        } while (i < n);
    }
    return 1;
}
