// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00128240..0x001296f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::AcquireTargetTrack
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_fac20c96 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fac20c96 {} using namespace fn_fac20c96;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* address) { return address; }
namespace fn_fac20c96 {
void* __cdecl FUN_0008d690(unsigned int);
char SetCompare_00123600(void*, int); /* (unb5) as defined; address taken only */
char SetType_00123610(void*, int); /* (unb5) as defined; address taken only */
namespace hulkfight { namespace ai {
class TargetTypeCondition;
} }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 int* values;
 int count;
 void (*callback)();
 int extra;
 void FUN_00234cc0(const char*);
};
}
void __cdecl FUN_002347b0(int*,void*,int);


// 0x001285a0 FUN_001285a0 (190 B): equivalent/0x001285a0.cpp
// sym: ?target@fn_fac20c96@@YAXXZ @fc8dcb13f8ef @w27c6948ecfa6
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_001285a0 @ 0x001285a0
void target() {
 typedef fight::ParamEnumConstList<hulkfight::ai::TargetTypeCondition> Param;
 if (!DAT_004e0d78) {
  Param* list[2];
  list[0]=(Param*)FUN_0008d690((int)sizeof(Param));
  if(list[0]) {
   int count=(*(int*)&DAT_00427760);
   list[0]->FUN_00234cc0("compare");
   list[0]->count=count;
   new(list[0]) Param;
   list[0]->values=((int*)&DAT_00427758);
   list[0]->callback=(void (*)())SetCompare_00123600;
  }
  list[1]=(Param*)FUN_0008d690((int)sizeof(Param));
  if(list[1]) {
   list[1]->FUN_00234cc0("type");
   new(list[1]) Param;
   list[1]->values=((int*)&DAT_004a6acc);
   list[1]->count=2;
   list[1]->callback=(void (*)())SetType_00123610;
  }
  FUN_002347b0(((int*)&DAT_004e0d74),list,2);
 }
 ++DAT_004e0d78;
}

} // namespace fn_fac20c96
