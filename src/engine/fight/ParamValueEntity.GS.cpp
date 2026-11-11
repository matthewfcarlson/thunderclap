// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234fa0..0x00235170 (kind game, layer engine, confidence high), dominant class fight::ParamValueEntity
#include "tree_prelude.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_f3d93422 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3d93422 {} using namespace fn_f3d93422;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f3d93422 {
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual bool slot8(unsigned a, unsigned b, char* buffer, unsigned size); };
void __cdecl FUN_00232cc0(Context*, const char*, ...);
namespace fight {
struct ParamValue { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual bool vfunc_5(void*,void*,Context*); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void vfunc_9(); virtual void* vfunc_10(void*, unsigned __int64); virtual void slot11(void*,void*); unsigned field4; unsigned field8; unsigned fieldC; };
}
namespace fight {
struct ParamValueEntity : ParamValue { virtual bool vfunc_5(void*,void*,Context*); };
}


// 0x00235070 fight::ParamValueEntity::vfunc_5 (205 B): equivalent/0x00235070.cpp
// sym: ?vfunc_5@ParamValueEntity@fight@fn_f3d93422@@UAE_NPAX0PAUContext@3@@Z @5a256f090239 @w525875e73eaf
// STATUS: equivalent (tools/equiv.py level 3: 15754 inputs, branch coverage 6/6)
// fight::ParamValueEntity::vfunc_5 @ 0x00235070
namespace fight {
bool ParamValueEntity::vfunc_5(void* arg1, void* arg2, Context* context) {
 char buffer[256] = {0};
 bool success = context->slot8(field8, fieldC, buffer, 256);
 if (success) {
 unsigned __int64 key = FUN_0027b020(buffer);
 if (!key) slot11(arg1, 0);
 else {
 void* entity = vfunc_10(arg1, key);
 if (entity) slot11(arg1, entity);
 else {
 FUN_00232cc0(context, "\"%s\" could not be found in the inventory.", buffer);
 success = false;
 }
 }
 }
 return success;
}
}

} // namespace fn_f3d93422
