#include "decls/data/game/hulkfight/motion.h"
// data: result = DAT_004e13d8

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void target() {
    (*(Pair*)&DAT_004e13d8) = FUN_0027b020("golfBall_golfBall");
}