// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::HitEffectAction::vfunc_3 @ 0x001445d0
struct Vec_1445d0 { float x,y,z; bool FUN_0022d2b0(Vec_1445d0*,float); };
struct Pair_1445d0 { float x,y; };
struct Matrix { float m[16]; void FUN_0022b980(); void FUN_0022be40(Vec_1445d0*); };
void __cdecl FUN_00224db0(Matrix*,Vec_1445d0*,Vec_1445d0*);
struct Hit_1445d0 { char pad[8]; Vec_1445d0 position; char gap[4]; Vec_1445d0 direction; };
struct Inner_1445d0 { void FUN_00059a30(); };
struct Actor_1445d0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual Hit_1445d0* s3(); Inner_1445d0* FUN_000592a0(); };
struct Settings_1445d0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual float s6(); char pad[12]; float time; char gap[4]; Pair_1445d0 a; unsigned int b; unsigned int gap2; unsigned int c; unsigned int d; unsigned int e; unsigned int f; };
struct EffectManager { void FUN_00025590(Hit_1445d0*,Pair_1445d0*,unsigned int,unsigned int*,unsigned int,Matrix*,float,unsigned int); };
struct Global_1445d0 { char pad[32]; EffectManager* manager; }; extern Global_1445d0* DAT_004dd700;
namespace hulkfight { namespace motion { struct HitEffectAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(unsigned int,unsigned int); virtual void vfunc_4(); virtual void vfunc_5(); char pad[28]; Settings_1445d0* settings; Actor_1445d0* actor; }; 
bool HitEffectAction::vfunc_3(unsigned int,unsigned int) { actor->FUN_000592a0()->FUN_00059a30(); Hit_1445d0* hit=actor->s3(); if(hit) { Vec_1445d0 position=hit->position; Vec_1445d0 direction=hit->direction; Matrix matrix; matrix.FUN_0022b980(); Vec_1445d0 up; up.x=0;up.y=1;up.z=0; if(!direction.FUN_0022d2b0(&up,0.00001f)) { up.x=0;up.y=1;up.z=0; FUN_00224db0(&matrix,&up,&direction); } matrix.FUN_0022be40(&position); float time=settings->time; float remaining=time-settings->s6(); Settings_1445d0* s=settings; DAT_004dd700->manager->FUN_00025590(hit,&s->a,s->b,&s->c,s->e,&matrix,remaining,s->f); } return false; }
} }
