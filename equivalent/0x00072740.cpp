// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00072740 @ 0x00072740
#include "decls/data/game/global.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_00068b90();
extern void __cdecl FUN_00068ba0();
extern void __cdecl FUN_00068bb0();
class CMotionHitGroundHeightTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<CMotionHitGroundHeightTrack> Param;
extern void __cdecl FUN_002347b0(int*, Param**, int);
void FUN_00072740() {
 if (!DAT_004dd01c) {
 Param* params[3];
 Param* p = (Param*)FUN_0008d690(24);
 if (p) { p->FUN_00234960("timeBegin"); new(p) Param; p->callback=FUN_00068b90; } params[0]=p;
 p = (Param*)FUN_0008d690(24);
 if (p) { p->FUN_00234960("timeEnd"); new(p) Param; p->callback=FUN_00068ba0; } params[1]=p;
 p = (Param*)FUN_0008d690(24);
 if (p) { p->FUN_00234960("height"); new(p) Param; p->callback=FUN_00068bb0; } params[2]=p;
 FUN_002347b0(&DAT_004dd018, params, 3);
 }
 ++DAT_004dd01c;
}
