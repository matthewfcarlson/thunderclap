#include "decls/data/engine/fight.h"
// data: input = DAT_004ca26c, output = DAT_004e5b90

struct Pair {
    int a, b;
};
Pair __cdecl func(int, int, int);
void target() {
    Pair p = func((*(int*)&DAT_004ca26c), 0, 0);
    ((int*)&DAT_004e5b90)[0] = p.a;
    ((int*)&DAT_004e5b90)[1] = p.b;
}