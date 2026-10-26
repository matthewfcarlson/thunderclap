#include "decls/data/game/global.h"
// data: g_pairs = DAT_004e2788

struct Pair_1e9bc0 {
    int a;
    int b;
};
bool FUN_001e9bc0(int a, int b) {
    for (int i = 0; i < 28; ++i) {
        if (a == (*(Pair_1e9bc0**)&DAT_004e2788)[i].a && b == (*(Pair_1e9bc0**)&DAT_004e2788)[i].b)
            return true;
    }
    return false;
}