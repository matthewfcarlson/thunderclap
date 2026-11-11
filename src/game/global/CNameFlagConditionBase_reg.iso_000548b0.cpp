// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x000548b0 FUN_000548b0 (213 B): equivalent/0x000548b0.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_000548b0
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_f16e4822 {} using namespace fn_f16e4822;
namespace fn_f16e4822 {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_000548b0 @ 0x000548b0

/* size_t: tree_prelude.h */

} // namespace fn_f16e4822
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f16e4822 {

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl SetAngle_00048200();
void __cdecl SetArc_00048220();
void __cdecl SetMinVelocity_00048240();
class CMotionClimbAngleCondition;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<CMotionClimbAngleCondition> Param;
void __cdecl FUN_002347b0(void*, Param**, int);
extern "C" void __cdecl FUN_000548b0() {
 if (DAT_004dc584 == 0) {
  Param* params[3];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) {p->FUN_00234960("angle"); new(p) Param; p->callback = SetAngle_00048200;} params[0]=p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) {p->FUN_00234960("arc"); new(p) Param; p->callback = SetArc_00048220;} params[1]=p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if(p) {p->FUN_00234960("minVelocity"); new(p) Param; p->callback = SetMinVelocity_00048240;} params[2]=p;
  FUN_002347b0(&DAT_004dc580, params, 3);
 }
 ++DAT_004dc584;
}
} // namespace fn_f16e4822

