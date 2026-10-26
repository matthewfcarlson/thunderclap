#include "decls/data/game/global.h"
// data: g_row = DAT_004de678

struct Pair_35d970 {
    int a;
    int b;
};

extern "C" Pair_35d970 FindRow(const char*);

void FUN_0035d970() {
    (*(Pair_35d970*)&DAT_004de678) = FindRow("RowBackgrounds");
}
