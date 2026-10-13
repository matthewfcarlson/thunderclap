// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::HitReactionFloatTrack::vfunc_9 @ 0x0014f470
extern char DAT_00494b44;
extern char DAT_00494b60;
struct Reaction;
struct Context;
struct Temporary {
 char data[0x98];
 void FUN_00059820();
 void FUN_00059300();
};
struct Controller { unsigned char FUN_00231a40(void*, Reaction*); };
struct Link { Controller* FUN_000392e0(); };
struct Result { Link* FUN_00059a30(); };
struct Reaction {
 virtual void slot0();
 virtual void slot1();
 Reaction* FUN_000598e0(void*, Temporary*);
};
struct Context {
 char padding[8];
 void* owner;
 Result* FUN_000592a0(Reaction*);
 void FUN_00059760(Controller*);
};
extern void* __cdecl FUN_00344e74(Context*, int, void*, void*, int);
extern void* __cdecl FUN_0008d690(unsigned int);
// equiv-conv: FUN_0014f2f0 eax edi
extern void FUN_0014f2f0(Context*, Temporary*);
namespace hulkfight { namespace motion {
struct HitReactionFloatTrack {
 int vfunc_9(void*, void*, Context*);
};
int HitReactionFloatTrack::vfunc_9(void* unused, void* argument, Context* context) {
 if (!FUN_00344e74(context, 0, &DAT_00494b44, &DAT_00494b60, 0)) return 1;
 Temporary temporary;
 temporary.FUN_00059820();
 FUN_0014f2f0(context, &temporary);
 Reaction* allocation = (Reaction*)FUN_0008d690(0xb0);
 Reaction* reaction = allocation ? allocation->FUN_000598e0(context->owner, &temporary) : 0;
 reaction->slot0();
 Result* result = context->FUN_000592a0(reaction);
 Link* link = result->FUN_00059a30();
 Controller* controller = link->FUN_000392e0();
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
