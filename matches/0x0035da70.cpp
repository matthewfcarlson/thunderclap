#include "decls/data/game/global.h"
// data: gPair = DAT_004de6e8

struct Pair {
    unsigned a;
    unsigned b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035da70() {
    (*(Pair*)&DAT_004de6e8) = FUN_0027b020("$MACRO_INSERT");
}