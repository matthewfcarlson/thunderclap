// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x003354c0 FUN_003354c0 (58 B): matches/0x003354c0.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?Get@C_3354c0@fn_f0c850c7@@QAE_NHPAI@Z
#include "gen/owners.h"
namespace fn_f0c850c7 {} using namespace fn_f0c850c7;
namespace fn_f0c850c7 {
typedef unsigned int u32_3354c0;
struct Item_3354c0 {
    char pad[8];
    volatile int kind;
};
struct Info_3354c0 {
    char pad[0x44];
    int count;
};
class C_3354c0 {
  public:
    char pad0[4];
    Info_3354c0* info;
    u32_3354c0* values;
    bool Get(int index, u32_3354c0* out);
};
bool C_3354c0::Get(int index, u32_3354c0* out) {
    if (index < 0)
        return false;
    if (index >= info->count)
        return false;
    if (((Item_3354c0 *)((owners::Thing_337090 *)info)->FUN_00337090(index))->kind != 1)
        return false;
    *out = values[index];
    return true;
}
} // namespace fn_f0c850c7

