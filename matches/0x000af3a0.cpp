// Same code shape as 0x000ae640 (propagated; names are from that function)
#include "gen/owners.h"
hulk_intptr owners::C_af3a0::FUN_000af3a0(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}