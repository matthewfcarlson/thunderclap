#include "decls/data/game/global.h"
// data: result = DAT_004dcee0

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035ca30() {
    (*(Pair*)&DAT_004dcee0) = FUN_0027b020("squad");
}