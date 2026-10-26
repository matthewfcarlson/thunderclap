#include "decls/data/game/DollyScript.h"
#include "decls/data/game/global.h"
// data: g_lo_35dfe0 = DAT_004e0a08, hulk_at_00400488 = DAT_00400488

#include "compat/ptr.h"
struct Hash_35dfe0 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Hash_35dfe0 __cdecl FUN_0027b020(const char*);

void __cdecl FUN_0035dfe0() {
    Hash_35dfe0 h = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_00400488)));
    (*(unsigned int*)&DAT_004e0a08) = h.lo;
    (*(unsigned int*)((char*)&DAT_004e0a08 + 4)) = h.hi;
}
