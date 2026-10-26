#include "decls/data/game/hulkfight/ai.h"
// data: result = DAT_004e0cf0

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035e2c0() {
    (*(Pair*)&DAT_004e0cf0) = FUN_0027b020("locator");
}