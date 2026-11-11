// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00335580 FUN_00335580 (87 B): matches/0x00335580.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?length@Obj@fn_fcb435aa@@QAE_NHPAH@Z
#include "gen/owners.h"
namespace fn_fcb435aa {} using namespace fn_fcb435aa;
namespace fn_fcb435aa {
class Item {
  public:
    char pad[8];
    int type;
};
class Store {
  public:
    char pad[0x44];
    int count;
};
class Obj {
  public:
    char pad[4];
    Store* store;
    char** strings;
    bool length(int index, int* out);
};
bool Obj::length(int index, int* out) {
    if (index < 0)
        return false;
    if (index >= store->count)
        return false;
    if (((Item *)((owners::Thing_337090 *)store)->FUN_00337090(index))->type != 4)
        return false;
    const char* s = strings[index];
    if (!s) {
        *out = 0;
        return true;
    }
    const char* e = s + 1;
    char c;
    do {
        c = *s++;
    } while (c);
    *(hulk_intptr*)out = s - e;
    return true;
}
} // namespace fn_fcb435aa

