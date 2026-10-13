// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// hulkfight::motion::GrappleHitReactionTrack::vfunc_9 @ 0x00148730
extern char DAT_00494b44, DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Local { char data[0x98]; void FUN_00059820(); void FUN_00059300(); };
struct Item { virtual void v0(); virtual void v1(); Item* FUN_000598e0(void*, Local*); };
struct Manager { unsigned char FUN_00231a40(void*, Item*); };
struct Link2 { Manager* FUN_000392e0(); };
struct Link1 { Link2* FUN_00059a30(); };
struct Actor { Link1* FUN_000592a0(Item*); void FUN_00059760(Manager*); };
struct Source { char pad[16]; void** value; };
struct Builder {};
// equiv-conv: FUN_00148580 ecx esi
void FUN_00148580(Builder*, Local*);
extern "C" Builder* __cdecl FUN_0005a470(Actor*);
extern "C" Source* __cdecl FUN_0005a430(Actor*);
extern "C" void* __cdecl FUN_0005a3f0(Actor*);
extern "C" void* __cdecl FUN_0008d690(unsigned);
namespace hulkfight { namespace motion {
struct GrappleHitReactionTrack {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual int vfunc_9(int, int, Actor*); virtual void vfunc_10();
};
int GrappleHitReactionTrack::vfunc_9(int, int, Actor* actor) {
if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return 1;
Local local; local.FUN_00059820();
FUN_00148580(FUN_0005a470(actor), &local);
Item* item = (Item*)FUN_0008d690(0xb0);
if (item) item = item->FUN_000598e0(*FUN_0005a430(actor)->value,&local);
item->v0();
Manager* manager = actor->FUN_000592a0(item)->FUN_00059a30()->FUN_000392e0();
actor->FUN_00059760(manager);
if (!manager) { item->v1(); local.FUN_00059300(); return 1; }
unsigned char result = manager->FUN_00231a40(FUN_0005a3f0(actor),item);
item->v1(); local.FUN_00059300(); return result == 0;
}
}}
