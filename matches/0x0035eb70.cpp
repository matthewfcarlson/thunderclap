#include "decls/data/game/global.h"
// data: g_pair = DAT_004e2558

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035eb70() {
    (*(Pair*)&DAT_004e2558) = FUN_0027b020("mercyFuelRod3");
}