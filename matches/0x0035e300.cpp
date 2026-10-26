#include "decls/data/game/hulkfight/ai.h"
// data: result = DAT_004e0d20

struct Pair {
    unsigned a;
    unsigned b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e300() {
    (*(Pair*)&DAT_004e0d20) = FUN_0027b020("closest_intersect_enemy");
}