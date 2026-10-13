// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_002d0950 @ 0x002d0950
struct Item { char pad[8]; unsigned flags; };
struct Object;
// equiv-conv: FUN_002c96e0 eax esi edx
void FUN_002c96e0(Object*, void*, unsigned);
// equiv-conv: FUN_002cb2b0 ecx esi stack
void FUN_002cb2b0(Object*, void*, int);
// equiv-conv: FUN_002c7690 eax esi stack
void FUN_002c7690(Object*, void*, int);
// equiv-conv: FUN_002c7a50 eax esi ecx
void FUN_002c7a50(Object*, void*, unsigned);
struct Object {
 char pad0[0x14]; void* field14; char pad18[0x38]; void* field50; char pad54[4]; Item* item;
 unsigned __int64 FUN_002c8a80(void*, void*);
 unsigned __int64 FUN_002c92f0(void*, void*);
};
// equiv-conv: target ecx stack stack stack edx
void target(Object* self, void* arg1, void* arg2, void* arg3, unsigned incomingEdx) {
 bool enabled = arg3 != 0 && self->field50 != 0;
 unsigned remainingEcx = (!enabled && arg3) ? 0 : (unsigned)self;
 bool special;
 if (enabled) {
  unsigned __int64 result;
  if (self->item) result = self->FUN_002c8a80(arg2,arg3); else result = self->FUN_002c92f0(arg2,arg3);
  incomingEdx = (unsigned)(result >> 32);
  special = self->item != 0 && (self->item->flags & 0xffffffcfU) != 0;
 } else special = self->item != 0;
 if (special) {
  if (self->field14) FUN_002c96e0(self,arg1,(incomingEdx & 0xffffff00U) | (enabled ? 1 : 0));
  else FUN_002cb2b0(self,arg1,enabled ? 1 : 0);
 } else {
  if (self->field14) FUN_002c7690(self,arg1,enabled ? 1 : 0);
  else FUN_002c7a50(self,arg1,(remainingEcx & 0xffffff00U) | (enabled ? 1 : 0));
 }
}
