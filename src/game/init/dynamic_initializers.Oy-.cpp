// cl-flags: /Oy- /GX
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035be88..0x00364840 (kind game-init, layer game, confidence low)
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_faf34b04 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faf34b04 {} using namespace fn_faf34b04;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_faf34b04 {
struct Thing {
    char bytes[0x408];
    Thing();
    ~Thing();
};
extern "C" void work();


// 0x0035be90 FUN_0035be90 (11 B): matches/0x0035be90.cpp
// sym: $L#0@?target@fn_faf34b04@@YAXXZ
// (gx1) an unwind funclet of library code built with exceptions (this TU is `/GX`); the game's code is built
// without (MSVC /GX-, the native builds' -fno-exceptions), where the funclet does not exist
void target() {
    Thing t;
#if defined(_CPPUNWIND)
    try {
        work();
    } catch (...) {
        throw;
    }
#else
    work();
#endif
}

} // namespace fn_faf34b04
