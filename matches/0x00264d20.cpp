#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"
#include "decls/data/records.h"
// data: g_cur_264d20 = DAT_00527c4c, g_obj_264d20 = DAT_00527c28
#include "gen/owners.h"

extern "C" CoreFiber* __cdecl FUN_0026dbf0();
extern "C" void* __cdecl FUN_00266da0(void*);
extern "C" void __cdecl FUN_0026dc00(CoreFiber*);

// the content loader's yield: from the game's fiber (0x00527c4c) to the loader's fiber when there is work, and back
// from the loader's; each side keeps its current heap (0x00527c50 / 0x00527c54)
void owners::Q_264d20::FUN_00264d20() {
    if (FUN_0026dbf0() == (*(CoreFiber**)&DAT_00527c4c)) {
        unsigned s = m14;
        unsigned e = m18;
        int n;
        if (s <= e) {
            n = (int)(e - s) >> 3;
        } else {
            n = ((int)(e - m1c) >> 3) + ((int)(m20 - s) >> 3);
        }
        if ((unsigned)n > 0 || m8 != 0) {
            (*(void**)&DAT_00527c54) = FUN_00266da0((*(void**)&DAT_00527c50));
            FUN_0026dc00(&DAT_00527c28);
        }
    } else {
        (*(void**)&DAT_00527c50) = FUN_00266da0((*(void**)&DAT_00527c54));
        FUN_0026dc00((*(CoreFiber**)&DAT_00527c4c));
    }
}
