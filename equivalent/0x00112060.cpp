// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00112060 @ 0x00112060
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

typedef unsigned int uint;
void* __cdecl FUN_0008d690(uint);
inline void* operator new(hulk_uintptr, void* p) { return p; }
void FUN_0010c200();
void FUN_0010c230();
void FUN_0010cc40();
void __cdecl FUN_002347b0(void*, void**, int);
namespace hulkfight { namespace ai { class KeyWordWaitCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 void FUN_00234cc0(const char*);
 char pad[12];
 const char* list;
 uint count;
 void (*callback)();
 uint extra;
};
template<class T> struct ParamString {
 virtual void slot0();
 void FUN_002349e0(const char*);
 char pad[12];
 void (*callback)();
 uint extra;
};
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 void FUN_00234960(const char*);
 char pad[12];
 void (*callback)();
 uint extra;
};
}
void FUN_00112060() {
 if (!(*(uint*)&DAT_004e0b24)) {
  void* items[3];
  typedef fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition> E;
  typedef fight::ParamString<hulkfight::ai::KeyWordWaitCondition> S;
  typedef fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition> F;
  E* e=(E*)FUN_0008d690(32);
  if(e) {
   uint count=(*(uint*)&DAT_00427754);
   e->FUN_00234cc0("compare");
   e->count=count;
   new(e) E;
   e->list=((char*)&DAT_0042773c);
   e->callback=FUN_0010c200;
  }
  items[0]=e;
  S* s=(S*)FUN_0008d690(24);
  if(s) {
   s->FUN_002349e0("text");
   new(s) S;
   s->callback=FUN_0010cc40;
  }
  items[1]=s;
  F* f=(F*)FUN_0008d690(24);
  if(f) {
   f->FUN_00234960("value");
   new(f) F;
   f->callback=FUN_0010c230;
  }
  items[2]=f;
  FUN_002347b0(((uint*)&DAT_004e0b20),items,3);
 }
 ++(*(uint*)&DAT_004e0b24);
}
