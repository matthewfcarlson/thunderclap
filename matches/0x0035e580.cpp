#include "decls/data/game/global.h"
// data: gPair = DAT_004e1828

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e580() {
    (*(Pair*)&DAT_004e1828) = FUN_0027b020("golfBall_golfBall");
}