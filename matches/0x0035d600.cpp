#include "decls/data/game/global.h"

struct Pair_35d600 {
    int a;
    int b;
};
extern "C" Pair_35d600 __cdecl FUN_0027b020(const char*);
void FUN_0035d600() {
    Pair_35d600 r = FUN_0027b020(((char*)&DAT_004004a0));
    *(int*)((char*)&DAT_004ddf38) = r.a;
    *(int*)((char*)&DAT_004ddf3c) = r.b;
}
