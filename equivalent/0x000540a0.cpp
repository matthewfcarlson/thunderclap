// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 6/6)
// FUN_000540a0 @ 0x000540a0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void FUN_00048060();
void FUN_00048070();
void* __cdecl FUN_0008d690(unsigned int);
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12];
 const void* values;
 int count;
 void (*callback)();
 int trailing;
 void FUN_00234cc0(const char*);
};
}
class CMotionHitCondition;
typedef fight::ParamEnumConstList<CMotionHitCondition> Entry_540a0;
void __cdecl FUN_002347b0(void*,Entry_540a0**,int);
void __cdecl target() {
 if (DAT_004dc52c == 0) {
  Entry_540a0* entries[2];
  Entry_540a0* p = (Entry_540a0*)FUN_0008d690(32);
  if (p) {
   int n = (*(int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   new (p) Entry_540a0;
   p->count=n;
   p->values=((char*)&DAT_00427758);
   p->callback=FUN_00048060;
  }
  entries[0]=p;
  p=(Entry_540a0*)FUN_0008d690(32);
  if (p) {
   p->FUN_00234cc0("motionHit");
   new (p) Entry_540a0;
   p->values=((char*)&DAT_0048f9c0);
   p->count=5;
   p->callback=FUN_00048070;
  }
  entries[1]=p;
  FUN_002347b0(&DAT_004dc528,entries,2);
 }
 ++DAT_004dc52c;
}
