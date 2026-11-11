// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00335500 FUN_00335500 (58 B): matches/0x00335500.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?run@A_335500@fn_f035f14a@@QAE_NHPAI@Z
#include "gen/owners.h"
namespace fn_f035f14a {} using namespace fn_f035f14a;
namespace fn_f035f14a {
struct C_335500 {
    char pad[8];
    int type;
};
struct B_335500 {
    char pad[0x44];
    int count;
};
struct A_335500 {
    char pad[4];
    B_335500* b;
    unsigned int* values;
    bool run(int index, unsigned int* out);
};
bool A_335500::run(int index, unsigned int* out) {
    if (index < 0)
        return false;
    if (index >= b->count)
        return false;
    if (((C_335500 *)((owners::Thing_337090 *)b)->FUN_00337090(index))->type != 2)
        return false;
    *out = values[index];
    return true;
}
} // namespace fn_f035f14a

