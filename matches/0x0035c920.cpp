#include "decls/data/game/hulkfight.h"
// data: globalPair = DAT_004dc0a8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl Lookup(const char*);
void FUN_0035c920() {
    (*(Pair*)&DAT_004dc0a8) = Lookup("destroyer");
}