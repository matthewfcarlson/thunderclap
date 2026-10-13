// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::HitReactionTrack::vfunc_9 @ 0x0014f110
extern char DAT_00494b44;
extern char DAT_00494b60;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
struct Reaction;
struct Settings { char data[0x98]; void FUN_00059820(); void FUN_00059300(); };
struct Controller { unsigned char FUN_00231a40(void*, Reaction*); };
struct Handle { Controller* FUN_000392e0(); };
struct Link { Handle* FUN_00059a30(); };
struct Owner { char pad[8]; void* field8; Link* FUN_000592a0(Reaction*); void FUN_00059760(Controller*); };
struct Reaction { virtual void vfunc_0(); virtual void vfunc_1(); Reaction* FUN_000598e0(void*, Settings*); };
namespace hulkfight { namespace motion {
struct HitReactionTrack {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9(void*, void*, Owner*);
};
}}
// equiv-conv: FUN_0014efd0 esi edi
extern void FUN_0014efd0(hulkfight::motion::HitReactionTrack*, Settings*);
int hulkfight::motion::HitReactionTrack::vfunc_9(void* unused, void* argument, Owner* owner) {
 if (!FUN_00344e74(owner,0,&DAT_00494b44,&DAT_00494b60,0)) return 1;
 Settings settings;
 settings.FUN_00059820();
 FUN_0014efd0(this,&settings);
 Reaction* reaction = (Reaction*)FUN_0008d690(0xb0);
 if (reaction) reaction = reaction->FUN_000598e0(owner->field8,&settings);
 reaction->vfunc_0();
 Controller* controller = owner->FUN_000592a0(reaction)->FUN_00059a30()->FUN_000392e0();
 owner->FUN_00059760(controller);
 if (!controller) { reaction->vfunc_1(); settings.FUN_00059300(); return 1; }
 unsigned char result = controller->FUN_00231a40(argument,reaction);
 reaction->vfunc_1();
 settings.FUN_00059300();
 return result == 0;
}
