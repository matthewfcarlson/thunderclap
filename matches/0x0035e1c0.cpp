#include "decls/data/game/global.h"
// data: gValue = DAT_004e0a70

struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
extern "C" void __cdecl FUN_0035e1c0() {
    (*(Pair*)&DAT_004e0a70) = FUN_0027b020("$MACRO_INSERT");
}