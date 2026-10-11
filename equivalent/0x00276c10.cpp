// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_19 @ 0x00276c10
void* __cdecl FUN_00273560(unsigned size);
namespace core { struct InstanceDrive; }
void* __stdcall FUN_0026dbb0(core::InstanceDrive*, unsigned, unsigned);
struct Item { void* FUN_00274d80(void*); };
struct Owner { unsigned FUN_00272b60(void*, unsigned, unsigned); };
namespace core {
struct InstanceDrive {
 void* vtable;
 char padding[8];
 Owner* owner;
 unsigned context;
 unsigned vfunc_19(unsigned a, unsigned b);
};
unsigned InstanceDrive::vfunc_19(unsigned a, unsigned b) {
 Item* item = (Item*)FUN_00273560(0x18);
 void* result = 0;
 if (item) result = item->FUN_00274d80(FUN_0026dbb0(this, a, b));
 return owner->FUN_00272b60(result, context, 0);
}
}
