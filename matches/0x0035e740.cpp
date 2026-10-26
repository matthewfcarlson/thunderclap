#include "decls/data/game/global.h"
// data: gPair = DAT_004e2298

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e740() {
    (*(Pair*)&DAT_004e2298) = FUN_0027b020("}");
}