// cl-flags: /O2
#include "decls/data/engine/fight.h"
// data: gHigh = DAT_004e5b9c, gValue = DAT_004ca298

struct Result {
    int lo;
    int hi;
};
Result FUN_002672f0(int a, int b, int c);

void target() {
    int a = DAT_004ca298;
    Result r = FUN_002672f0(a, 0, 0);
    (*(int*)&DAT_004e5b98) = r.lo;
    (*(int*)&DAT_004e5b9c) = r.hi;
}
