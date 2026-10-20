// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00155ea0 @ 0x00155ea0
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

__forceinline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_0014caa0();
void __cdecl FUN_0014cac0();
void __cdecl FUN_0014cae0();
namespace hulkfight { namespace motion { class HitPauseTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 char tail[4];
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<hulkfight::motion::HitPauseTrack> Param;
void __cdecl FUN_002347b0(unsigned int*, Param**, int);
void __cdecl FUN_00155ea0() {
 if (!DAT_004e10ec) {
 Param* params[3];
 Param* p = (Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("timeBegin"); new (p) Param; p->callback = FUN_0014caa0; }
 params[0]=p;
 p=(Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("pauseTime"); new (p) Param; p->callback = FUN_0014cac0; }
 params[1]=p;
 p=(Param*)FUN_0008d690(24);
 if(p) { p->FUN_00234960("blendOutTime"); new (p) Param; p->callback = FUN_0014cae0; }
 params[2]=p;
 FUN_002347b0(&DAT_004e10e8,params,3);
 }
 ++DAT_004e10ec;
}
