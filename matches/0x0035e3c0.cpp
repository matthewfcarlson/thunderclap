#include "decls/data/game/hulkfight/motion.h"
// data: result = DAT_004e1150

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e3c0() {
    (*(Pair*)&DAT_004e1150) = FUN_0027b020("golfBall_golfBall");
}