// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0016b3c0 @ 0x0016b3c0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern void FUN_00165580();
extern void FUN_00165590();
extern void* __cdecl FUN_0008d690(hulk_uintptr);
namespace hulkfight { namespace motion { class LocomotionMotionStateCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 int* values;
 int count;
 void (*callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
}
typedef fight::ParamEnumConstList<hulkfight::motion::LocomotionMotionStateCondition> List_16b3c0;
extern void __cdecl FUN_002347b0(int*, List_16b3c0**, int);
void initialize() {
 if (!DAT_004e1224) {
  List_16b3c0* lists[2];
  List_16b3c0* a = (List_16b3c0*)FUN_0008d690(32);
  if (a) {
   int count = (*(int*)&DAT_00427760);
   a->FUN_00234cc0("compare");
   new(a) List_16b3c0;
   a->values = ((int*)&DAT_00427758);
   a->count = count;
   a->callback = FUN_00165580;
  }
  lists[0] = a;
  List_16b3c0* b = (List_16b3c0*)FUN_0008d690(32);
  if (b) {
   int count = (*(int*)&DAT_003f5bbc);
   b->FUN_00234cc0("locomotionMotionState");
   new(b) List_16b3c0;
   b->values = ((int*)&DAT_0048f590);
   b->count = count;
   b->callback = FUN_00165590;
  }
  lists[1] = b;
  FUN_002347b0(&DAT_004e1220, lists, 2);
 }
 ++DAT_004e1224;
}
