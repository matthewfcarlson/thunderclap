#include "decls/data/engine/fight.h"
// data: gInput = DAT_004ca268, gOutput = DAT_004e5b10

extern "C" __int64 __cdecl FUN_002672f0(int, int, int);
void FUN_0035f0b0() {
    (*(__int64*)&DAT_004e5b10) = FUN_002672f0((*(int*)&DAT_004ca268), 0, 0);
}