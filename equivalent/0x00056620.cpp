// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 8/8)
// FUN_00056620 @ 0x00056620
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"

inline void* operator new(unsigned,void* p) { return p; }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; void* list; int count; void (*callback)(); int extra; void FUN_00234cc0(const char*); };
template<class T> struct ParamName { virtual void slot0(); char pad[12]; void (*callback)(); int extra; void FUN_00234a90(const char*); };
template<class T> struct ParamIntConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int extra; void FUN_002348e0(const char*); };
}
class CSmartPropNameCondition;
   
void FUN_00047e90(); void FUN_00047ea0(); void FUN_00047eb0();
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_002347b0(void*,void**,int);
void target() {
 if (!DAT_004dc4c4) {
 void* params[3];
 fight::ParamEnumConstList<CSmartPropNameCondition>* a = (fight::ParamEnumConstList<CSmartPropNameCondition>*)FUN_0008d690(32);
 if(a) { int count=(*(int*)&DAT_00427760); a->FUN_00234cc0("compare"); a->count=count; new (a) fight::ParamEnumConstList<CSmartPropNameCondition>; a->list=((int*)&DAT_00427758); a->callback=FUN_00047e90; }
 params[0]=a;
 fight::ParamName<CSmartPropNameCondition>* b=(fight::ParamName<CSmartPropNameCondition>*)FUN_0008d690(24);
 if(b) { b->FUN_00234a90("name"); new (b) fight::ParamName<CSmartPropNameCondition>; b->callback=FUN_00047ea0; } params[1]=b;
 fight::ParamIntConstRange<CSmartPropNameCondition>* c=(fight::ParamIntConstRange<CSmartPropNameCondition>*)FUN_0008d690(24);
 if(c) { c->FUN_002348e0("attachmentIndex"); new (c) fight::ParamIntConstRange<CSmartPropNameCondition>; c->callback=FUN_00047eb0; } params[2]=c;
 FUN_002347b0(&DAT_004dc4c0,params,3);
 }
 ++DAT_004dc4c4;
}
