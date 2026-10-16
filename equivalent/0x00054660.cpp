// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_00054660 @ 0x00054660
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void FUN_00048190(); void FUN_000481a0(); void FUN_000481b0();
class CFightNodePrevCondition;
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char pad[12]; int* values; int count; void (*callback)(); int extra;
 void FUN_00234cc0(const char*);
};
template<class T> struct ParamBranch {
 virtual void slot0();
 char pad[12]; void (*callback)(); int extra;
 void FUN_00235170(const char*);
};
template<class T> struct ParamBool {
 virtual void slot0();
 char pad[12]; void (*callback)(); int extra;
 void FUN_00234860(const char*);
};
}
void __cdecl FUN_002347b0(int*, void**, int);
void FUN_00054660() {
 if (!DAT_004dc56c) {
 void* list[3];
 void* p=FUN_0008d690(32);
 if(p) {
 int count=(*(int*)&DAT_00427760);
 ((fight::ParamEnumConstList<CFightNodePrevCondition>*)p)->FUN_00234cc0("compare");
 fight::ParamEnumConstList<CFightNodePrevCondition>* obj=new(p) fight::ParamEnumConstList<CFightNodePrevCondition>;
 obj->count=count; obj->values=((int*)&DAT_00427758); obj->callback=FUN_00048190;
 }
 list[0]=p;
 p=FUN_0008d690(24);
 if(p) {
 ((fight::ParamBranch<CFightNodePrevCondition>*)p)->FUN_00235170("fightNode");
 fight::ParamBranch<CFightNodePrevCondition>* obj=new(p) fight::ParamBranch<CFightNodePrevCondition>;
 obj->callback=FUN_000481a0;
 }
 list[1]=p;
 p=FUN_0008d690(24);
 if(p) {
 ((fight::ParamBool<CFightNodePrevCondition>*)p)->FUN_00234860("lastFrame");
 fight::ParamBool<CFightNodePrevCondition>* obj=new(p) fight::ParamBool<CFightNodePrevCondition>;
 obj->callback=FUN_000481b0;
 }
 list[2]=p;
 FUN_002347b0(&DAT_004dc568,list,3);
 }
 ++DAT_004dc56c;
}
