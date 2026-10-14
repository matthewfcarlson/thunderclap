// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::HitReactionFloatTrack::vfunc_9 @ 0x0014f470
extern char DAT_00494b44;
extern char DAT_00494b60;
struct Reaction_14f470;
struct Context;
struct Temporary_14f470 {
 char data[0x98];
 void FUN_00059820();
 void FUN_00059300();
};
struct Controller_14f470 { unsigned char FUN_00231a40(void*, Reaction_14f470*); };
struct Link_14f470 { Controller_14f470* FUN_000392e0(); };
struct Result_14f470 { Link_14f470* FUN_00059a30(); };
struct Reaction_14f470 {
 virtual void slot0();
 virtual void slot1();
 Reaction_14f470* FUN_000598e0(void*, Temporary_14f470*);
};
struct Context {
 char padding[8];
 void* owner;
 Result_14f470* FUN_000592a0(Reaction_14f470*);
 void FUN_00059760(Controller_14f470*);
};
extern void* __cdecl FUN_00344e74(Context*, int, void*, void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
// equiv-conv: FUN_0014f2f0 eax edi
extern void FUN_0014f2f0(Context*, Temporary_14f470*);
namespace hulkfight { namespace motion {
struct HitReactionFloatTrack {
 int vfunc_9(void*, void*, Context*);
};
int HitReactionFloatTrack::vfunc_9(void* unused, void* argument, Context* context) {
 if (!FUN_00344e74(context, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 1;
 Temporary_14f470 temporary;
 temporary.FUN_00059820();
 FUN_0014f2f0(context, &temporary);
 Reaction_14f470* allocation = (Reaction_14f470*)FUN_0008d690(0xb0);
 Reaction_14f470* reaction = allocation ? allocation->FUN_000598e0(context->owner, &temporary) : 0;
 reaction->slot0();
 Result_14f470* result = context->FUN_000592a0(reaction);
 Link_14f470* link = result->FUN_00059a30();
 Controller_14f470* controller = link->FUN_000392e0();
 context->FUN_00059760(controller);
 if (!controller) {
 reaction->slot1();
 temporary.FUN_00059300();
 return 1;
 }
 unsigned char success = controller->FUN_00231a40(argument, reaction);
 reaction->slot1();
 temporary.FUN_00059300();
 return success == 0;
}
}}
