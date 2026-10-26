#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca294, gOutput = DAT_004e5b60

struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl FUN_002672f0(unsigned, unsigned, unsigned);
void FUN_0035f210() {
    (*(Pair*)&DAT_004e5b60) = FUN_002672f0((*(unsigned*)&DAT_004ca294), 0, 0);
}