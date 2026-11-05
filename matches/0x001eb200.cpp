// Same code shape as 0x00085cd0 (propagated); reads 0x004e36d8, a pointer item
#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" hulk_intptr FUN_001eb200(void) {
    return *(hulk_intptr*)&DAT_004e36d8;
}
