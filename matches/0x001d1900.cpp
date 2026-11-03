#include "compat/ptr.h"
#include "gen/owners.h"
extern "C" void __cdecl helper(hulk_intptr, int, int);
bool owners::Obj_1d1900::FUN_001d1900(hulk_intptr n) {
    if (((int)n) < 1)
        return false;
    helper(field, 0xffffd8f0, ((int)n));
    return true;
}