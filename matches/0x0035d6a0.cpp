#include "decls/data/game/global.h"
// data: gResult = DAT_004ddf88, gValue = DAT_0040048c

extern __int64 __cdecl getValue(int*);
void FUN_0035d6a0() {
    (*(__int64*)&DAT_004ddf88) = getValue(((int*)&DAT_0040048c));
}
