// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_001285a0 @ 0x001285a0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* address) { return address; }
void* __cdecl FUN_0008d690(unsigned int);
void FUN_00123600(); void FUN_00123610();
namespace hulkfight { namespace ai { class TargetTypeCondition; } }
namespace fight { template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 int* values;
 int count;
 void (*callback)();
 int extra;
 void FUN_00234cc0(const char*);
}; }
void __cdecl FUN_002347b0(int*,void*,int);
void target() {
 typedef fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition> Param;
 if (!DAT_004e0d78) {
  Param* list[2];
  list[0]=(Param*)FUN_0008d690(32);
  if(list[0]) {
   int count=(*(int*)&DAT_00427760);
   list[0]->FUN_00234cc0("compare");
   list[0]->count=count;
   new(list[0]) Param;
   list[0]->values=((int*)&DAT_00427758);
   list[0]->callback=FUN_00123600;
  }
  list[1]=(Param*)FUN_0008d690(32);
  if(list[1]) {
   list[1]->FUN_00234cc0("type");
   new(list[1]) Param;
   list[1]->values=((int*)&DAT_004a6acc);
   list[1]->count=2;
   list[1]->callback=FUN_00123610;
  }
  FUN_002347b0(((int*)&DAT_004e0d74),list,2);
 }
 ++DAT_004e0d78;
}
