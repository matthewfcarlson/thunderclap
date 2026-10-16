#include "decls/address.h"
typedef unsigned __int64 U64_35d3c0;
extern int gMac1;
extern int gMac2;

void __cdecl FUN_0035d3c0() {
    U64_35d3c0 r = FUN_0027b020("$MACRO_DEFINE");
    gMac1 = (int)r;
    gMac2 = (int)(r >> 32);
}
