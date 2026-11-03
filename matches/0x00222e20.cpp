#include "gen/owners.h"
hulk_uintptr owners::C_222e20::FUN_00222e20(unsigned i) {
    if (i < count)
        return *(unsigned*)(rest + i * 0x28);
    return 0;
}