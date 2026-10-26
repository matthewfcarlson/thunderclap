#include "decls/data/game/global.h"
// data: gPair = DAT_004de6c8

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d990() {
    (*(Pair*)&DAT_004de6c8) = FUN_0027b020("MemcardSelectLocators");
}