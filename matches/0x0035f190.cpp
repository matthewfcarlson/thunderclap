#include "decls/data/engine/fight.h"

typedef unsigned int u32;
struct Pair {
    u32 lo;
    u32 hi;
};
extern "C" Pair __cdecl FUN_002672f0(u32, u32, u32);
void FUN_0035f190() {
    (*(Pair*)&DAT_004e5b80) = FUN_002672f0((*(u32*)&DAT_004ca284), 0, 0);
}
