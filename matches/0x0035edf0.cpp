#include "decls/data/game/global.h"
// data: gPair = DAT_004e3700

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035edf0() {
    (*(Pair*)&DAT_004e3700) = FUN_0027b020("golfBall_golfBall");
}