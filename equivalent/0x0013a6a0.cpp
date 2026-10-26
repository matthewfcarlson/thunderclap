// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 7/8, incomplete)
// hulkfight::motion::AnimationVelocityScaledAction::vfunc_5 @ 0x0013a6a0
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Actor { void* FUN_000592a0(); }; struct Animation_13a6a0 { void* FUN_00059a40(); }; struct State { bool FUN_00222a00(void*); }; namespace hulkfight { namespace motion {  } } 
bool hulkfight::motion::AnimationVelocityScaledAction::vfunc_5(hulk_intptr type, int unused) { if(type != 1) return true; Animation_13a6a0* anim = (Animation_13a6a0*)(*(Actor * *)&this->f_20)->FUN_000592a0(); State* state = (State*)anim->FUN_00059a40(); if (!state) return false; return !state->FUN_00222a00((*(void * *)&this->f_24)); }
