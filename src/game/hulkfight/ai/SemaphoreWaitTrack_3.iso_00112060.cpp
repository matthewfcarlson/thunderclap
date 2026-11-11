// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00112060 FUN_00112060 (231 B): equivalent/0x00112060.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00112060 @ac3d546b8b6f @wbaa3f16da3e6
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_f875f18f {} using namespace fn_f875f18f;
namespace fn_f875f18f {
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 8/8)
// FUN_00112060 @ 0x00112060

typedef unsigned int uint;
void* __cdecl FUN_0008d690(uint);

} // namespace fn_f875f18f
inline void* operator new(hulk_uintptr, void* p) { return p; }
namespace fn_f875f18f {

void SetCompare_0010c200();
void SetValue_0010c230();
void SetText_0010cc40();
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
extern "C" void FUN_00112060() {
 if (!(*(uint*)&DAT_004e0b24)) {
  void* items[3];
  typedef fight::ParamEnumConstList<hulkfight::ai::KeyWordWaitCondition> E;
  typedef fight::ParamString<hulkfight::ai::KeyWordWaitCondition> S;
  typedef fight::ParamFloatConstRange<hulkfight::ai::KeyWordWaitCondition> F;
  E* e=(E*)FUN_0008d690((int)sizeof(E));
  if(e) {
   uint count=(*(uint*)&DAT_00427754);
   e->FUN_00234cc0("compare");
   e->count=count;
   new(e) E;
   e->list=((char*)&DAT_0042773c);
   e->callback=SetCompare_0010c200;
  }
  items[0]=e;
  S* s=(S*)FUN_0008d690((int)sizeof(S));
  if(s) {
   s->FUN_002349e0("text");
   new(s) S;
   s->callback=SetText_0010cc40;
  }
  items[1]=s;
  F* f=(F*)FUN_0008d690((int)sizeof(F));
  if(f) {
   f->FUN_00234960("value");
   new(f) F;
   f->callback=SetValue_0010c230;
  }
  items[2]=f;
  FUN_002347b0(((uint*)&DAT_004e0b20),items,3);
 }
 ++(*(uint*)&DAT_004e0b24);
}
} // namespace fn_f875f18f

