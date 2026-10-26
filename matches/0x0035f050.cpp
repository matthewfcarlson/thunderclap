#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca25c, gOutput = DAT_004e5b30

struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
void FUN_0035f050() {
    (*(Pair*)&DAT_004e5b30) = FUN_002672f0((*(unsigned*)&DAT_004ca25c), 0, 0);
}