// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CCollisionHitLocationCondition::vfunc_7 @ 0x00048bb0
#include "gen/global.h"

struct Target_48bb0 { char pad[0x74]; int value; };
struct Ctx_48bb0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual Target_48bb0* GetTarget(); };

bool CCollisionHitLocationCondition::vfunc_7(void* __p0) { Ctx_48bb0 * ctx = (Ctx_48bb0 *)__p0;

 Target_48bb0* t = ctx->GetTarget();
 if (t) {
  int v = t->value;
  switch ((*(unsigned int *)&this->f_0c)) {
  case 0: return v < this->f_10;
  case 1: return v <= this->f_10;
  case 2: return v == this->f_10;
  case 3: return v != this->f_10;
  case 4: return v >= this->f_10;
  case 5: return v > this->f_10;
  }
 }
 return false;
}
