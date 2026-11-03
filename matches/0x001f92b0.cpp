#include "gen/owners.h"
typedef unsigned int uint_1f92b0;
struct Thing_1f92b0 {
    char pad[0x10];
};
uint_1f92b0 FUN_001f92b0(Thing_1f92b0* a, Thing_1f92b0* b) {
    Thing_1f92b0* x = (Thing_1f92b0*)((char*)b + 0x10);
    Thing_1f92b0* y = (Thing_1f92b0*)((char*)a + 0x10);
    if (((owners::Key_1f84d0 *)y)->FUN_001f84d0((const owners::Key_1f84d0 *)(Thing_1f92b0 *)x))
        return 0xffffffff;
    return ((owners::Key_1f84d0 *)x)->FUN_001f84d0((const owners::Key_1f84d0 *)(Thing_1f92b0 *)y) != 0;
}