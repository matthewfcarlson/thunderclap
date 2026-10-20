// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// FUN_0017a340 @ 0x0017a340
#include "compat/ptr.h"
#include "decls/data/game/hulkfight/motion.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_0016f200();
void __cdecl FUN_0016f210();
void __cdecl FUN_0016f230();
void* __cdecl FUN_0008d690(hulk_uintptr);
namespace hulkfight { namespace motion { class MomentumXZAddTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char padding[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
};
}
typedef fight::ParamFloatConstRange<hulkfight::motion::MomentumXZAddTrack> Param;
void __cdecl FUN_002347b0(unsigned int*, Param**, int);
void target() {
 if (DAT_004e134c == 0) {
  Param* params[3];
  Param* p = (Param*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("timeBegin"); new (p) Param; p->callback = FUN_0016f200; }
  params[0] = p;
  p = (Param*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("timeEnd"); new (p) Param; p->callback = FUN_0016f210; }
  params[1] = p;
  p = (Param*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("finalVelocity"); new (p) Param; p->callback = FUN_0016f230; }
  params[2] = p;
  FUN_002347b0(&DAT_004e1348, params, 3);
 }
 ++DAT_004e134c;
}
