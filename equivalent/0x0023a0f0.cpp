// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// fight::QueuedNodeAction::vfunc_3 @ 0x0023a0f0
#include "compat/ptr.h"
typedef unsigned int uint_23a0f0;
extern "C" uint_23a0f0 __cdecl FUN_00238190(uint_23a0f0);
extern "C" uint_23a0f0 __cdecl FUN_00266da0(hulk_uintptr);
struct Result_23a0f0 { char pad[12]; uint_23a0f0 flags; float first, second; };
struct Owner_23a0f0;
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual float slot6(); virtual float slot7(); virtual uint_23a0f0 slot8(uint_23a0f0,uint_23a0f0); virtual void slot9(); virtual Result_23a0f0* slot10(Owner_23a0f0*,uint_23a0f0,uint_23a0f0);
 Node* next; uint_23a0f0 flags;
};
struct Owner_23a0f0 { char pad[40]; Node* head; };
struct Queue_23a0f0 {
 void FUN_00232290(Result_23a0f0*);
 void FUN_00232030(Owner_23a0f0*);
 void FUN_002322f0(uint_23a0f0,uint_23a0f0);
 bool FUN_00231ee0();
 char pad[40];
};
namespace fight {
struct QueuedNodeAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(uint_23a0f0,uint_23a0f0); virtual void vfunc_4(); virtual void vfunc_5();
 char pad0[8]; uint_23a0f0 flags; char pad1[12]; Owner_23a0f0* owner; uint_23a0f0 query; uint_23a0f0 expected; uint_23a0f0 context; Queue_23a0f0 queue; uint_23a0f0 value; unsigned char active;
};
bool QueuedNodeAction::vfunc_3(uint_23a0f0 arg, uint_23a0f0 arg2) {
 uint_23a0f0 saved = FUN_00266da0(FUN_00238190(3));
 value = arg;
 if (!owner) { FUN_00266da0(saved); return false; }
 uint_23a0f0 status = 1;
 for (Node* node = owner->head; node; node = node->next) {
 uint_23a0f0 f = node->flags;
 uint_23a0f0 match = node->slot8(query,context);
 if (expected == match) {
 Result_23a0f0* r = node->slot10(owner,expected,context);
 if (r) {
 r->first = node->slot6();
 r->second = node->slot7();
 r->flags = (r->flags & ~3u) | (f & 3u);
 queue.FUN_00232290(r);
 }
 if (!f) status = 0;
 }
 }
 queue.FUN_00232030(owner);
 flags = (flags & ~3u) | status;
 queue.FUN_002322f0(value,arg2);
 active = 1;
 bool result = queue.FUN_00231ee0();
 FUN_00266da0(saved);
 return result;
}
}