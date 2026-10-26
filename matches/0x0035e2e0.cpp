#include "decls/data/game/hulkfight/ai.h"
// data: g_result = DAT_004e0ce8

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e2e0() {
    (*(Pair*)&DAT_004e0ce8) = FUN_0027b020("closest_intersect");
}