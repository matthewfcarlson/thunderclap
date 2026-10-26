#include "decls/data/game/hulkfight/motion.h"
// data: result = DAT_004e15a8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl lookup(const char*);
void init() {
    (*(Pair*)&DAT_004e15a8) = lookup("golfBall_golfBall");
}