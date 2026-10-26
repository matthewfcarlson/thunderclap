#include "decls/data/game/global.h"

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const int*);
void FUN_0035db90() {
    (*(Pair*)&DAT_004de750) = FUN_0027b020(((const int*)&DAT_00400488));
}