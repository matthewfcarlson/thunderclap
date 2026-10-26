#include "decls/data/engine/fight.h"

struct Pair {
    int lo, hi;
};
extern "C" Pair __cdecl FUN_002672f0(int a, int b, int c);
void __cdecl FUN_0035f030() {
    (*(Pair*)&DAT_004e5b70) = FUN_002672f0((*(int*)&DAT_004ca258), 0, 0);
}
