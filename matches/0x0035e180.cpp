#include "decls/data/game/global.h"
// data: result = DAT_004e0a80, text = DAT_0040048c

extern "C" __int64 __cdecl getValue(const char*);
void FUN_0035e180() {
    (*(__int64*)&DAT_004e0a80) = getValue(DAT_0040048c);
}