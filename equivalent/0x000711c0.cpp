// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 10/10)
// FUN_000711c0 @ 0x000711c0
#include "decls/data/game/global.h"
#include "gen/fight.h"

inline void* operator new(unsigned int, void* p) { return p; }
void __cdecl SetTimeBegin_00068310();
void __cdecl SetTimeEnd_00068320();
void __cdecl SetDistance_00068330();
void __cdecl SetDirection_0006b7b0();
extern "C" void* __cdecl FUN_0008d690(unsigned int);
struct ParamBase_711c0 {
 virtual void placeholder();
 char padding[12];
 void (__cdecl *callback)();
 int tail;
};
class CMoveAddYTrack_711c0;
namespace fight { template<class T> struct ParamFloatConstRange_711c0 : ParamBase_711c0 { virtual void placeholder(); }; }
void __cdecl FUN_002347b0(int*,ParamBase_711c0**,int);
extern "C" void FUN_000711c0() {
 if (DAT_004dcf5c == 0) {
 ParamBase_711c0* items[4];
 ParamBase_711c0* p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetTimeBegin_00068310; } items[0]=p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("timeEnd"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetTimeEnd_00068320; } items[1]=p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("distance"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetDistance_00068330; } items[2]=p;
 p = (ParamBase_711c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>));
 if(p) { ((fight::ParamValueFloat *)(ParamBase_711c0 *)p)->FUN_00234960("direction"); new(p) fight::ParamFloatConstRange_711c0<CMoveAddYTrack_711c0>; p->callback=SetDirection_0006b7b0; } items[3]=p;
 FUN_002347b0(&DAT_004dcf58,items,4);
 }
 ++DAT_004dcf5c;
}
