// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023d420..0x0023d810 (kind game, layer engine, confidence high), dominant class fight::DebugCondition
#include "tree_prelude.h"


// 0x0023d630 FUN_0023d630 (190 B): equivalent/0x0023d630.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?FUN_0023d630@fn_f32810ac@@YAXXZ
#include "gen/owners.h"
#include "decls/data/engine/fight.h"
#include "decls/data/engine/unknown.h"
namespace fn_f32810ac {} using namespace fn_f32810ac;
namespace fn_f32810ac {
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 6/6)
// FUN_0023d630 @ 0x0023d630

/* size_t: tree_prelude.h */

} // namespace fn_f32810ac
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f32810ac {

extern void SetCompare_0023d450();
extern void SetMode_0023d460();
extern void* __cdecl FUN_0008d690(unsigned int);
struct Base_23d630 { char pad[16]; void FUN_00234cc0(const char*); };
namespace fight {
class DebugCondition;
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 void* entries;
 int count;
 void (*callback)();
 int tail;
};
}
extern void __cdecl FUN_002347b0(void*, void*, int);
void FUN_0023d630() {
 if (!DAT_004e5c58) {
  fight::ParamEnumConstList<fight::DebugCondition>* items[2];
  void* p = FUN_0008d690((int)sizeof(fight::ParamEnumConstList<fight::DebugCondition>));
  if(p) {
   int n = (*(int*)&DAT_00427760);
   ((Base_23d630*)p)->FUN_00234cc0("compare");
   ((fight::ParamEnumConstList<fight::DebugCondition>*)p)->count=n;
   items[0] = new(p) fight::ParamEnumConstList<fight::DebugCondition>;
   items[0]->entries=((int*)&DAT_00427758);
   items[0]->callback=SetCompare_0023d450;
  } else items[0]=0;
  p=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<fight::DebugCondition>));
  if(p) {
   ((Base_23d630*)p)->FUN_00234cc0("mode");
   items[1]=new(p) fight::ParamEnumConstList<fight::DebugCondition>;
   items[1]->entries=((int*)&DAT_00428b30);
   items[1]->count=3;
   items[1]->callback=SetMode_0023d460;
  } else items[1]=0;
  FUN_002347b0(&DAT_004e5c54,items,2);
 }
 ++DAT_004e5c58;
}
} // namespace fn_f32810ac

