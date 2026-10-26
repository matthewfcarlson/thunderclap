#include "decls/data/game/global.h"

struct Pair_35df20 {
    int lo;
    int hi;
};
extern "C" Pair_35df20 __cdecl DEFINE(const char* name);
void __cdecl FUN_0035df20() {
    Pair_35df20 r = DEFINE("$MACRO_DEFINE");
    *(int*)((char*)&DAT_004e09c8) = r.lo;
    *(int*)((char*)&DAT_004e09cc) = r.hi;
}
