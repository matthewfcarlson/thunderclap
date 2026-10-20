// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00053b00 @ 0x00053b00
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) { return p; }
void FUN_00047e70();
void FUN_00047e80();
void* __cdecl FUN_0008d690(unsigned int);
class CSmartPropTypeCondition;
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 void* values;
 int count;
 void (*callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
}
typedef fight::ParamEnumConstList<CSmartPropTypeCondition> Param;
void __cdecl FUN_002347b0(int*, Param**, int);
void FUN_00053b00() {
 if (!DAT_004dc4bc) {
  Param* items[2];
  items[0] = (Param*)FUN_0008d690(32);
  if (items[0]) {
   int n = (*(int*)&DAT_00427760);
   items[0]->FUN_00234cc0("compare");
   items[0]->count = n;
   new (items[0]) Param;
   items[0]->values = ((int*)&DAT_00427758);
   items[0]->callback = FUN_00047e70;
  }
  items[1] = (Param*)FUN_0008d690(32);
  if (items[1]) {
   items[1]->FUN_00234cc0("type");
   new (items[1]) Param;
   items[1]->values = ((int*)&DAT_003f6b40);
   items[1]->count = 23;
   items[1]->callback = FUN_00047e80;
  }
  FUN_002347b0(&DAT_004dc4b8, items, 2);
 }
 ++DAT_004dc4bc;
}
