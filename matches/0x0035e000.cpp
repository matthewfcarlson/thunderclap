#include "decls/data/game/DollyScript.h"
#include "decls/data/game/global.h"
// data: g_guid = DAT_004e0a10, hulk_at_0040048c = DAT_0040048c

#include "compat/ptr.h"
#include "decls/address.h"
struct G {
    __int64 v;
};
void FUN_0035e000() {
    (*(G*)&DAT_004e0a10).v = FUN_0027b020((const char*)((hulk_intptr)((char*)&DAT_0040048c)));
}
