// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c1460..0x001c49c0 (kind game, layer game, confidence high), dominant class Render::Canvas::HulkShaderCallback
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001c3840 FUN_001c3840 (7 B): matches/0x001c3840.cpp [isolated: lost its match in the tree (codegen differs (11 of 12 instructions))]
// sym: ?g@Outer_1c3840@fn_f2795b19@@QAEXHH@Z
#include "gen/owners.h"
namespace fn_f2795b19 {} using namespace fn_f2795b19;
namespace fn_f2795b19 {
// Same code shape as 0x001c3830 (propagated; names are from that function)
class Inner_1c3840 {
  public:
};
class Outer_1c3840 {
  public:
    Inner_1c3840* p;
    void g(hulk_intptr, hulk_intptr);
};
void Outer_1c3840::g(hulk_intptr a0, hulk_intptr a1) {
    ((owners::Obj_1c1750 *)p)->FUN_001c1750((int *)(hulk_uintptr)(int)a0, (int *)(hulk_uintptr)(int)a1);
}
} // namespace fn_f2795b19

