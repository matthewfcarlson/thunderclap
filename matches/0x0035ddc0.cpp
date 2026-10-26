#include "decls/data/game/global.h"
// data: gName = DAT_00400488, gResult = DAT_004de970

extern __int64 __cdecl lookup(const char*);
void FUN_0035ddc0() {
    (*(__int64*)&DAT_004de970) = lookup(DAT_00400488);
}
