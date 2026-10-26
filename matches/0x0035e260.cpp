#include "decls/data/game/hulkfight/ai.h"
// data: gPair = DAT_004e0d28

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e260() {
    (*(Pair*)&DAT_004e0d28) = FUN_0027b020("routing");
}