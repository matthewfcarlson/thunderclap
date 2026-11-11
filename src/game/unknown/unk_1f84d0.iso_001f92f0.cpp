// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f84d0..0x001f94e0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x001f92f0 FUN_001f92f0 (48 B): matches/0x001f92f0.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: _FUN_001f92f0
#include "gen/owners.h"
namespace fn_ff7da6fe {} using namespace fn_ff7da6fe;
namespace fn_ff7da6fe {
typedef unsigned int uint_1f92f0;
struct Obj_1f92f0 {
    char pad[0x10];
};
extern "C" uint_1f92f0 __cdecl FUN_001f92f0(Obj_1f92f0* lhs, Obj_1f92f0* rhs) {
    if (((owners::Key_1f84d0 *)lhs)->FUN_001f84d0((const owners::Key_1f84d0 *)(Obj_1f92f0 *)((Obj_1f92f0*)((char*)rhs + 0x10))))
        return 0xffffffff;
    return ((owners::Key_1f84d0 *)(((Obj_1f92f0*)((char*)rhs + 0x10))))->FUN_001f84d0((const owners::Key_1f84d0 *)(Obj_1f92f0 *)lhs) != 0;
}
} // namespace fn_ff7da6fe

