// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030eba0..0x00310130 (kind game, layer engine, confidence medium), dominant class physics::Pose
// (tree_prelude.h: not needed)


// 0x0030eea0 FUN_0030eea0 (42 B): matches/0x0030eea0.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?Target@A_30eea0@fn_f149c202@@QAEXH@Z
#include "gen/owners.h"
namespace fn_f149c202 {} using namespace fn_f149c202;
namespace fn_f149c202 {
// Same code shape as 0x0030ee70 (propagated; names are from that function)
struct B_30eea0 {
};
struct A_30eea0 {
    char pad[0xBC];
    void Init();
    void Finish();
    void Target(int);
};
void A_30eea0::Target(int x) {
    Init();
    ((owners::Obj_30f140 *)(((B_30eea0*)((char*)this + 0x68))))->FUN_0030f140((owners::Obj_30f140 *)(hulk_uintptr)(int)x);
    *(int*)((char*)this + 0xbc) = 1;
    Finish();
}
} // namespace fn_f149c202

