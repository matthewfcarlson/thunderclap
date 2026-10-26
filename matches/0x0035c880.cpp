#include "decls/data/game/global.h"
// data: result = DAT_004dc078

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035c880() {
    (*(Pair*)&DAT_004dc078) = FUN_0027b020("mlrs");
}