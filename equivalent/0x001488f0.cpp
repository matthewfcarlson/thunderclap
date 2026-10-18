// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 6/6)
// hulkfight::motion::GrappleHitReactionAction::vfunc_3 @ 0x001488f0
// hulkfight::motion::GrappleHitReactionAction::vfunc_3 @ 0x001488f0
struct Context;
struct ReactionData { char data[0x78]; int value; char tail[0x1c]; void FUN_00059820(); void FUN_00059300(); };
struct Controller_1488f0 { void FUN_000437a0(int, ReactionData*, void*, int, int); };
struct Intermediate_1488f0 { Controller_1488f0* FUN_00059a30(); };
struct Actor_1488f0 { char pad[12]; int fieldC; Intermediate_1488f0* FUN_000592a0(); };
// equiv-conv: FUN_00148580 ecx esi edi
bool FUN_00148580(Actor_1488f0*, ReactionData*, int);
struct Motion_1488f0 { int first; int second; char pad[0x24]; void FUN_002322f0(int,int); bool FUN_00231ee0(); };
namespace hulkfight { namespace motion {
struct GrappleHitReactionAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
 char pad4[8]; unsigned flags; char pad10[12]; int field1C; Actor_1488f0* actor; Motion_1488f0 motion; int argument; unsigned char active;
};
bool GrappleHitReactionAction::vfunc_3(int a,int b) {
 argument=a;
 Controller_1488f0* controller=actor->FUN_000592a0()->FUN_00059a30();
 if(!controller) return false;
 ReactionData data;
 data.FUN_00059820();
 if(!FUN_00148580(actor, &data, field1C)) { data.FUN_00059300(); return false; }
 controller->FUN_000437a0(data.value,&data,&motion,actor->fieldC,0);
 if(motion.second) flags &= ~3u; else flags=(flags & ~2u)|1u;
 motion.FUN_002322f0(argument,b);
 active=1;
 bool result=motion.FUN_00231ee0();
 data.FUN_00059300();
 return result;
}
}}
