#include "decls/data/game/hulkfight/motion.h"

extern "C" {
struct Pair {
    int a;
    int b;
};
Pair __cdecl FUN_0027b020(const char*);
}
void FUN_0035e480() {
    (*(Pair*)&DAT_004e13c8) = FUN_0027b020("none");
}
