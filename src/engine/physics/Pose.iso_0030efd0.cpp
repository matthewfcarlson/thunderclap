// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030eba0..0x00310130 (kind game, layer engine, confidence medium), dominant class physics::Pose
// (tree_prelude.h: not needed)


// 0x0030efd0 FUN_0030efd0 (42 B): matches/0x0030efd0.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?target@C_30efd0@fn_fdcf1476@@QAEXH@Z
#include "gen/owners.h"
namespace fn_fdcf1476 {} using namespace fn_fdcf1476;
namespace fn_fdcf1476 {
// Same code shape as 0x0030efa0 (propagated; names are from that function)
class C_30efd0 {
  public:
    char pad[0xbc];
    int value;
    void first();
    void third();
    void target(int);
};
void C_30efd0::target(int arg) {
    first();
    ((owners::Obj_30f140 *)(((C_30efd0*)((char*)this + 0x14))))->FUN_0030f140((owners::Obj_30f140 *)(hulk_uintptr)(int)arg);
    value = 2;
    third();
}
} // namespace fn_fdcf1476

