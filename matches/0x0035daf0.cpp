#include "decls/data/game/global.h"
// data: result = DAT_004de6d8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035daf0() {
    (*(Pair*)&DAT_004de6d8) = FUN_0027b020("ClearAfterEntry");
}