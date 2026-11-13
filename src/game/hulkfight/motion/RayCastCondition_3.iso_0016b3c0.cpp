// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0016a910..0x0016c600 (kind game, layer game, confidence high), dominant class hulkfight::motion::RayCastCondition
#include "tree_prelude.h"


// 0x0016b3c0 FUN_0016b3c0 (192 B): equivalent/0x0016b3c0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?initialize@fn_f3c05a9a@@YAXXZ @eb5c858029a3 @w1a81a89f8535
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/unknown.h"
namespace fn_f3c05a9a {} using namespace fn_f3c05a9a;
namespace fn_f3c05a9a {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_0016b3c0 @ 0x0016b3c0


} // namespace fn_f3c05a9a
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f3c05a9a {

extern bool SetCompare_00165580(void*, int); /* (unb5) as defined; address taken only */
extern bool SetLocomotionMotionState_00165590(void*, void*); /* (unb5) as defined; address taken only */
extern void* __cdecl FUN_0008d690(unsigned int);
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
  List_16b3c0* a = (List_16b3c0*)FUN_0008d690((int)sizeof(List_16b3c0));
  if (a) {
   int count = (*(int*)&DAT_00427760);
   a->FUN_00234cc0("compare");
   new(a) List_16b3c0;
   a->values = ((int*)&DAT_00427758);
   a->count = count;
   a->callback = (void (*)())SetCompare_00165580;
  }
  lists[0] = a;
  List_16b3c0* b = (List_16b3c0*)FUN_0008d690((int)sizeof(List_16b3c0));
  if (b) {
   int count = (*(int*)&DAT_003f5bbc);
   b->FUN_00234cc0("locomotionMotionState");
   new(b) List_16b3c0;
   b->values = ((int*)&DAT_0048f590);
   b->count = count;
   b->callback = (void (*)())SetLocomotionMotionState_00165590;
  }
  lists[1] = b;
  FUN_002347b0(&DAT_004e1220, lists, 2);
 }
 ++DAT_004e1224;
}
} // namespace fn_f3c05a9a

