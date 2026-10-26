#include "decls/data/game/global.h"
// data: gPair = DAT_004e2208

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e670() {
    (*(Pair*)&DAT_004e2208) = FUN_0027b020("golfBall_golfBall");
}