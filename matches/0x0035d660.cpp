#include "decls/data/game/global.h"
// data: result = DAT_004ddf58

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl lookup(const char*);
void FUN_0035d660() {
    (*(Pair*)&DAT_004ddf58) = lookup("AddTextInput");
}