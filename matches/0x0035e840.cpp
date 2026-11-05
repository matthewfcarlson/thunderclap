#include "decls/data/game/global.h"
// data: gHandle = DAT_004e2440

struct Handle_35e840 {
    int lo;
    int hi;
};
unsigned __int64 FUN_0027b020(const char* s);
void FUN_0035e840() {
    (*(unsigned __int64*)&DAT_004e2440) = FUN_0027b020("golfBall_golfBall");
}
