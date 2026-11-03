#include "gen/owners.h"

void owners::C_3012d0::FUN_003012d0(hulk_intptr a, hulk_intptr b) {
    if (!Check(((int)a), ((int)b))) {
        Pair(((int)a), ((int)b));
        Pair(((int)b), ((int)a));
        Finish(((int)a), ((int)b));
    }
}