#include "decls/data/game/hulkfight/ai.h"
// data: result = DAT_004e0d00

extern "C" struct Pair {
    unsigned a;
    unsigned b;
};
extern "C" Pair __cdecl FUN_0027b020(const char*);
void FUN_0035e320() {
    (*(Pair*)&DAT_004e0d00) = FUN_0027b020("random_intersect");
}