#include "gen/owners.h"
void owners::X_232600::FUN_00232600(unsigned int mask, bool enabled) {
    if (enabled)
        flags |= mask;
    else
        flags &= ~mask;
}