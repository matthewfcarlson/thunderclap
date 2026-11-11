// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00048650..0x00048680 (kind game, layer game, confidence medium), dominant class CAxisCondition
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f0ee63c9 {
#define TREE_TU_END }
namespace fn_f0ee63c9 {} using namespace fn_f0ee63c9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f0ee63c9 {
class Helper_48650 {
  public:
    int second_00059a30();
};

} // namespace fn_f0ee63c9

// 0x00048650 CAxisCondition::vfunc_8 (45 B): matches/0x00048650.cpp
// sym: ?vfunc_8@CAxisCondition@@UAEXH@Z
void CAxisCondition::vfunc_8(hulk_intptr arg) {
    Helper_48650* h = ((Helper_48650 *)((owners::Object_592a0 *)(((Helper_48650*)arg)))->FUN_000592a0());
    int v = h->second_00059a30();
    vfunc_9(v, v + this->axis * 0x38 + 0x1ff4);
}

