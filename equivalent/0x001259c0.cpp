// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::ai::TargetOrientationCondition::vfunc_6 @ 0x001259c0
#include "decls/data/game/hulkfight/ai.h"

struct Vec_1259c0 { float x,y,z; void FUN_0022c3b0(const Vec_1259c0*, Vec_1259c0*); };
extern char DAT_00494b44, DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern float __cdecl FUN_00224f10(Vec_1259c0*);
extern float __cdecl FUN_00224fc0(float, float);
struct Target_1259c0 { char pad[16]; Vec_1259c0 position; };
struct Link_1259c0 { char pad[0x12c]; Target_1259c0* target; };
struct Actor_1259c0 { char pad[0x328]; Target_1259c0* fallback; char gap[4]; Link_1259c0* link; };
// equiv-conv: FUN_000354c0 ecx stack
extern float __cdecl FUN_000354c0(Actor_1259c0*, float);
struct Context { Actor_1259c0* FUN_00059a30(); };
struct Input_1259c0 { Context* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct TargetOrientationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int, Input_1259c0*, int);
 char pad[8]; float offset; float range;
};
bool TargetOrientationCondition::vfunc_6(int, Input_1259c0* input, int) {
 if (!FUN_00344e74(input,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor_1259c0* actor=input->FUN_000592a0()->FUN_00059a30();
 Target_1259c0* target=0;
 if(actor->link) target=actor->link->target;
 if(!target) target=actor->fallback;
 if(!target) return false;
 Vec_1259c0 direction;
 target->position.FUN_0022c3b0(((Vec_1259c0*)&DAT_004a6ae4),&direction);
 float angle=FUN_00224f10(&direction);
 float delta=FUN_00224fc0(FUN_000354c0(actor,angle)+offset,angle);
 union { float f; unsigned int u; } absolute;
 absolute.f=delta; absolute.u &= 0x7fffffff;
 return range*0.5f > absolute.f;
}
}}
