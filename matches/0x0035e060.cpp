#include "decls/data/game/DollyScript.h"
#include "decls/data/game/global.h"
// data: result = DAT_004e0a28

extern __int64 __cdecl getValue(const char*);
void target() {
    (*(__int64*)&DAT_004e0a28) = getValue(((char*)&DAT_00400488));
}