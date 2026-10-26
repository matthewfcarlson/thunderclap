#include "decls/data/game/unknown.h"

struct Pair_35c7e0 {
    unsigned int lo;
    unsigned int hi;
};
extern "C" Pair_35c7e0 __cdecl FUN_0027b020(const char*);

void FUN_0035c7e0() {
    Pair_35c7e0 p = FUN_0027b020("blackhawk_leader");
    (*(unsigned int*)&DAT_004dc070) = p.lo;
    (*(unsigned int*)&DAT_004dc074) = p.hi;
}
