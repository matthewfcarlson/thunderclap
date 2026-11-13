// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00054660 FUN_00054660 (231 B): equivalent/0x00054660.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00054660 @fe5d344ddd0f @wd6ed4354e066
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_fdd675a5 {} using namespace fn_fdd675a5;
namespace fn_fdd675a5 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_00054660 @ 0x00054660

void* __cdecl FUN_0008d690(unsigned int);

} // namespace fn_fdd675a5
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fdd675a5 {

bool SetCompare_00048190(void*, int); /* (unb5) as defined; address taken only */ void* GetFightNode_000481a0(void*); /* (unb5) as defined; address taken only */ char SetLastFrame_000481b0(void*, char); /* (unb5) as defined; address taken only */
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
extern "C" void FUN_00054660() {
 if (!DAT_004dc56c) {
 void* list[3];
 void* p=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CFightNodePrevCondition>));
 if(p) {
 int count=(*(int*)&DAT_00427760);
 ((fight::ParamEnumConstList<CFightNodePrevCondition>*)p)->FUN_00234cc0("compare");
 fight::ParamEnumConstList<CFightNodePrevCondition>* obj=new(p) fight::ParamEnumConstList<CFightNodePrevCondition>;
 obj->count=count; obj->values=((int*)&DAT_00427758); obj->callback=(void (*)())SetCompare_00048190;
 }
 list[0]=p;
 p=FUN_0008d690((int)sizeof(fight::ParamBranch<CFightNodePrevCondition>));
 if(p) {
 ((fight::ParamBranch<CFightNodePrevCondition>*)p)->FUN_00235170("fightNode");
 fight::ParamBranch<CFightNodePrevCondition>* obj=new(p) fight::ParamBranch<CFightNodePrevCondition>;
 obj->callback=(void (*)())GetFightNode_000481a0;
 }
 list[1]=p;
 p=FUN_0008d690((int)sizeof(fight::ParamBool<CFightNodePrevCondition>));
 if(p) {
 ((fight::ParamBool<CFightNodePrevCondition>*)p)->FUN_00234860("lastFrame");
 fight::ParamBool<CFightNodePrevCondition>* obj=new(p) fight::ParamBool<CFightNodePrevCondition>;
 obj->callback=(void (*)())SetLastFrame_000481b0;
 }
 list[2]=p;
 FUN_002347b0(&DAT_004dc568,list,3);
 }
 ++DAT_004dc56c;
}
} // namespace fn_fdd675a5

