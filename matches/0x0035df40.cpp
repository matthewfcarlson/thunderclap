#include "decls/data/game/global.h"
// data: g_pair = DAT_004e09b0

extern "C" struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
void FUN_0035df40() {
    (*(Pair*)&DAT_004e09b0) = FUN_0027b020("$MACRO_INSERT");
}