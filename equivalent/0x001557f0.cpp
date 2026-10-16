// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_001557f0 @ 0x001557f0
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0014c610(); void __cdecl FUN_0014c620(); void __cdecl FUN_0014c630();
namespace hulkfight { namespace motion { class CollisionSourceNodeCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; unsigned int* values; unsigned int count; void (__cdecl *callback)(); unsigned int extra; void FUN_00234cc0(const char*); };
template<class T> struct ParamBranch { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); unsigned int extra; void FUN_00235170(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char pad[12]; void (__cdecl *callback)(); unsigned int extra; void FUN_00234860(const char*); };
}
void __cdecl FUN_002347b0(unsigned int*, void**, int);
void target() {
 if (!(*(unsigned int*)&DAT_004e109c)) {
 void* params[3]; typedef hulkfight::motion::CollisionSourceNodeCondition Node;
 fight::ParamEnumConstList<Node>* a=(fight::ParamEnumConstList<Node>*)FUN_0008d690(32);
 if(a) { unsigned int count=(*(unsigned int*)&DAT_00427760); a->FUN_00234cc0("compare"); a->count=count; new(a) fight::ParamEnumConstList<Node>; a->values=((unsigned int*)&DAT_00427758); a->callback=FUN_0014c610; } params[0]=a;
 fight::ParamBranch<Node>* b=(fight::ParamBranch<Node>*)FUN_0008d690(24);
 if(b) { b->FUN_00235170("branch"); new(b) fight::ParamBranch<Node>; b->callback=FUN_0014c620; } params[1]=b;
 fight::ParamBool<Node>* c=(fight::ParamBool<Node>*)FUN_0008d690(24);
 if(c) { c->FUN_00234860("checkAncestors"); new(c) fight::ParamBool<Node>; c->callback=FUN_0014c630; } params[2]=c;
 FUN_002347b0(((unsigned int*)&DAT_004e1098),params,3);
 } ++(*(unsigned int*)&DAT_004e109c);
}
