#include "decls/address.h"
struct Pair_35eb50 {
    unsigned int lo, hi;
};
extern Pair_35eb50 gPair;
void __cdecl FUN_0035eb50() {
    __int64 v = FUN_0027b020("mercyFuelRod2");
    gPair = *(Pair_35eb50*)&v;
}
