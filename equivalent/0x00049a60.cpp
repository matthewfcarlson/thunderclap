// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 28/28)
// CSmartPropStateCondition::vfunc_7 @ 0x00049a60
#include "gen/global.h"

struct State_49a60 { char pad[0x40]; int value; };
struct Link_49a60 { char pad[8]; State_49a60* state; int type; };
struct Actor_49a60 { char pad[0x3a4]; Link_49a60* link; State_49a60* FUN_00035ef0(int); };
struct Owner_49a60 { Actor_49a60* FUN_00059a30(); };
struct Context_49a60 { Owner_49a60* FUN_000592a0(); };

bool CSmartPropStateCondition::vfunc_7(void* __p0) { Context_49a60 * context = (Context_49a60 *)__p0;

 Actor_49a60* actor = context->FUN_000592a0()->FUN_00059a30();
 State_49a60* state = actor->FUN_00035ef0(0);
 if (!state) {
  Link_49a60* link = actor->link;
  if (!link || link->type != 5) return false;
  state = link->state;
  if (!state) return false;
 }
 int value = state->value;
 switch ((*(unsigned int *)&this->f_0c)) {
 case 0: return value < this->f_10;
 case 1: return value <= this->f_10;
 case 2: return value == this->f_10;
 case 3: return value != this->f_10;
 case 4: return value >= this->f_10;
 case 5: return value > this->f_10;
 default: return false;
 }
}
