// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00070620..0x00072590 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x000718c0 FUN_000718c0 (213 B): equivalent/0x000718c0.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: _FUN_000718c0
#include "gen/owners.h"
#include "decls/data/game/global.h"
namespace fn_fe016cb5 {} using namespace fn_fe016cb5;
namespace fn_fe016cb5 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_000718c0 @ 0x000718c0

/* size_t: tree_prelude.h */

} // namespace fn_fe016cb5
inline void* operator new(size_t, void* p) { return p; }
namespace fn_fe016cb5 {

class CComboTimerTrack;
void __cdecl SetTimeBegin_00068550();
void __cdecl SetTimeEnd_00068560();
void __cdecl SetComboTimer_00068570();
struct ParamBase_718c0 {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char* name);
};
namespace fight {
 template<class T> struct ParamFloatConstRange : ParamBase_718c0 {
 virtual void slot0();
 };
}
void* __cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_002347b0(void* registry, ParamBase_718c0** params, int count);
extern "C" void __cdecl FUN_000718c0() {
 if (!DAT_004dcf84) {
  ParamBase_718c0* params[3];
  ParamBase_718c0* p = (ParamBase_718c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CComboTimerTrack>));
  if (p) {
   p->FUN_00234960("timeBegin");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = SetTimeBegin_00068550;
  }
  params[0] = p;
  p = (ParamBase_718c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CComboTimerTrack>));
  if (p) {
   p->FUN_00234960("timeEnd");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = SetTimeEnd_00068560;
  }
  params[1] = p;
  p = (ParamBase_718c0*)FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<CComboTimerTrack>));
  if (p) {
   p->FUN_00234960("comboTimer");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = SetComboTimer_00068570;
  }
  params[2] = p;
  FUN_002347b0(&DAT_004dcf80, params, 3);
 }
 ++DAT_004dcf84;
}
} // namespace fn_fe016cb5

