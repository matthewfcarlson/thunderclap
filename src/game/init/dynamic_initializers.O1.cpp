// cl-flags: /O1
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0035be88..0x00364840 (kind game-init, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#define TREE_TU_BEGIN namespace fn_f8e91467 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8e91467 {} using namespace fn_f8e91467;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f8e91467 {
extern "C" void __fastcall FUN_00260680(void*);
extern void* g_target_364740;
class Obj_364740 {
  public:
    void Run();
};


// 0x00364350 FUN_00364350 (10 B): matches/0x00364350.cpp
// sym: ?FUN_00364350@fn_f8e91467@@YIXXZ
void __fastcall FUN_00364350() {
    FUN_00260680(((char*)&DAT_004e6698));
}


// 0x00364740 FUN_00364740 (10 B): matches/0x00364740.cpp
// sym: ?FUN_00364740@fn_f8e91467@@YGXXZ
// data: hulk_at_004e7b08 = DAT_004e7b08
void __stdcall FUN_00364740() {
    ((Obj_364740*)((hulk_intptr)(DAT_004e7b50)))->Run();
}

} // namespace fn_f8e91467
