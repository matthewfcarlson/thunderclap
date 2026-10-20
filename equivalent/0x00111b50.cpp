// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00111b50 @ 0x00111b50
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_0010c0d0();
void __cdecl FUN_0010c0f0();
void __cdecl FUN_0010c110();
void __cdecl FUN_002347b0(void*, void*, int);
namespace hulkfight { namespace ai { class OnBlockedTriangleCondition; } }
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
template<class T> struct ParamBool {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 int extra;
 void FUN_00234860(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 int extra;
 void FUN_002348e0(const char*);
};
}
void target() {
 if (!DAT_004e0ae4) {
 void* params[3];
 typedef fight::ParamEnumConstList<hulkfight::ai::OnBlockedTriangleCondition> E;
 typedef fight::ParamBool<hulkfight::ai::OnBlockedTriangleCondition> B;
 typedef fight::ParamIntConstRange<hulkfight::ai::OnBlockedTriangleCondition> I;
 E* e=(E*)FUN_0008d690(32);
 if(e) { int count=(*(int*)&DAT_00427754); e->FUN_00234cc0("compare"); new (e) E; e->count=count; e->names=((char*)&DAT_0042773c); e->callback=FUN_0010c0d0; }
 params[0]=e;
 B* b=(B*)FUN_0008d690(24);
 if(b) { b->FUN_00234860("target"); new (b) B; b->callback=FUN_0010c0f0; }
 params[1]=b;
 I* i=(I*)FUN_0008d690(24);
 if(i) { i->FUN_002348e0("smartPropIndex"); new (i) I; i->callback=FUN_0010c110; }
 params[2]=i;
 FUN_002347b0(&DAT_004e0ae0,params,3);
 }
 ++DAT_004e0ae4;
}
