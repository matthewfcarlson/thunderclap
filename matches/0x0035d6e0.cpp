#include "decls/data/game/global.h"
// data: gPair = DAT_004ddf78

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d6e0() {
    (*(Pair*)&DAT_004ddf78) = FUN_0027b020("$MACRO_INSERT");
}