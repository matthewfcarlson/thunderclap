// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00154c00..0x00156e80 (kind game, layer game, confidence high), dominant class hulkfight::motion::InterruptPriorityTrack
#include "tree_prelude.h"


// 0x00155ea0 FUN_00155ea0 (213 B): equivalent/0x00155ea0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00155ea0
#include "gen/owners.h"
#include "decls/data/game/hulkfight/motion.h"
namespace fn_f38a9d74 {} using namespace fn_f38a9d74;
namespace fn_f38a9d74 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_00155ea0 @ 0x00155ea0


} // namespace fn_f38a9d74
__forceinline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f38a9d74 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetTimeBegin_0014caa0();
void __cdecl SetPauseTime_0014cac0();
void __cdecl SetBlendOutTime_0014cae0();
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
extern "C" void __cdecl FUN_00155ea0() {
 if (!DAT_004e10ec) {
 Param* params[3];
 Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("timeBegin"); new (p) Param; p->callback = SetTimeBegin_0014caa0; }
 params[0]=p;
 p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("pauseTime"); new (p) Param; p->callback = SetPauseTime_0014cac0; }
 params[1]=p;
 p=(Param*)FUN_0008d690((int)sizeof(Param));
 if(p) { p->FUN_00234960("blendOutTime"); new (p) Param; p->callback = SetBlendOutTime_0014cae0; }
 params[2]=p;
 FUN_002347b0(&DAT_004e10e8,params,3);
 }
 ++DAT_004e10ec;
}
} // namespace fn_f38a9d74

