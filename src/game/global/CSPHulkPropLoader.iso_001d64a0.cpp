// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d4d50..0x001d64c0 (kind game, layer game, confidence medium), dominant class CSPHulkPropLoader
// (tree_prelude.h: not needed)


// 0x001d64a0 FUN_001d64a0 (11 B): matches/0x001d64a0.cpp [isolated: lost its match in the tree (codegen differs (3 of 3 instructions))]
// sym: ?F@A_1d64a0@fn_f2612c23@@QAEHXZ
#include "gen/owners.h"
namespace fn_f2612c23 {} using namespace fn_f2612c23;
namespace fn_f2612c23 {
class B_1d64a0 {
  public:
};
class A_1d64a0 {
  public:
    char pad[0xec];
    B_1d64a0* p;
    int F();
};
int A_1d64a0::F() {
    return ((owners::C_1d4de0 *)p)->FUN_001d4de0();
}
} // namespace fn_f2612c23

