// cl-flags: /O2
#include "decls/data/game/global.h"
// data: gValue_79370 = DAT_004dd040

extern "C" void __stdcall FUN_00079370(int v) {
    if (v <= 0x14)
        DAT_004dd040 = v;
}