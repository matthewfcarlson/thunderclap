// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00128db0 @ 0x00128db0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_00123830(); void FUN_00123840(); void FUN_00123860(); void FUN_00123880();
  
namespace hulkfight { namespace ai { class TargetDistanceXZCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; const char* choices; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234860(const char*); };
}
void __cdecl FUN_002347b0(void*, void**, int);
void FUN_00128db0() {
 if (DAT_004e0dc8 == 0) {
  void* params[4]; typedef hulkfight::ai::TargetDistanceXZCondition T;
  fight::ParamEnumConstList<T>* a = (fight::ParamEnumConstList<T>*)FUN_0008d690(32);
  if(a) { int count = (*(int*)&DAT_00427754); a->FUN_00234cc0("compare"); a->count = count; new (a) fight::ParamEnumConstList<T>; a->choices = "lwB"; a->callback = FUN_00123830; }
  params[0] = a;
  fight::ParamFloatConstRange<T>* b = (fight::ParamFloatConstRange<T>*)FUN_0008d690(24);
  if(b) { b->FUN_00234960("distance"); new (b) fight::ParamFloatConstRange<T>; b->callback = FUN_00123840; }
  params[1] = b;
  fight::ParamBool<T>* c = (fight::ParamBool<T>*)FUN_0008d690(24);
  if(c) { c->FUN_00234860("useHulk"); new (c) fight::ParamBool<T>; c->callback = FUN_00123860; }
  params[2] = c;
  fight::ParamBool<T>* d = (fight::ParamBool<T>*)FUN_0008d690(24);
  if(d) { d->FUN_00234860("useGroundPoint"); new (d) fight::ParamBool<T>; d->callback = FUN_00123880; }
  params[3] = d; FUN_002347b0(&DAT_004e0dc4, params, 4);
 }
 ++DAT_004e0dc8;
}
