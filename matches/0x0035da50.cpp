#include "decls/data/game/global.h"
// data: gPair = DAT_004de710

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035da50() {
    (*(Pair*)&DAT_004de710) = FUN_0027b020("$MACRO_DEFINE");
}