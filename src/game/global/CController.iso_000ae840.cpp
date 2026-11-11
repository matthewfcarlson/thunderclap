// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ad990..0x000ae9a0 (kind game, layer game, confidence medium), dominant class CController
// (tree_prelude.h: not needed)


// 0x000ae840 FUN_000ae840 (96 B): matches/0x000ae840.cpp [isolated: lost its match in the tree (a call became inline code (callee now defined in the same TU))]
// sym: ?run@Obj_ae840@fn_f51bb478@@QAEXXZ
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_f51bb478 {} using namespace fn_f51bb478;
namespace fn_f51bb478 {
// data: gCount_ae840 = DAT_004dda40

extern "C" void __cdecl FUN_002684c0();
struct Helper_ae840 {
    void a();
    void d();
};
struct Obj_ae840 {
    char pad[4];
    Helper_ae840* p;
    char pad2[4];
    char flags[13];
    char flags2[2];
    void run();
    void finish();
};
void Obj_ae840::run() {
    p->a();
    FUN_002684c0();
    ++(*(int*)&DAT_004dda40);
    p->d();
    for (int i = 0; i < 13; ++i)
        if (flags[i])
            ((owners::C_ada30 *)p)->FUN_000ada30(i);
    for (int i = 0; i < 2; ++i)
        if (flags2[i])
            ((owners::X_ada50 *)p)->FUN_000ada50(i);
    finish();
}
} // namespace fn_f51bb478

