// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_001313c0 @ 0x001313c0
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void FUN_0012dff0();
extern "C" void FUN_0012e000();
namespace hulkfight { class UnlockableCondition; }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char base[12];
 const char* list;
 int count;
 void (*callback)();
 int tail;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamBool {
 virtual void slot0();
 char base[12];
 void (*callback)();
 int tail;
 void FUN_00234860(const char*);
};
}
extern "C" void __cdecl FUN_002347b0(int*,void**,int);
void __cdecl FUN_001313c0() {
 if (!DAT_004e0e58) {
  void* params[2];
  fight::ParamEnumConstList<hulkfight::UnlockableCondition>* e = (fight::ParamEnumConstList<hulkfight::UnlockableCondition>*)FUN_0008d690(32);
  if(e) {
   e->FUN_00234cc0("unlockable");
   e = new(e) fight::ParamEnumConstList<hulkfight::UnlockableCondition>;
   e->list=((char*)&DAT_0049ceb0); e->count=766; e->callback=FUN_0012dff0;
  }
  params[0]=e;
  fight::ParamBool<hulkfight::UnlockableCondition>* b=(fight::ParamBool<hulkfight::UnlockableCondition>*)FUN_0008d690(24);
  if(b) {
   b->FUN_00234860("locked");
   b = new(b) fight::ParamBool<hulkfight::UnlockableCondition>;
   b->callback=FUN_0012e000;
  }
  params[1]=b;
  FUN_002347b0(&DAT_004e0e54,params,2);
 }
 ++DAT_004e0e58;
}
