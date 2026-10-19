// STATUS: equivalent (tools/equiv.py level 3: 16070 inputs, branch coverage 8/8)
// hulkfight::motion::HitReactionTrack::vfunc_9 @ 0x0014f110
// hulkfight::motion::HitReactionTrack::vfunc_9 @ 0x0014f110
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
struct Reaction_14f110;
struct Settings_14f110 { char data[0x98]; void FUN_00059820(); void FUN_00059300(); };
struct Controller_14f110 { unsigned char FUN_00231a40(void*, Reaction_14f110*); };
struct Handle_14f110 { Controller_14f110* FUN_000392e0(Reaction_14f110*); };
struct Link_14f110 { Handle_14f110* FUN_00059a30(); };
struct Owner_14f110 { char pad[8]; void* field8; Link_14f110* FUN_000592a0(); void FUN_00059760(Controller_14f110*); };
struct Reaction_14f110 { virtual void vfunc_0(); virtual void vfunc_1(); Reaction_14f110* FUN_000598e0(void*, Settings_14f110*); };
namespace hulkfight { namespace motion {
struct HitReactionTrack {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9(void*, void*, Owner_14f110*);
};
}}
// equiv-conv: FUN_0014efd0 ebx esi edi
extern void FUN_0014efd0(Owner_14f110*, hulkfight::motion::HitReactionTrack*, Settings_14f110*);
int hulkfight::motion::HitReactionTrack::vfunc_9(void* unused, void* argument, Owner_14f110* owner) {
 if (!FUN_00344e74(owner,0,&DAT_00494b44,&DAT_00494b60,0)) return 1;
 Settings_14f110 settings;
 settings.FUN_00059820();
 FUN_0014efd0(owner,this,&settings);
 Reaction_14f110* reaction = (Reaction_14f110*)FUN_0008d690(0xb0);
 if (reaction) reaction = reaction->FUN_000598e0(owner->field8,&settings);
 reaction->vfunc_0();
 Controller_14f110* controller = owner->FUN_000592a0()->FUN_00059a30()->FUN_000392e0(reaction);
 owner->FUN_00059760(controller);
 if (!controller) { reaction->vfunc_1(); settings.FUN_00059300(); return 1; }
 unsigned char result = controller->FUN_00231a40(argument,reaction);
 reaction->vfunc_1();
 settings.FUN_00059300();
 return result == 0;
}
