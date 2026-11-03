#include "gen/owners.h"
typedef unsigned char u8_38e30;
extern "C" u8_38e30 __cdecl FUN_002029e0(int, int, int, int, int, int);
u8_38e30 owners::Obj_38e30::FUN_00038e30(hulk_intptr a, hulk_intptr b, int c, int d, hulk_intptr e, hulk_intptr f) {
    Gate(0);
    u8_38e30 r = FUN_002029e0(((int)a), ((int)b), c, d, ((int)e), ((int)f));
    Gate(1);
    return r;
}