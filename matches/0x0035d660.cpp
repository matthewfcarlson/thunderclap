#include "decls/data/game/global.h"
// data: result = DAT_004ddf58

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035d660() {
    (*(Pair*)&DAT_004ddf58) = FUN_0027b020("AddTextInput");
}