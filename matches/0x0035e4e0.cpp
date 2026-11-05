#include "decls/data/game/hulkfight/motion.h"
// data: result = DAT_004e15a8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void init() {
    (*(Pair*)&DAT_004e15a8) = FUN_0027b020("golfBall_golfBall");
}