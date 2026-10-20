// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00072280 @ 0x00072280
#include "compat/ptr.h"
#include "decls/data/game/global.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_00068930();
void __cdecl FUN_00068940();
void __cdecl FUN_00068950();
class CUninterruptibleTrack;
namespace fight {
 template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
 };
}
typedef fight::ParamFloatConstRange<CUninterruptibleTrack> Param;
void __cdecl FUN_002347b0(int*, Param**, int);
void FUN_00072280() {
 if (!DAT_004dcfd4) {
 Param* params[3];
 Param* p;
 p = (Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeBegin"); new (p) Param; p->callback=FUN_00068930; }
 params[0]=p;
 p = (Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeEnd"); new (p) Param; p->callback=FUN_00068940; }
 params[1]=p;
 p = (Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("extensionTime"); new (p) Param; p->callback=FUN_00068950; }
 params[2]=p;
 FUN_002347b0(&DAT_004dcfd0,params,3);
 }
 ++DAT_004dcfd4;
}
