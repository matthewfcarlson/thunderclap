// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_00187ac0 @ 0x00187ac0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
inline void* __cdecl operator new(unsigned, void* memory) { return memory; }
namespace hulkfight { namespace motion { class PropStateByIndexCondition; } }
namespace fight {
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_002348e0(const char*);
};
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
void __cdecl FUN_0017f5a0();
void __cdecl FUN_0017f5c0();
void __cdecl FUN_0017f5e0();
void __cdecl FUN_002347b0(void*,void**,int);
void __cdecl FUN_00187ac0() {
 if (!DAT_004e1444) {
  void* items[3];
  typedef fight::ParamIntConstRange<hulkfight::motion::PropStateByIndexCondition> IntParam;
  typedef fight::ParamEnumConstList<hulkfight::motion::PropStateByIndexCondition> EnumParam;
  IntParam* a=(IntParam*)FUN_0008d690(24);
  if(a) { a->FUN_002348e0("attachmentIndex"); new(a) IntParam; a->callback=FUN_0017f5a0; }
  items[0]=a;
  EnumParam* b=(EnumParam*)FUN_0008d690(32);
  if(b) { int count=(*(int*)&DAT_00427754); b->FUN_00234cc0("compare"); new(b) EnumParam; b->count=count; b->list=((char*)&DAT_0042773c); b->callback=FUN_0017f5c0; }
  items[1]=b;
  IntParam* c=(IntParam*)FUN_0008d690(24);
  if(c) { c->FUN_002348e0("state"); new(c) IntParam; c->callback=FUN_0017f5e0; }
  items[2]=c;
  FUN_002347b0(&DAT_004e1440,items,3);
 }
 ++DAT_004e1444;
}