// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335680 FUN_00335680 (69 B): matches/0x00335680.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?FUN_00335680@Owner@fn_fc5d2736@@QAE_NHPAH0@Z
#include "gen/owners.h"
namespace fn_fc5d2736 {} using namespace fn_fc5d2736;
namespace fn_fc5d2736 {
struct Entry {
    char pad[8];
    int type;
};
struct Table {
    char pad[0x44];
    int count;
};
struct Pair {
    int first;
    int second;
};
struct Owner {
    char pad[4];
    Table* table;
    Pair** pairs;
    bool FUN_00335680(int index, int* first, int* second);
};
bool Owner::FUN_00335680(int index, int* first, int* second) {
    if (index < 0)
        return false;
    if (index >= table->count)
        return false;
    if (((Entry *)((owners::Thing_337090 *)table)->FUN_00337090(index))->type != 5)
        return false;
    Pair* pair = pairs[index];
    *first = pair->first;
    *second = pair->second;
    return true;
}
} // namespace fn_fc5d2736

