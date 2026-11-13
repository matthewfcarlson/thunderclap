// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00053b00 FUN_00053b00 (190 B): equivalent/0x00053b00.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00053b00 @f6ed2524fce7 @w3969a1a3125d
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
namespace fn_fb14ba15 {} using namespace fn_fb14ba15;
namespace fn_fb14ba15 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_00053b00 @ 0x00053b00


} // namespace fn_fb14ba15
inline void* operator new(size_t, void* p) { return p; }
namespace fn_fb14ba15 {

char SetCompare_00047e70(void*, int); /* (unb5) as defined; address taken only */
bool SetType_00047e80(void*, int); /* (unb5) as defined; address taken only */
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
extern "C" void FUN_00053b00() {
 if (!DAT_004dc4bc) {
  Param* items[2];
  items[0] = (Param*)FUN_0008d690((int)sizeof(Param));
  if (items[0]) {
   int n = (*(int*)&DAT_00427760);
   items[0]->FUN_00234cc0("compare");
   items[0]->count = n;
   new (items[0]) Param;
   items[0]->values = ((int*)&DAT_00427758);
   items[0]->callback = (void (*)())SetCompare_00047e70;
  }
  items[1] = (Param*)FUN_0008d690((int)sizeof(Param));
  if (items[1]) {
   items[1]->FUN_00234cc0("type");
   new (items[1]) Param;
   items[1]->values = ((int*)&DAT_003f6b40);
   items[1]->count = 23;
   items[1]->callback = (void (*)())SetType_00047e80;
  }
  FUN_002347b0(&DAT_004dc4b8, items, 2);
 }
 ++DAT_004dc4bc;
}
} // namespace fn_fb14ba15

