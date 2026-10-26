#include "decls/address.h"
#include "decls/data/game/global.h"
typedef unsigned __int64 U64_35d3c0;

void __cdecl FUN_0035d3c0() {
    U64_35d3c0 r = FUN_0027b020("$MACRO_DEFINE");
    (*(int*)&DAT_004ddc10) = (int)r;
    (*(int*)&DAT_004ddc14) = (int)(r >> 32);
}
