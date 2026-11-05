#include "decls/data/game/hulkfight/ai.h"
// data: gPair = DAT_004e0d08

struct Pair {
    int a;
    int b;
};
extern Pair __cdecl FUN_0027b020(const char*);
void InitWaypoint() {
    (*(Pair*)&DAT_004e0d08) = FUN_0027b020("waypoint");
}