#include "decls/data/engine/fight.h"
// data: result = DAT_004e5b40, source = DAT_004ca278

struct Pair {
    int a, b;
};
Pair __cdecl getPair(int, int, int);
void target() {
    Pair p = getPair((*(int*)&DAT_004ca278), 0, 0);
    ((int*)&DAT_004e5b40)[0] = p.a;
    ((int*)&DAT_004e5b40)[1] = p.b;
}