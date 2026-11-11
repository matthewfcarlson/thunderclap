// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335480 FUN_00335480 (59 B): matches/0x00335480.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?get@Obj@fn_fef5cc49@@QAEDHPAE@Z
#include "gen/owners.h"
namespace fn_fef5cc49 {} using namespace fn_fef5cc49;
namespace fn_fef5cc49 {
struct Item {
    char pad[8];
    int state;
};
struct List {
    char pad[0x44];
    int count;
};
struct Obj {
    void* v;
    List* list;
    unsigned char* flags;
    char get(int index, unsigned char* out);
};
char Obj::get(int index, unsigned char* out) {
    if (index < 0)
        return 0;
    if (index >= list->count)
        return 0;
    Item* p = ((Item *)((owners::Thing_337090 *)list)->FUN_00337090(index));
    if (p->state)
        return 0;
    *out = flags[index * 4];
    return 1;
}
} // namespace fn_fef5cc49

