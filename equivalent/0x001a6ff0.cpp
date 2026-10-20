// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_001a6ff0 @ 0x001a6ff0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/hulkfight/scenario.h"

inline void* operator new(unsigned int, void* p) { return p; }
extern void FUN_001a1f00();
extern void FUN_001a1f10();
extern void* __cdecl FUN_0008d690(unsigned int);
struct Base_1a6ff0 { virtual void slot0(); void FUN_00234cc0(const char*); };
namespace hulkfight { namespace scenario { class Event_LocomotionStateNamePreviousCondition; } }
namespace fight { template<class T> struct ParamEnumConstList : Base_1a6ff0 {
 virtual void slot0();
 char pad[12];
 int* entries;
 int count;
 void (*callback)();
 int extra;
}; }
typedef fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition> Param;
extern void __cdecl FUN_002347b0(int*, Param**, int);
void FUN_001a6ff0() {
 if (!DAT_004e1724) {
  Param* list[2];
  Param* p = (Param*)FUN_0008d690(32);
  if (p) {
   int count = (*(int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   new (p) Param;
   p->entries = ((int*)&DAT_00427758);
   p->count = count;
   p->callback = FUN_001a1f00;
  }
  list[0] = p;
  p = (Param*)FUN_0008d690(32);
  if (p) {
   int count = (*(int*)&DAT_003f5bbc);
   p->FUN_00234cc0("oldState");
   new (p) Param;
   p->entries = ((int*)&DAT_0048f590);
   p->count = count;
   p->callback = FUN_001a1f10;
  }
  list[1] = p;
  FUN_002347b0(&DAT_004e1720, list, 2);
 }
 ++DAT_004e1724;
}
