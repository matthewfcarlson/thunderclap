// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 8/8)
// hulkfight::motion::GrappleHitReactionTrack::vfunc_9 @ 0x00148730
// hulkfight::motion::GrappleHitReactionTrack::vfunc_9 @ 0x00148730
#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/global.h"

extern char DAT_00494b44, DAT_00494b60;
extern "C" void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Local_148730 { char data[0x98]; void FUN_00059820(); void FUN_00059300(); };
struct CFightParamsCollision_nv_148730 {
    ::CFightParamsCollision* FUN_000598e0(void*, Local_148730*);
};
struct Manager_148730 { unsigned char FUN_00231a40(void*, ::CFightParamsCollision*); };
struct Link2_148730 { Manager_148730* FUN_000392e0(::CFightParamsCollision*); };
struct Link1_148730 { Link2_148730* FUN_00059a30(); };
struct Actor_148730 { Link1_148730* FUN_000592a0(); void FUN_00059760(Manager_148730*); };
struct Source_148730 { char pad[16]; void** value; };
struct Builder_148730 {};
// equiv-conv: FUN_00148580 ecx esi edi
void FUN_00148580(Builder_148730*, Local_148730*, void*);
extern "C" Builder_148730* __cdecl FUN_0005a470(Actor_148730*);
extern "C" Source_148730* __cdecl FUN_0005a430(Actor_148730*);
extern "C" void* __cdecl FUN_0005a3f0(Actor_148730*);
extern "C" void* __cdecl FUN_0008d690(unsigned);
namespace hulkfight { namespace motion {

}}
int hulkfight::motion::GrappleHitReactionTrack::vfunc_9(hulk_intptr , hulk_intptr , hulk_intptr __p2) { Actor_148730 * actor = (Actor_148730 *)__p2;

if (!FUN_00344e74(actor,0,&DAT_00494b44,&DAT_00494b60,0)) return 1;
Local_148730 local; local.FUN_00059820();
FUN_00148580(FUN_0005a470(actor), &local, this);
::CFightParamsCollision* item = (::CFightParamsCollision*)FUN_0008d690(0xb0);
if (item) item = ((CFightParamsCollision_nv_148730*)(((::CFightParamsCollision*)(item))))->FUN_000598e0(*FUN_0005a430(actor)->value,&local);
item->vfunc_0();
Manager_148730* manager = actor->FUN_000592a0()->FUN_00059a30()->FUN_000392e0(item);
actor->FUN_00059760(manager);
if (!manager) { item->vfunc_1(); local.FUN_00059300(); return 1; }
unsigned char result = manager->FUN_00231a40(FUN_0005a3f0(actor),item);
item->vfunc_1(); local.FUN_00059300(); return result == 0;
}
