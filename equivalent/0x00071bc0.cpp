// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00071bc0 @ 0x00071bc0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* __cdecl operator new(unsigned int,void* p) { return p; }
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_000685f0();
void __cdecl FUN_00068600();
void __cdecl FUN_00068610();
void __cdecl FUN_00068620();
class CCameraShakeTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void dummy();
 char pad[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<CCameraShakeTrack> Param;
void __cdecl FUN_002347b0(void*,Param**,int);
void target() {
 if(DAT_004dcfa4==0) {
 Param* params[4];
 Param* p;
 p=(Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeBegin"); new(p) Param; p->callback=FUN_000685f0; } params[0]=p;
 p=(Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeEnd"); new(p) Param; p->callback=FUN_00068600; } params[1]=p;
 p=(Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("amplitude"); new(p) Param; p->callback=FUN_00068610; } params[2]=p;
 p=(Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("frequency"); new(p) Param; p->callback=FUN_00068620; } params[3]=p;
 FUN_002347b0(&DAT_004dcfa0,params,4);
 }
 ++DAT_004dcfa4;
}
