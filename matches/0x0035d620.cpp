#include "decls/data/game/global.h"

struct Pair_35d620 {
    int a;
    int b;
};
extern Pair_35d620 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035d620() {
    Pair_35d620 p = FUN_0027b020("AddBackground");
    (*(int*)&DAT_004ddf30) = p.a;
    (*(int*)((char*)&DAT_004ddf30 + 4)) = p.b;
}
