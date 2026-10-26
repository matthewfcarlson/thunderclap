#include "decls/data/engine/fight.h"

struct Vec2 {
    int x, y;
};


extern "C" Vec2 __cdecl FUN_002672f0(int a, int b, int c);

void FUN_0035efd0() {
    (*(Vec2*)&DAT_004e5b28) = FUN_002672f0((*(int*)&DAT_004ca24c), 0, 0);
}
