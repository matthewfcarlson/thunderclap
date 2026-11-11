// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002349e0..0x00234a90 (kind game, layer engine, confidence medium), dominant class fight::ParamValueString
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f9940245 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9940245 {} using namespace fn_f9940245;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f9940245 {
extern "C" char DAT_00427a78[];
class Sub_2349e0 {
  public:
    void Init(const char*);
};
class ParamValueString {
  public:
    hulk_intptr vf;
    int pad;
    Sub_2349e0 sub;
    ParamValueString(const char*);
};


// 0x002349e0 FUN_002349e0 (34 B): matches/0x002349e0.cpp
// sym: ??0ParamValueString@fn_f9940245@@QAE@PBD@Z
ParamValueString::ParamValueString(const char* s) {
    vf = ((hulk_intptr)DAT_004279fc);
    sub.Init(s);
    vf = ((hulk_intptr)DAT_00427a78);
}

} // namespace fn_f9940245
