// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::AnimationAction::vfunc_4 @ 0x0013adc0
#include "gen/hulkfight.h"

struct AnimationClip { virtual void vfunc_0(); virtual void vfunc_1(); char pad[0x220]; unsigned char flag; }; struct Context_13adc0 { void* FUN_000592a0(); }; struct Link { void* FUN_00059a40(); }; struct Controller { void FUN_00222b50(AnimationClip*, int, float); void FUN_00222970(AnimationClip*, int); }; namespace hulkfight { namespace motion {   } }
void hulkfight::motion::AnimationAction::vfunc_4() { if ((*(AnimationClip * *)&this->f_24)) { Link* link = (Link*)(*(Context_13adc0 * *)&this->f_20)->FUN_000592a0(); Controller* controller = (Controller*)link->FUN_00059a40(); if (controller) { if ((*(AnimationClip * *)&this->f_24)->flag) controller->FUN_00222b50((*(AnimationClip * *)&this->f_24), 0, -1.0f); else controller->FUN_00222970((*(AnimationClip * *)&this->f_24), 0); if ((*(AnimationClip * *)&this->f_24)) { (*(AnimationClip * *)&this->f_24)->vfunc_1(); (*(AnimationClip * *)&this->f_24) = 0; } } } }
