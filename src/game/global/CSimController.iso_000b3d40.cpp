// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b35d0..0x000b3d50 (kind game, layer game, confidence medium), dominant class CSimController
// (tree_prelude.h: not needed)


// 0x000b3d40 FUN_000b3d40 (11 B): matches/0x000b3d40.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?target@A_b3d40@fn_f837203e@@QAEXXZ
#include "gen/owners.h"
namespace fn_f837203e {} using namespace fn_f837203e;
namespace fn_f837203e {
class B_b3d40 {
  public:
};
class A_b3d40 {
  public:
    int pad;
    B_b3d40* member;
    void target();
};
void A_b3d40::target() {
    ((owners::Obj_b3b50 *)member)->FUN_000b3b50(1);
}
} // namespace fn_f837203e

