// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00053e30 @ 0x00053e30
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_00047fa0();
void __cdecl FUN_00047fb0();
void __cdecl FUN_002347b0(void*,void*,int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
class CGrappleSizeCondition;
struct FUN_00234cc0 {
 FUN_00234cc0(const char*);
 virtual void slot0();
 char pad[12];
};
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 {
 void* values;
 int count;
 void (__cdecl *callback)();
 int tail;
 ParamEnumConstList(const char* s) : FUN_00234cc0(s) {}
 virtual void slot0();
};
}
void FUN_00053e30() {
 if (!DAT_004dc4fc) {
  fight::ParamEnumConstList<CGrappleSizeCondition>* p[2];
  void* mem=FUN_0008d690(32);
  if(mem) {
   int count=(*(int*)&DAT_00427760);
   p[0]=new(mem) fight::ParamEnumConstList<CGrappleSizeCondition>("compare");
   p[0]->values=((char*)&DAT_00427758); p[0]->count=count; p[0]->callback=FUN_00047fa0;
  } else p[0]=0;
  mem=FUN_0008d690(32);
  if(mem) {
   int count=(*(int*)&DAT_003f5eb4);
   p[1]=new(mem) fight::ParamEnumConstList<CGrappleSizeCondition>("size");
   p[1]->values=((char*)&DAT_0048f6b4); p[1]->count=count; p[1]->callback=FUN_00047fb0;
  } else p[1]=0;
  FUN_002347b0(&DAT_004dc4f8,p,2);
 }
 ++DAT_004dc4fc;
}
