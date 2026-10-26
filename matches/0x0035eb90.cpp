#include "decls/data/game/global.h"
// data: gPair = DAT_004e2520

struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
extern "C" void FUN_0035eb90() {
    (*(Pair*)&DAT_004e2520) = FUN_0027b020("mercyFuelRod4");
}