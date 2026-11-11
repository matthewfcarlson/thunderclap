// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00072280 FUN_00072280 (213 B): equivalent/0x00072280.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00072280
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_f5596bf6 {} using namespace fn_f5596bf6;
namespace fn_f5596bf6 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00072280 @ 0x00072280


} // namespace fn_f5596bf6
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f5596bf6 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_00068930();
void __cdecl SetTimeEnd_00068940();
void __cdecl SetExtensionTime_00068950();
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
extern "C" void FUN_00072280() {
 if (!DAT_004dcfd4) {
 Param* params[3];
 Param* p;
 p = (Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("timeBegin"); new (p) Param; p->callback=SetTimeBegin_00068930; }
 params[0]=p;
 p = (Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("timeEnd"); new (p) Param; p->callback=SetTimeEnd_00068940; }
 params[1]=p;
 p = (Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("extensionTime"); new (p) Param; p->callback=SetExtensionTime_00068950; }
 params[2]=p;
 FUN_002347b0(&DAT_004dcfd0,params,3);
 }
 ++DAT_004dcfd4;
}
} // namespace fn_f5596bf6

