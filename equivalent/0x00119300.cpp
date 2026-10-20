// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_00119300 @ 0x00119300
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"

void* __cdecl FUN_0008d690(hulk_uintptr);
void __cdecl FUN_001150d0();
void __cdecl FUN_001150e0();
void __cdecl FUN_00115100();
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace hulkfight { namespace ai { class MotionFleeTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<hulkfight::ai::MotionFleeTrack> Param;
void __cdecl FUN_002347b0(unsigned int*, Param**, int);
void __cdecl target() {
 if (DAT_004e0c48 == 0) {
  Param* entries[3];
  Param* p = (Param*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("timeBegin"); p = new(p) Param; p->callback = FUN_001150d0; }
  entries[0]=p;
  p = (Param*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("timeEnd"); p = new(p) Param; p->callback = FUN_001150e0; }
  entries[1]=p;
  p = (Param*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("speed"); p = new(p) Param; p->callback = FUN_00115100; }
  entries[2]=p;
  FUN_002347b0(&DAT_004e0c44,entries,3);
 }
 ++DAT_004e0c48;
}