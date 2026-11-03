// Same code shape as 0x000ae640 (propagated; names are from that function)
#include "gen/owners.h"
hulk_intptr owners::C_b3d20::FUN_000b3d20(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}