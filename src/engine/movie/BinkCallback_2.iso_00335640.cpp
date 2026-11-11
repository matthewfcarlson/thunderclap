// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335640 FUN_00335640 (50 B): matches/0x00335640.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?FUN_00335640@Object@fn_f3ca2e9c@@QAEHH@Z
#include "gen/owners.h"
namespace fn_f3ca2e9c {} using namespace fn_f3ca2e9c;
namespace fn_f3ca2e9c {
struct Entry {
    char pad[8];
    int type;
};
struct Manager {
    char pad[0x44];
    int count;
};
struct Object {
    char pad[4];
    Manager* manager;
    int* values;
    int FUN_00335640(int index);
};
int Object::FUN_00335640(int index) {
    if (index < 0)
        return 0;
    if (index >= manager->count)
        return 0;
    if (((Entry *)((owners::Thing_337090 *)manager)->FUN_00337090(index))->type != 4)
        return 0;
    return values[index];
}
} // namespace fn_f3ca2e9c

