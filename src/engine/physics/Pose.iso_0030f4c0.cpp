// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030eba0..0x00310130 (kind game, layer engine, confidence medium), dominant class physics::Pose
// (tree_prelude.h: not needed)


// 0x0030f4c0 FUN_0030f4c0 (68 B): matches/0x0030f4c0.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?run@Obj@fn_f10ce73f@@QAEXXZ
#include "gen/owners.h"
namespace fn_f10ce73f {} using namespace fn_f10ce73f;
namespace fn_f10ce73f {
struct SrcItem {
    char pad[0x40];
};
struct DstItem {
    char pad[0xc0];
};
struct Src {
    char pad[0x10];
    int count;
    char pad2[4];
    SrcItem* items;
};
class Obj {
    char pad[8];
    Src* source;
    DstItem* dest;

  public:
    void run();
};
void Obj::run() {
    int n;
    if (source == 0)
        n = 0;
    else
        n = source->count;
    for (int i = 0; i < n; ++i)
        ((owners::C_30efa0 *)&(dest[i]))->FUN_0030efa0((hulk_intptr)(SrcItem *)(&source->items[i]));
}
} // namespace fn_f10ce73f

