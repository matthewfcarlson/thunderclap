// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// CAutoTargetAction::vfunc_6 @ 0x000151a0
struct Owner_151a0; struct Actor_151a0; struct Context; struct Effect_151a0;
struct Name_151a0 { void FUN_0027b040(const char*); };
struct Value_151a0 { float FUN_002220d0(); void FUN_00221d20(float); };
struct Effect_151a0 { virtual void vfunc_0(); char pad4[4]; Name_151a0 name; char pad9[11]; int mode; Value_151a0 value; Effect_151a0* FUN_002248f0(int); };
struct Actor_151a0 { char pad[16]; Value_151a0 value; void FUN_00222890(Effect_151a0*,float,unsigned int,float,unsigned int,unsigned int,float); };
struct Context { Actor_151a0* FUN_00059a40(); };
struct Owner_151a0 { Context* FUN_000592a0(); };
struct Params { char pad[44]; unsigned int a,b,c; };
void* __cdecl FUN_00263ea0(unsigned int);
struct CAutoTargetAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); char pad[24]; Owner_151a0* owner; Params* params; Effect_151a0* effect; };
bool CAutoTargetAction::vfunc_6(int) { Actor_151a0* actor=owner->FUN_000592a0()->FUN_00059a40(); if(!actor) return false; unsigned int a=params->a,b=params->b,c=params->c; Effect_151a0* e=(Effect_151a0*)FUN_00263ea0(112); if(e) e=e->FUN_002248f0(0); effect=e; e->name.FUN_0027b040("autoTarget"); effect->vfunc_0(); float v=actor->value.FUN_002220d0(); effect->value.FUN_00221d20(v); effect->mode=2; actor->FUN_00222890(effect,-1.0f,a,1.0f,b,c,-1.0f); return true; }