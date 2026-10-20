// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_0023e7a0 @ 0x0023e7a0
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"

typedef void (*Callback_23e7a0)();
void FUN_0023e4d0();
void FUN_0023e4e0();
void FUN_0023e4f0();
void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned, void* p) { return p; }
struct ParamBase_23e7a0 {
 char bytes[16]; Callback_23e7a0 callback; unsigned tail;
 void FUN_00234960(const char*);
 void FUN_00235220(const char*);
};
namespace fight {
class StopTrack;
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char bytes[12]; Callback_23e7a0 callback; unsigned tail;
};
template<class T> struct ParamConditionGroup {
 virtual void slot0();
 char bytes[12]; Callback_23e7a0 callback; unsigned tail;
};
}
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_0023e7a0() {
 if (!DAT_004e5c78) {
  void* items[3];
  ParamBase_23e7a0* a = (ParamBase_23e7a0*)FUN_0008d690(24);
  if(a) {
   a->FUN_00234960("timeBegin");
   fight::ParamFloatConstRange<fight::StopTrack>* p = new(a) fight::ParamFloatConstRange<fight::StopTrack>;
   p->callback = FUN_0023e4d0;
  }
  items[0]=a;
  ParamBase_23e7a0* b = (ParamBase_23e7a0*)FUN_0008d690(24);
  if(b) {
   b->FUN_00234960("timeEnd");
   fight::ParamFloatConstRange<fight::StopTrack>* p = new(b) fight::ParamFloatConstRange<fight::StopTrack>;
   p->callback = FUN_0023e4e0;
  }
  items[1]=b;
  ParamBase_23e7a0* c = (ParamBase_23e7a0*)FUN_0008d690(24);
  if(c) {
   c->FUN_00235220("conditionGroup");
   fight::ParamConditionGroup<fight::StopTrack>* p = new(c) fight::ParamConditionGroup<fight::StopTrack>;
   p->callback = FUN_0023e4f0;
  }
  items[2]=c;
  FUN_002347b0(&DAT_004e5c74,items,3);
 }
 ++DAT_004e5c78;
}
