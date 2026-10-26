#include "decls/data/game/hulkfight/motion.h"

struct Pair {
    int a, b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e420() {
    (*(Pair*)&DAT_004e13d0) = FUN_0027b020("boost");
}