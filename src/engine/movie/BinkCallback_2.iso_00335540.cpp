// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335540 FUN_00335540 (58 B): matches/0x00335540.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?Fetch@Obj@fn_f90645c0@@QAE_NHPAH@Z
#include "gen/owners.h"
namespace fn_f90645c0 {} using namespace fn_f90645c0;
namespace fn_f90645c0 {
struct Item {
    char pad[8];
    int kind;
};
struct Manager {
    char pad[0x44];
    int count;
};
class Obj {
  public:
    char pad[4];
    Manager* mgr;
    int* values;
    bool Fetch(int index, int* out);
};
bool Obj::Fetch(int index, int* out) {
    if (index < 0)
        return false;
    if (index >= mgr->count)
        return false;
    if (((Item *)((owners::Thing_337090 *)mgr)->FUN_00337090(index))->kind != 3)
        return false;
    *out = values[index];
    return true;
}
} // namespace fn_f90645c0

