// cl-flags: /O1
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00061e30..0x00068c80 (kind game, layer game, confidence high), dominant class CWeaponCollisionTrack
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f2b8a849 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2b8a849 {} using namespace fn_f2b8a849;
#include "game/global.h"


// 0x00068a90 FUN_00068a90 (18 B): matches/0x00068a90.cpp
// sym: ?FUN_00068a90@Obj_68a90@owners@@QAEDM@Z
char owners::Obj_68a90::FUN_00068a90(float angle) {
    value = angle * 0.0174532923847437f;
    return 1;
}

