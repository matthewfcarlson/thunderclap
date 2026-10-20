// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// CAutoTargetAction::vfunc_6 @ 0x000151a0
#include "gen/global.h"

struct Owner_151a0; struct Actor_151a0; struct Context_151a0; struct Effect_151a0;
struct Name_151a0 { void FUN_0027b040(const char*); };
struct Value_151a0 { float FUN_002220d0(); void FUN_00221d20(float); };
struct Effect_151a0 { virtual void vfunc_0(); char pad4[4]; Name_151a0 name; char pad9[11]; int mode; Value_151a0 value; Effect_151a0* FUN_002248f0(int); };
struct Actor_151a0 { char pad[16]; Value_151a0 value; void FUN_00222890(Effect_151a0*,float,unsigned int,float,unsigned int,unsigned int,float); };
struct Context_151a0 { Actor_151a0* FUN_00059a40(); };
struct Owner_151a0 { Context_151a0* FUN_000592a0(); };
struct Params_151a0 { char pad[44]; unsigned int a,b,c; };
void* __cdecl FUN_00263ea0(unsigned int);

bool CAutoTargetAction::vfunc_6(int ) { Actor_151a0* actor=(*(Owner_151a0 * *)&this->f_1c)->FUN_000592a0()->FUN_00059a40(); if(!actor) return false; unsigned int a=(*(Params_151a0 * *)&this->f_20)->a,b=(*(Params_151a0 * *)&this->f_20)->b,c=(*(Params_151a0 * *)&this->f_20)->c; Effect_151a0* e=(Effect_151a0*)FUN_00263ea0(112); if(e) e=e->FUN_002248f0(0); (*(Effect_151a0 * *)&this->f_24)=e; e->name.FUN_0027b040("autoTarget"); (*(Effect_151a0 * *)&this->f_24)->vfunc_0(); float v=actor->value.FUN_002220d0(); (*(Effect_151a0 * *)&this->f_24)->value.FUN_00221d20(v); (*(Effect_151a0 * *)&this->f_24)->mode=2; actor->FUN_00222890((*(Effect_151a0 * *)&this->f_24),-1.0f,a,1.0f,b,c,-1.0f); return true; }
