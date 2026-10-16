// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 8/8)
// FUN_000610c0 @ 0x000610c0
#include "decls/data/game/global.h"

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_000604d0();
void __cdecl FUN_000604e0();
void __cdecl FUN_000604f0();
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
class CEffectStopTrack;
struct FloatBase_610c0 { virtual void slot0(); char pad[12]; void (*callback)(); char tail[4]; void FUN_00234960(const char*); };
struct IntBase_610c0 { virtual void slot0(); char pad[12]; void (*callback)(); char tail[4]; void FUN_002348e0(const char*); };
namespace fight {
template<class T> struct ParamFloatConstRange : FloatBase_610c0 { virtual void slot0(); };
template<class T> struct ParamIntConstRange : IntBase_610c0 { virtual void slot0(); };
}
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_000610c0() {
 if (!DAT_004dc614) {
  void* items[3];
  void* p = FUN_0008d690(24);
  if(p) { ((FloatBase_610c0*)p)->FUN_00234960("timeBegin"); fight::ParamFloatConstRange<CEffectStopTrack>* obj = new(p) fight::ParamFloatConstRange<CEffectStopTrack>; obj->callback=FUN_000604d0; }
  items[0]=p;
  p=FUN_0008d690(24);
  if(p) { ((IntBase_610c0*)p)->FUN_002348e0("slot"); fight::ParamIntConstRange<CEffectStopTrack>* obj = new(p) fight::ParamIntConstRange<CEffectStopTrack>; obj->callback=FUN_000604e0; }
  items[1]=p;
  p=FUN_0008d690(24);
  if(p) { ((IntBase_610c0*)p)->FUN_002348e0("slotMax"); fight::ParamIntConstRange<CEffectStopTrack>* obj = new(p) fight::ParamIntConstRange<CEffectStopTrack>; obj->callback=FUN_000604f0; }
  items[2]=p;
  FUN_002347b0(&DAT_004dc610,items,3);
 }
 ++DAT_004dc614;
}