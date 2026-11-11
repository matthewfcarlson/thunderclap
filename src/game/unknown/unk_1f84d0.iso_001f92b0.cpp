// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f84d0..0x001f94e0 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x001f92b0 FUN_001f92b0 (51 B): matches/0x001f92b0.cpp [isolated: lost its match in the tree (call sequence differs)]
// sym: ?FUN_001f92b0@fn_fb9531ef@@YAIPAUThing_1f92b0@1@0@Z
#include "gen/owners.h"
namespace fn_fb9531ef {} using namespace fn_fb9531ef;
namespace fn_fb9531ef {
typedef unsigned int uint_1f92b0;
struct Thing_1f92b0 {
    char pad[0x10];
};
uint_1f92b0 FUN_001f92b0(Thing_1f92b0* a, Thing_1f92b0* b) {
    Thing_1f92b0* x = (Thing_1f92b0*)((char*)b + 0x10);
    Thing_1f92b0* y = (Thing_1f92b0*)((char*)a + 0x10);
    if (((owners::Key_1f84d0 *)y)->FUN_001f84d0((const owners::Key_1f84d0 *)(Thing_1f92b0 *)x))
        return 0xffffffff;
    return ((owners::Key_1f84d0 *)x)->FUN_001f84d0((const owners::Key_1f84d0 *)(Thing_1f92b0 *)y) != 0;
}
} // namespace fn_fb9531ef

