// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 10/10)
// FUN_00128ad0 @ 0x00128ad0
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
// Standard placement allocation; it does not allocate or call game code.
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void FUN_00123780(); void FUN_00123790(); void FUN_001237b0(); void FUN_001237d0();
void __cdecl FUN_002347b0(void*,void*,int);
namespace hulkfight { namespace ai { class ProjectileDistanceCondition; } }
namespace fight {
template<class T> struct ParamEnumConstList { virtual void slot0(); char pad[12]; const char* values; int count; void (*callback)(); int tail; void FUN_00234cc0(const char*); };
template<class T> struct ParamFloatConstRange { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234960(const char*); };
template<class T> struct ParamBool { virtual void slot0(); char pad[12]; void (*callback)(); int tail; void FUN_00234860(const char*); };
}
void FUN_00128ad0() {
 if (!DAT_004e0da8) {
 void* params[4];
 typedef fight::ParamEnumConstList<hulkfight::ai::ProjectileDistanceCondition> Enum;
 typedef fight::ParamFloatConstRange<hulkfight::ai::ProjectileDistanceCondition> Float;
 typedef fight::ParamBool<hulkfight::ai::ProjectileDistanceCondition> Bool;
 Enum* e=(Enum*)FUN_0008d690(32);
 if(e) { int n=(*(int*)&DAT_00427754); e->FUN_00234cc0("compare"); new(e) Enum; e->count=n; e->values=((char*)&DAT_0042773c); e->callback=FUN_00123780; }
 params[0]=e;
 Float* f=(Float*)FUN_0008d690(24);
 if(f) { f->FUN_00234960("distance"); new(f) Float; f->callback=FUN_00123790; }
 params[1]=f;
 Bool* b=(Bool*)FUN_0008d690(24);
 if(b) { b->FUN_00234860("onlyRespondtoEvil"); new(b) Bool; b->callback=FUN_001237b0; }
 params[2]=b;
 b=(Bool*)FUN_0008d690(24);
 if(b) { b->FUN_00234860("onlyRespondtoProps"); new(b) Bool; b->callback=FUN_001237d0; }
 params[3]=b;
 FUN_002347b0(((int*)&DAT_004e0da4),params,4);
 }
 ++DAT_004e0da8;
}
