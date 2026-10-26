#include "decls/data/game/global.h"
// data: g_hash_35ca50 = DAT_004dced0

struct Pair_35ca50 {
    int a;
    int b;
};
extern "C" Pair_35ca50 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035ca50() {
    (*(Pair_35ca50*)&DAT_004dced0) = FUN_0027b020("jumping");
}
