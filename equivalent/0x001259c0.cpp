// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::ai::TargetOrientationCondition::vfunc_6 @ 0x001259c0
struct Vec { float x,y,z; void FUN_0022c3b0(const Vec*, Vec*); };
extern Vec DAT_004a6ae4;
extern char DAT_00494b44, DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern float __cdecl FUN_00224f10(Vec*);
extern float __cdecl FUN_00224fc0(float, float);
struct Target { char pad[16]; Vec position; };
struct Link { char pad[0x12c]; Target* target; };
struct Actor { char pad[0x328]; Target* fallback; char gap[4]; Link* link; };
// equiv-conv: FUN_000354c0 ecx stack
extern float __cdecl FUN_000354c0(Actor*, float);
struct Context { Actor* FUN_00059a30(); };
struct Input { Context* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct TargetOrientationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int, Input*, int);
 char pad[8]; float offset; float range;
};
bool TargetOrientationCondition::vfunc_6(int, Input* input, int) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor* actor=input->FUN_000592a0()->FUN_00059a30();
 Target* target=0;
 if(actor->link) target=actor->link->target;
 if(!target) target=actor->fallback;
 if(!target) return false;
 Vec direction;
 target->position.FUN_0022c3b0(&DAT_004a6ae4,&direction);
 float angle=FUN_00224f10(&direction);
 float delta=FUN_00224fc0(FUN_000354c0(actor,angle)+offset,angle);
 union { float f; unsigned int u; } absolute;
 absolute.f=delta; absolute.u &= 0x7fffffff;
 return range*0.5f > absolute.f;
}
}}
