// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00111720..0x001133f0 (kind game, layer game, confidence high), dominant class hulkfight::ai::SemaphoreWaitTrack
#include "tree_prelude.h"


// 0x001123a0 FUN_001123a0 (274 B): equivalent/0x001123a0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?target@fn_f37097d7@@YAXXZ @01c359cf2c48 @w59f8228dad81
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"
namespace fn_f37097d7 {} using namespace fn_f37097d7;
namespace fn_f37097d7 {
// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_001123a0 @ 0x001123a0


} // namespace fn_f37097d7
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f37097d7 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetCompare_0010c2c0(); void __cdecl SetDistance_0010c2e0(); void __cdecl SetNumberofAttachedProps_0010c300(); void __cdecl SetNumber_0010c320();
  
namespace hulkfight { namespace ai { class PropsToSuckCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; const char* list; int count; void (__cdecl *callback)(); int tail; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_00234860(const char*); };
template<class T> struct ParamIntConstRange { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); char pad[12]; void (__cdecl *callback)(); int tail; void FUN_002348e0(const char*); };
}
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (DAT_004e0b44 == 0) {
 void* params[4]; typedef hulkfight::ai::PropsToSuckCondition T;
 fight::ParamEnumConstList<T>* a=(fight::ParamEnumConstList<T>*)FUN_0008d690((int)sizeof(fight::ParamEnumConstList<T>));
 if(a) { int count=(*(int*)&DAT_00427754); a->FUN_00234cc0("compare"); a->count=count; new(a) fight::ParamEnumConstList<T>; a->list="lwB"; a->callback=SetCompare_0010c2c0; } params[0]=a;
 fight::ParamFloatConstRange<T>* b=(fight::ParamFloatConstRange<T>*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<T>));
 if(b) { b->FUN_00234960("distance"); new(b) fight::ParamFloatConstRange<T>; b->callback=SetDistance_0010c2e0; } params[1]=b;
 fight::ParamBool<T>* c=(fight::ParamBool<T>*)FUN_0008d690((int)sizeof(fight::ParamBool<T>));
 if(c) { c->FUN_00234860("numberofAttachedProps"); new(c) fight::ParamBool<T>; c->callback=SetNumberofAttachedProps_0010c300; } params[2]=c;
 fight::ParamIntConstRange<T>* d=(fight::ParamIntConstRange<T>*)FUN_0008d690((int)sizeof(fight::ParamIntConstRange<T>));
 if(d) { d->FUN_002348e0("number"); new(d) fight::ParamIntConstRange<T>; d->callback=SetNumber_0010c320; } params[3]=d;
 FUN_002347b0(&DAT_004e0b40,params,4);
 } ++DAT_004e0b44;
}
} // namespace fn_f37097d7

