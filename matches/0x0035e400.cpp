#include "decls/data/game/hulkfight/motion.h"
// data: result = DAT_004e13d8

struct Pair {
    int a, b;
};
extern Pair __cdecl lookup(const char*);
void target() {
    (*(Pair*)&DAT_004e13d8) = lookup("golfBall_golfBall");
}