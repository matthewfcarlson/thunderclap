// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_9 @ 0x00276a20
namespace core { struct InstanceDrive; }
struct Item_276a20 { Item_276a20* FUN_00275aa0(core::InstanceDrive*, unsigned int); };
extern void* __cdecl FUN_00273560(unsigned int);
struct Container_276a20 { unsigned int FUN_00272b60(Item_276a20*, unsigned int, unsigned int); };
namespace core {
struct InstanceDrive {
 void* vtable;
 void* secondaryVtable;
 unsigned int field8;
 Container_276a20* container;
 unsigned int field10;
 unsigned int vfunc_9(unsigned int);
};
unsigned int InstanceDrive::vfunc_9(unsigned int arg) {
 Item_276a20* storage = static_cast<Item_276a20*>(FUN_00273560(16));
 Item_276a20* item = 0;
 if (storage) item = storage->FUN_00275aa0(this, arg);
 return container->FUN_00272b60(item, field10, 0);
}
}