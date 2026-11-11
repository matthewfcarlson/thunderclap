// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"


// 0x0016b480 FUN_0016b480 (190 B): equivalent/0x0016b480.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_0016b480 @2e575270a4d9 @w0849c144c264
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
namespace fn_f8c42fc3 {} using namespace fn_f8c42fc3;
namespace fn_f8c42fc3 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_0016b480 @ 0x0016b480

/* size_t: tree_prelude.h */

} // namespace fn_f8c42fc3
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f8c42fc3 {

extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void SetCompare_001655a0();
extern "C" void SetConstant_001655b0();
namespace hulkfight { namespace motion { class GrappleReactionTypeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 void* values;
 unsigned int count;
 void (*callback)();
 unsigned int tail;
 void FUN_00234cc0(const char*);
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::GrappleReactionTypeCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Param**, int);
extern "C" void __cdecl FUN_0016b480() {
 if (!DAT_004e122c) {
  Param* entries[2];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) {
   unsigned int count = (*(unsigned int*)&DAT_00427754);
   p->FUN_00234cc0("compare");
   p = new(p) Param;
   p->count = count;
   p->values = ((char*)&DAT_0042773c);
   p->callback = SetCompare_001655a0;
  }
  entries[0] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) {
   p->FUN_00234cc0("constant");
   p = new(p) Param;
   p->values = ((char*)&DAT_004b4d98);
   p->count = 3;
   p->callback = SetConstant_001655b0;
  }
  entries[1] = p;
  FUN_002347b0(&DAT_004e1228, entries, 2);
 }
 ++DAT_004e122c;
}
} // namespace fn_f8c42fc3

