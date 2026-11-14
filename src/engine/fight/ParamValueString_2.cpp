// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002349e0..0x00234a90 (kind game, layer engine, confidence medium), dominant class fight::ParamValueString
#include "tree_prelude.h"
#define HULK_FIGHT_PARAM_IMPLICIT   // (gx2, D18) include/gen/fight.h: the parameter classes' real constructors
#include "compat/ptr.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_f9940245 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9940245 {} using namespace fn_f9940245;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f9940245 {
} // namespace fn_f9940245


// 0x002349e0 FUN_002349e0 (34 B): matches/0x002349e0.cpp
// sym: ??0ParamValueString@fight@@QAE@PBD@Z
// (gx2, D18) the constructor the parameter registrations call (`new ParamString<T>(name, setter)`)
fight::ParamValueString::ParamValueString(const char* s) : fight::ParamValue(s) {}
