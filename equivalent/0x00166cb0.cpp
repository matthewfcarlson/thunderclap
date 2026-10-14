// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 24/24)
// hulkfight::motion::GrappleReactionTypeCondition::vfunc_6 @ 0x00166cb0
extern char DAT_00494b44;
extern char DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct ActorState { void FUN_00059a30(); };
struct Actor { ActorState* FUN_000592a0(); };
struct Reaction { char pad[0x394]; int reactionType; };
extern Reaction* __cdecl FUN_00048260(Actor*);
namespace hulkfight { namespace motion {
struct GrappleReactionTypeCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Actor*, void*);
 char pad[8]; unsigned comparison; int value;
};
bool GrappleReactionTypeCondition::vfunc_6(void*, Actor* actor, void*) {
 if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 actor->FUN_000592a0()->FUN_00059a30();
 Reaction* reaction = FUN_00048260(actor);
 if (!reaction) return false;
 int actual = reaction->reactionType;
 switch (comparison) {
 case 0: return actual < value;
 case 1: return actual <= value;
 case 2: return actual == value;
 case 3: return actual != value;
 case 4: return actual >= value;
 case 5: return actual > value;
 default: return false;
 }
}
}}
