// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"


// 0x00128db0 FUN_00128db0 (274 B): equivalent/0x00128db0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00128db0 @61fdb8856067 @w141c84d02b1e
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_fee99970 {} using namespace fn_fee99970;
namespace fn_fee99970 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00128db0 @ 0x00128db0


} // namespace fn_fee99970
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fee99970 {

void* __cdecl FUN_0008d690(unsigned int);
char SetCompare_00123830(void*, int); /* (unb5) as defined; address taken only */ bool SetDistance_00123840(void*, int); /* (unb5) as defined; address taken only */ char SetUseHulk_00123860(void*, char); /* (unb5) as defined; address taken only */ char SetUseGroundPoint_00123880(void*, char); /* (unb5) as defined; address taken only */
  
namespace hulkfight { namespace ai { class TargetDistanceXZCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; const char* choices; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234860(const char*); };
}
void __cdecl FUN_002347b0(void*, void**, int);
extern "C" void FUN_00128db0() {
 if (DAT_004e0dc8 == 0) {
  void* params[4]; typedef hulkfight::ai::TargetDistanceXZCondition T;
  fight::ParamEnumConstList<T>* a = (fight::ParamEnumConstList<T>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<T>));
  if(a) { int count = (*(int*)&DAT_00427754); a->FUN_00234cc0("compare"); a->count = count; new (a) fight::ParamEnumConstList<T>; a->choices = "lwB"; a->callback = (void (*)())SetCompare_00123830; }
  params[0] = a;
  fight::ParamFloatConstRange<T>* b = (fight::ParamFloatConstRange<T>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<T>));
  if(b) { b->FUN_00234960("distance"); new (b) fight::ParamFloatConstRange<T>; b->callback = (void (*)())SetDistance_00123840; }
  params[1] = b;
  fight::ParamBool<T>* c = (fight::ParamBool<T>*)FUN_0008d690((int)sizeof(fight::ParamBool<T>));
  if(c) { c->FUN_00234860("useHulk"); new (c) fight::ParamBool<T>; c->callback = (void (*)())SetUseHulk_00123860; }
  params[2] = c;
  fight::ParamBool<T>* d = (fight::ParamBool<T>*)FUN_0008d690((int)sizeof(fight::ParamBool<T>));
  if(d) { d->FUN_00234860("useGroundPoint"); new (d) fight::ParamBool<T>; d->callback = (void (*)())SetUseGroundPoint_00123880; }
  params[3] = d; FUN_002347b0(&DAT_004e0dc4, params, 4);
 }
 ++DAT_004e0dc8;
}
} // namespace fn_fee99970

