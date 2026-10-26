#include "decls/data/game/DollyScript.h"
// data: gResult = DAT_004e0a18

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e020() {
    (*(Pair*)&DAT_004e0a18) = FUN_0027b020("$MACRO_DEFINE");
}