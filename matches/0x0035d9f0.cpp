#include "decls/data/game/global.h"
// data: result = DAT_004de680

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d9f0() {
    (*(Pair*)&DAT_004de680) = FUN_0027b020("GoToSim");
}