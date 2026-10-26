#include "decls/data/game/global.h"

struct Handle_35ecf0 {
    int lo, hi;
};
extern "C" Handle_35ecf0 __cdecl FUN_0027b020(const char*);
void __cdecl FUN_0035ecf0() {
    Handle_35ecf0 h = FUN_0027b020("golfBall_golfBall");
    (*(int*)&DAT_004e2640) = h.lo;
    (*(int*)&DAT_004e2644) = h.hi;
}
