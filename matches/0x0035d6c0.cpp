#include "decls/data/game/global.h"
// data: macroValue = DAT_004ddf90

extern "C" __int64 __cdecl findMacro(const char*);
extern "C" void __cdecl FUN_0035d6c0() {
    (*(__int64*)&DAT_004ddf90) = findMacro("$MACRO_DEFINE");
}