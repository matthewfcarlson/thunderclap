// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001a70b0 @ 0x001a70b0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/hulkfight/scenario.h"

inline void* __cdecl operator new(unsigned int, void* memory) { return memory; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_001a1f20();
extern "C" void FUN_001a1f30();
namespace hulkfight { namespace scenario { class Event_LocomotionStateNameCondition; } }
namespace fight { template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 void* values;
 unsigned int count;
 void (*callback)();
 unsigned int tail;
 void FUN_00234cc0(const char*);
}; }
typedef fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Param**, unsigned int);
void __cdecl FUN_001a70b0() {
 if ((*(unsigned int*)&DAT_004e172c) == 0) {
  Param* entries[2];
  Param* p = (Param*)FUN_0008d690(32);
  if (p) {
   unsigned int count = (*(unsigned int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   new (p) Param;
   p->values = ((char*)&DAT_00427758);
   p->count = count;
   p->callback = FUN_001a1f20;
  }
  entries[0] = p;
  p = (Param*)FUN_0008d690(32);
  if (p) {
   unsigned int count = (*(unsigned int*)&DAT_003f5bbc);
   p->FUN_00234cc0("newState");
   new (p) Param;
   p->values = ((char*)&DAT_0048f590);
   p->count = count;
   p->callback = FUN_001a1f30;
  }
  entries[1] = p;
  FUN_002347b0(((unsigned int*)&DAT_004e1728), entries, 2);
 }
 ++(*(unsigned int*)&DAT_004e172c);
}
