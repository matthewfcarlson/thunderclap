#include "decls/data/game/DollyScript.h"

typedef struct {
    unsigned lo;
    unsigned hi;
} Pair_35e120;
extern Pair_35e120 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035e120() {
    Pair_35e120 r = FUN_0027b020("$MACRO_DEFINE");
    (*(unsigned*)&DAT_004e0a58) = r.lo;
    (*(unsigned*)&DAT_004e0a5c) = r.hi;
}
