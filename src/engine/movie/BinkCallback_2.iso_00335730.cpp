// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335730 FUN_00335730 (69 B): matches/0x00335730.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?Fetch@Target@fn_fd444bf9@@QAE_NHPAH0@Z
#include "gen/owners.h"
namespace fn_fd444bf9 {} using namespace fn_fd444bf9;
namespace fn_fd444bf9 {
struct Entry {
    int a, b;
};
struct Item {
    char pad[8];
    int type;
};
class Owner {
  public:
    char pad[0x44];
    int count;
};
class Target {
  public:
    char pad[4];
    Owner* owner;
    Entry** entries;
    bool Fetch(int index, int* outA, int* outB);
};
bool Target::Fetch(int index, int* outA, int* outB) {
    if (index < 0)
        return false;
    if (index >= owner->count)
        return false;
    Item* item = ((Item *)((owners::Thing_337090 *)owner)->FUN_00337090(index));
    if (item->type != 7)
        return false;
    Entry* e = entries[index];
    *outA = e->a;
    *outB = e->b;
    return true;
}
} // namespace fn_fd444bf9

