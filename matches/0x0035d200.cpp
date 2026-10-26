#include "decls/data/game/hulkfight.h"
// data: hulk_at_004dd940 = DAT_004dd940

#include "compat/ptr.h"
extern "C" double __cdecl cos(double);
extern "C" void __cdecl FUN_0035d200() {
    double r = cos(0.017453293005625408);
    *(volatile float*)((hulk_intptr)((char*)&DAT_004dd940)) = 1.0f - (hulk_freg)r;
}
