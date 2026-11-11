// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00187340..0x00188ab0 (kind game, layer game, confidence high), dominant class hulkfight::motion::PropAddToCollisionTrack
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f52ddce5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f52ddce5 {} using namespace fn_f52ddce5;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_f52ddce5 {
extern "C" void* __cdecl FUN_0008d690(unsigned);
} // namespace fn_f52ddce5
inline void* __cdecl operator new(size_t, void* memory) { return memory; }
namespace fn_f52ddce5 {
namespace hulkfight { namespace motion {
class PropStateByIndexCondition;
} }
namespace fight {
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_002348e0(const char*);
};
}
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 const char* list;
 int count;
 void (__cdecl *callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
}
void __cdecl SetAttachmentIndex_0017f5a0();
void __cdecl SetCompare_0017f5c0();
void __cdecl SetState_0017f5e0();
extern "C" void __cdecl FUN_002347b0(void*,void**,int);


// 0x00187ac0 FUN_00187ac0 (231 B): equivalent/0x00187ac0.cpp
// sym: _FUN_00187ac0 @07a2cf3565a2 @w122f4aee11cf
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_00187ac0 @ 0x00187ac0
extern "C" void __cdecl FUN_00187ac0() {
 if (!DAT_004e1444) {
  void* items[3];
  typedef fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition> IntParam;
  typedef fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition> EnumParam;
  IntParam* a=(IntParam*)FUN_0008d690((int)sizeof(IntParam));
  if(a) { a->FUN_002348e0("attachmentIndex"); new(a) IntParam; a->callback=SetAttachmentIndex_0017f5a0; }
  items[0]=a;
  EnumParam* b=(EnumParam*)FUN_0008d690((int)sizeof(EnumParam));
  if(b) { int count=(*(int*)&DAT_00427754); b->FUN_00234cc0("compare"); new(b) EnumParam; b->count=count; b->list=((char*)&DAT_0042773c); b->callback=SetCompare_0017f5c0; }
  items[1]=b;
  IntParam* c=(IntParam*)FUN_0008d690((int)sizeof(IntParam));
  if(c) { c->FUN_002348e0("state"); new(c) IntParam; c->callback=SetState_0017f5e0; }
  items[2]=c;
  FUN_002347b0(&DAT_004e1440,items,3);
 }
 ++DAT_004e1444;
}

} // namespace fn_f52ddce5
