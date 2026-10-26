#include "decls/data/game/global.h"
// data: entries = DAT_004ddab0, zero = DAT_003f335c

struct Entry {
    int count;
    float* value;
};
float* __cdecl FUN_000b0a00(int x, int y, int z) {
    if (x < 0 || x >= 2 || y < 0 || y >= 2 || z < 0 || z >= 3)
        return ((float*)&DAT_003f335c);
    Entry* p = &((Entry*)&DAT_004ddab0)[(x * 2 + y) * 3 + z];
    if (p->count <= 0)
        return ((float*)&DAT_003f335c);
    return p->value;
}