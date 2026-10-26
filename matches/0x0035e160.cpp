#include "decls/data/game/global.h"
// data: input = DAT_00400488, result = DAT_004e0a78

extern "C" __int64 __cdecl parse(const void*);
void FUN_0035e160() {
    (*(__int64*)&DAT_004e0a78) = parse(((char*)&DAT_00400488));
}