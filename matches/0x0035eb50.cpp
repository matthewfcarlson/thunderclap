#include "decls/address.h"
#include "decls/data/game/global.h"
// data: gPair = DAT_004e2550
struct Pair_35eb50 {
    unsigned int lo, hi;
};
void __cdecl FUN_0035eb50() {
    __int64 v = FUN_0027b020("mercyFuelRod2");
    (*(Pair_35eb50*)&DAT_004e2550) = *(Pair_35eb50*)&v;
}
