// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// FUN_0012ce90 @ 0x0012ce90
#include "decls/data/engine/unknown.h"
#include "decls/data/game/hulkfight/ai.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern "C" void* __cdecl FUN_0008d690(unsigned int);
extern "C" void __cdecl FUN_0012b1c0();
extern "C" void __cdecl FUN_0012b1d0();
extern "C" void __cdecl FUN_0012b1e0();
extern "C" void __cdecl FUN_0012b1f0();
extern "C" void __cdecl FUN_002347b0(void*,void**,int);
namespace hulkfight { namespace ai { class ThreatDistanceCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot(); char pad[12]; const char* values; int count; void (__cdecl *callback)(); int end; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void slot(); char pad[12]; void (__cdecl *callback)(); int end; void FUN_00234960(const char*); };
template<class T> struct ParamName { virtual void slot(); char pad[12]; void (__cdecl *callback)(); int end; void FUN_00234a90(const char*); };
template<class T> struct ParamBool { virtual void slot(); char pad[12]; void (__cdecl *callback)(); int end; void FUN_00234860(const char*); };
}
void initialize() {
 if (DAT_004e0e20 == 0) {
 void* params[4];
 typedef hulkfight::ai::ThreatDistanceCondition T;
 fight::ParamEnumConstList<T>* a=(fight::ParamEnumConstList<T>*)FUN_0008d690(32);
 if(a) { int count=(*(int*)&DAT_00427754); a->FUN_00234cc0("compare"); new (a) fight::ParamEnumConstList<T>; a->count=count; a->values="lwB"; a->callback=FUN_0012b1c0; }
 params[0]=a;
 fight::ParamFloatConstRange<T>* b=(fight::ParamFloatConstRange<T>*)FUN_0008d690(24);
 if(b) { b->FUN_00234960("distance"); new (b) fight::ParamFloatConstRange<T>; b->callback=FUN_0012b1d0; } params[1]=b;
 fight::ParamName<T>* c=(fight::ParamName<T>*)FUN_0008d690(24);
 if(c) { c->FUN_00234a90("threatName"); new (c) fight::ParamName<T>; c->callback=FUN_0012b1e0; } params[2]=c;
 fight::ParamBool<T>* d=(fight::ParamBool<T>*)FUN_0008d690(24);
 if(d) { d->FUN_00234860("threatRespondOnlyOnce"); new (d) fight::ParamBool<T>; d->callback=FUN_0012b1f0; } params[3]=d;
 FUN_002347b0(&DAT_004e0e1c,params,4);
 }
 ++DAT_004e0e20;
}
