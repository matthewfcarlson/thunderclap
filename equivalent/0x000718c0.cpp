// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_000718c0 @ 0x000718c0
#include "compat/ptr.h"
#include "decls/data/game/global.h"

typedef unsigned int size_t;
inline void* operator new(size_t, void* p) { return p; }
class CComboTimerTrack;
void __cdecl FUN_00068550();
void __cdecl FUN_00068560();
void __cdecl FUN_00068570();
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
void* __cdecl FUN_0008d690(hulk_uintptr size);
void __cdecl FUN_002347b0(void* registry, ParamBase_718c0** params, int count);
void __cdecl FUN_000718c0() {
 if (!DAT_004dcf84) {
  ParamBase_718c0* params[3];
  ParamBase_718c0* p = (ParamBase_718c0*)FUN_0008d690(24);
  if (p) {
   p->FUN_00234960("timeBegin");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = FUN_00068550;
  }
  params[0] = p;
  p = (ParamBase_718c0*)FUN_0008d690(24);
  if (p) {
   p->FUN_00234960("timeEnd");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = FUN_00068560;
  }
  params[1] = p;
  p = (ParamBase_718c0*)FUN_0008d690(24);
  if (p) {
   p->FUN_00234960("comboTimer");
   new (p) fight::ParamFloatConstRange<CComboTimerTrack>;
   p->callback = FUN_00068570;
  }
  params[2] = p;
  FUN_002347b0(&DAT_004dcf80, params, 3);
 }
 ++DAT_004dcf84;
}
