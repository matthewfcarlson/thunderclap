// STATUS: equivalent (tools/equiv.py level 3: 19933 inputs, branch coverage 9/10, incomplete)
// hulkfight::ai::PathAction::vfunc_4 @ 0x0011c9a0
// cl-flags: /GS
#include "decls/address.h"
struct Token_11c9a0 {};
struct EventPart { void FUN_001ca2e0(Token_11c9a0*); char storage[0x50]; };
struct Event_11c9a0 { char prefix[12]; EventPart part; };
struct Listener_11c9a0 { void FUN_001cbc20(Event_11c9a0*); };
struct PathPoint_11c9a0 {};
struct Navigation { void FUN_001ae150(PathPoint_11c9a0*); };
struct World { char pad[0x1c]; Navigation* navigation; char pad2[0x10]; Listener_11c9a0* listener; };
struct Request { char pad[0xb4]; int previous; int current; Token_11c9a0* FUN_001034d0(int,int,int); };
struct RequestOwner { Request* FUN_000fdc40(); };
struct ActorState_11c9a0 { char pad[0x1f1]; unsigned char active; void FUN_00060170(); };
struct Actor_11c9a0 { char pad[0x10]; int* identity; char pad2[0x1ca0-0x14]; RequestOwner* owner; char pad3[0x1f58-0x1ca4]; ActorState_11c9a0 state; };
struct Handle2 { Actor_11c9a0* FUN_00059a30(); };
struct Handle_11c9a0 { Handle2* FUN_000592a0(); };
namespace hulkfight { namespace ai {
struct PathAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[0x18]; PathPoint_11c9a0 point; char pad2[0x90-0x1d]; Handle_11c9a0* handle; char pad3[0xec-0x94]; int value;
};
void PathAction::vfunc_4() {
 if (handle) {
 Actor_11c9a0* actor=handle->FUN_000592a0()->FUN_00059a30();
 if (actor) {
 DAT_004dd700->navigation->FUN_001ae150(&point);
 if(actor->state.active) {
 Request* request=actor->owner->FUN_000fdc40();
 if(request) {
 World* manager=DAT_004dd700;
 Token_11c9a0* token=request->FUN_001034d0(*actor->identity,value,1);
 Event_11c9a0 event;
 event.part.FUN_001ca2e0(token);
 manager->listener->FUN_001cbc20(&event);
 request->current=value;
 request->previous=value;
 }
 }
 actor->state.active=0;
 actor->state.FUN_00060170();
 }
 }
}
}}
