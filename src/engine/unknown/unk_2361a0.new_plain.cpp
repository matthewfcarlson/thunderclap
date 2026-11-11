// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002361a0..0x002366e0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "decls/data/engine/fight.h"
#include "decls/data/engine/unknown.h"
#define TREE_TU_BEGIN namespace fn_fa4a1c60 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa4a1c60 {} using namespace fn_fa4a1c60;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* address) { return address; }
namespace fn_fa4a1c60 {
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl SetCompare_00235970();
extern void __cdecl GetParent_00235980();
extern void __cdecl SetRecurse_00235990();
extern "C" void __cdecl FUN_002347b0(int*, void**, int);
namespace fight {
class FightNodeParentCondition;
}
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0(); char pad[12]; void* values; int count; void (__cdecl *callback)(); int tail;
 void FUN_00234cc0(const char*);
};
}
namespace fight {
template<class T> struct ParamBranch {
 virtual void slot0(); char pad[12]; void (__cdecl *callback)(); int tail;
 void FUN_00235170(const char*);
};
}
namespace fight {
template<class T> struct ParamBool {
 virtual void slot0(); char pad[12]; void (__cdecl *callback)(); int tail;
 void FUN_00234860(const char*);
};
}


// 0x00236250 FUN_00236250 (231 B): equivalent/0x00236250.cpp
// sym: _FUN_00236250 @995b67afb85c @wcadb8b5b31e1
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_00236250 @ 0x00236250
extern "C" void FUN_00236250() {
 if (!DAT_004e5be8) {
 void* params[3];
 typedef fight::ParamEnumConstList<fight::FightNodeParentCondition> Enum;
 typedef fight::ParamBranch<fight::FightNodeParentCondition> Branch;
 typedef fight::ParamBool<fight::FightNodeParentCondition> Bool;
 Enum* a = (Enum*)FUN_0008d690((int)sizeof(Enum));
 if (a) { int count = (*(int*)&DAT_00427760); a->FUN_00234cc0("compare"); a->count=count; new(a) Enum; a->values=((char*)&DAT_00427758); a->callback=SetCompare_00235970; }
 params[0]=a;
 Branch* b=(Branch*)FUN_0008d690((int)sizeof(Branch));
 if(b) { b->FUN_00235170("parent"); new(b) Branch; b->callback=GetParent_00235980; }
 params[1]=b;
 Bool* c=(Bool*)FUN_0008d690((int)sizeof(Bool));
 if(c) { c->FUN_00234860("recurse"); new(c) Bool; c->callback=SetRecurse_00235990; }
 params[2]=c;
 FUN_002347b0(&DAT_004e5be4,params,3);
 }
 ++DAT_004e5be8;
}

} // namespace fn_fa4a1c60
