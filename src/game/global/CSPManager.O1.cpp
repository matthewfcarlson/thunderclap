// cl-flags: /O1
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001db770..0x001e5f10 (kind game, layer game, confidence high), dominant class CSPManager
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#define TREE_TU_BEGIN namespace fn_f5099814 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5099814 {} using namespace fn_f5099814;
#include "game/global.h"

namespace fn_f5099814 {

// 0x001dba30 FUN_001dba30 (10 B): matches/0x001dba30.cpp
// sym: _FUN_001dba30
// data: gValue_1dba30 = DAT_004c616c
extern "C" void FUN_001dba30(int v) {
    DAT_004c616c = v;
}

} // namespace fn_f5099814
