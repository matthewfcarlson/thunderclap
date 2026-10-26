#include "decls/data/engine/fight.h"
// data: gLoader = DAT_004ca274, gResult = DAT_004e5b38

struct Pair {
    unsigned int lo, hi;
};
extern "C" Pair __cdecl FUN_002672f0(int a, int b, int c);
Pair __cdecl FUN_0035f110() {
    (*(Pair*)&DAT_004e5b38) = FUN_002672f0((*(int*)&DAT_004ca274), 0, 0);
    return (*(Pair*)&DAT_004e5b38);
}
