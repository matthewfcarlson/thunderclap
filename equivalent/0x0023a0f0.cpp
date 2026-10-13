// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// fight::QueuedNodeAction::vfunc_3 @ 0x0023a0f0
typedef unsigned int uint;
extern "C" uint __cdecl FUN_00238190(uint);
extern "C" uint __cdecl FUN_00266da0(uint);
struct Result { char pad[12]; uint flags; float first, second; };
struct Owner;
struct Node {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual float slot6(); virtual float slot7(); virtual uint slot8(uint,uint); virtual void slot9(); virtual Result* slot10(Owner*,uint,uint);
 Node* next; uint flags;
};
struct Owner { char pad[40]; Node* head; };
struct Queue {
 void FUN_00232290(Result*);
 void FUN_00232030(Owner*);
 void FUN_002322f0(uint,uint);
 bool FUN_00231ee0();
 char pad[40];
};
namespace fight {
struct QueuedNodeAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(uint,uint); virtual void vfunc_4(); virtual void vfunc_5();
 char pad0[8]; uint flags; char pad1[12]; Owner* owner; uint query; uint expected; uint context; Queue queue; uint value; unsigned char active;
};
bool QueuedNodeAction::vfunc_3(uint arg, uint arg2) {
 uint saved = FUN_00266da0(FUN_00238190(3));
 value = arg;
 if (!owner) { FUN_00266da0(saved); return false; }
 uint status = 1;
 for (Node* node = owner->head; node; node = node->next) {
 uint f = node->flags;
 uint match = node->slot8(query,context);
 if (expected == match) {
 Result* r = node->slot10(owner,expected,context);
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