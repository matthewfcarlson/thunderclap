#include "decls/data/game/global.h"
// data: gHandle = DAT_004e2440

struct Handle_35e840 {
    int lo;
    int hi;
};
extern "C" Handle_35e840 __cdecl FindHandle(const char* name);
void FUN_0035e840() {
    (*(Handle_35e840*)&DAT_004e2440) = FindHandle("golfBall_golfBall");
}
