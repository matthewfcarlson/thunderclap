#include "decls/data/game/unknown.h"
// data: result = DAT_004dc2a0

struct Pair {
    int a, b;
};
extern Pair __cdecl Lookup(const char*);
void __cdecl FUN_0035c9b0() {
    (*(Pair*)&DAT_004dc2a0) = Lookup("golfBall_golfBall");
}