#include "decls/data/game/global.h"

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035c980() {
    (*(Pair*)&DAT_004dc080) = FUN_0027b020("mercy");
}