// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f43cc60b {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f43cc60b {} using namespace fn_f43cc60b;
#include "game/hulkfight/ai.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f43cc60b {
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetCompare_0010c0d0();
void __cdecl SetTarget_0010c0f0();
void __cdecl SetSmartPropIndex_0010c110();
void __cdecl FUN_002347b0(void*, void*, int);
namespace hulkfight { namespace ai {
class OnBlockedTriangleCondition;
} }
namespace fight {
template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 const char* names;
 int count;
 void (__cdecl *callback)();
 int extra;
 void FUN_00234cc0(const char*);
};
}
namespace fight {
template<class T> struct ParamBool {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 int extra;
 void FUN_00234860(const char*);
};
}
namespace fight {
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 int extra;
 void FUN_002348e0(const char*);
};
}


// 0x00111b50 FUN_00111b50 (231 B): equivalent/0x00111b50.cpp
// sym: ?target@fn_f43cc60b@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00111b50 @ 0x00111b50
void target() {
 if (!DAT_004e0ae4) {
 void* params[3];
 typedef fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition> E;
 typedef fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition> B;
 typedef fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition> I;
 E* e=(E*)FUN_0008d690((int)sizeof(E));
 if(e) { int count=(*(int*)&DAT_00427754); e->FUN_00234cc0("compare"); new (e) E; e->count=count; e->names=((char*)&DAT_0042773c); e->callback=SetCompare_0010c0d0; }
 params[0]=e;
 B* b=(B*)FUN_0008d690((int)sizeof(B));
 if(b) { b->FUN_00234860("target"); new (b) B; b->callback=SetTarget_0010c0f0; }
 params[1]=b;
 I* i=(I*)FUN_0008d690((int)sizeof(I));
 if(i) { i->FUN_002348e0("smartPropIndex"); new (i) I; i->callback=SetSmartPropIndex_0010c110; }
 params[2]=i;
 FUN_002347b0(&DAT_004e0ae0,params,3);
 }
 ++DAT_004e0ae4;
}

} // namespace fn_f43cc60b
