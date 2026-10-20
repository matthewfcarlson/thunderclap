// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 20/20)
// FUN_002d0950 @ 0x002d0950
// FUN_002d0950 @ 0x002d0950
struct Item_2d0950 { char pad[8]; unsigned flags; };
struct Object;
// equiv-conv: FUN_002c96e0 eax edx esi
void FUN_002c96e0(Object*, unsigned char, void*);
// equiv-conv: FUN_002cb2b0 ecx stack esi
void FUN_002cb2b0(Object*, int, void*);
// equiv-conv: FUN_002c7690 eax esi stack
void FUN_002c7690(Object*, void*, int);
// equiv-conv: FUN_002c7a50 ecx eax esi
void FUN_002c7a50(unsigned char, Object*, void*);
struct Object {
 char pad0[0x14]; void* field14; char pad18[0x38]; void* field50; char pad54[4]; Item_2d0950* item;
 unsigned __int64 FUN_002c8a80(void*, void*);
 unsigned __int64 FUN_002c92f0(void*, void*);
 void target(void* arg1, void* arg2, void* arg3);
};
void Object::target(void* arg1, void* arg2, void* arg3) {
 Object* self = this;
 bool enabled = arg3 != 0 && self->field50 != 0;
 bool special;
 if (enabled) {
  unsigned __int64 result;
  if (self->item) result = self->FUN_002c8a80(arg2,arg3); else result = self->FUN_002c92f0(arg2,arg3);
  special = self->item != 0 && (self->item->flags & 0xffffffcfU) != 0;
 } else special = self->item != 0;
 if (special) {
  if (self->field14) FUN_002c96e0(self, enabled ? 1 : 0, arg1);
  else FUN_002cb2b0(self, enabled ? 1 : 0, arg1);
 } else {
  if (self->field14) FUN_002c7690(self,arg1,enabled ? 1 : 0);
  else FUN_002c7a50(enabled ? 1 : 0, self, arg1);
 }
}
