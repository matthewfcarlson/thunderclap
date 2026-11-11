// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00071bc0 FUN_00071bc0 (256 B): equivalent/0x00071bc0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: ?target@fn_f54903fc@@YAXXZ
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_f54903fc {} using namespace fn_f54903fc;
namespace fn_f54903fc {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00071bc0 @ 0x00071bc0


} // namespace fn_f54903fc
inline void* __cdecl operator new(size_t,void* p) { return p; }
namespace fn_f54903fc {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_000685f0();
void __cdecl SetTimeEnd_00068600();
void __cdecl SetAmplitude_00068610();
void __cdecl SetFrequency_00068620();
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
 p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("timeBegin"); new(p) Param; p->callback=SetTimeBegin_000685f0; } params[0]=p;
 p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("timeEnd"); new(p) Param; p->callback=SetTimeEnd_00068600; } params[1]=p;
 p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("amplitude"); new(p) Param; p->callback=SetAmplitude_00068610; } params[2]=p;
 p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("frequency"); new(p) Param; p->callback=SetFrequency_00068620; } params[3]=p;
 FUN_002347b0(&DAT_004dcfa0,params,4);
 }
 ++DAT_004dcfa4;
}
} // namespace fn_f54903fc

