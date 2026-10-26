#include "decls/data/game/global.h"

extern "C" {
struct Pair {
    unsigned a, b;
};
Pair FUN_0027b020(const char*);
}
void FUN_0035c840() {
    (*(Pair*)&DAT_004dc0c0) = FUN_0027b020("tank");
}