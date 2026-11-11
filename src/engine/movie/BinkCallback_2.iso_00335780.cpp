// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335780 FUN_00335780 (81 B): matches/0x00335780.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?fn@Obj@fn_f7f4de18@@QAEDHPAH00@Z
#include "gen/owners.h"
namespace fn_f7f4de18 {} using namespace fn_f7f4de18;
namespace fn_f7f4de18 {
struct Item {
    char pad[8];
    int type;
};
struct Manager {
    char pad[0x44];
    int count;
};
struct Obj {
    char pad[4];
    Manager* mgr;
    int** entries;
    char fn(int index, int* x, int* y, int* z);
};
char Obj::fn(int index, int* x, int* y, int* z) {
    if (index < 0)
        return 0;
    if (index >= mgr->count)
        return 0;
    if (((Item *)((owners::Thing_337090 *)mgr)->FUN_00337090(index))->type != 8)
        return 0;
    int* v = entries[index];
    *x = *v;
    *y = *(++v);
    *z = *(++v);
    return 1;
}
} // namespace fn_f7f4de18

