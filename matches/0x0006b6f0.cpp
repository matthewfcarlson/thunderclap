#include "compat/ptr.h"
#include "gen/owners.h"
extern hulk_freg __cdecl FUN_0004af40(float, float, float);
bool owners::C_6b6f0::FUN_0006b6f0(float x) {
    angle = FUN_0004af40(-180.0f, 180.0f, x) * 0.017453292f;
    return true;
}