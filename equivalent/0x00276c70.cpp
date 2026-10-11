// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_20 @ 0x00276c70
void* __cdecl FUN_00273560(unsigned int size);
struct Owner {
 unsigned int FUN_00272b60(void* object, unsigned int value, unsigned int zero);
};
struct Item {
 void* FUN_00274ba0(unsigned int argument, Owner* owner);
};
namespace core {
struct InstanceDrive {
 void* vtable;
 void* refVtable;
 unsigned int field8;
 Owner* owner;
 unsigned int value;
 unsigned int vfunc_20(unsigned int argument);
};
unsigned int InstanceDrive::vfunc_20(unsigned int argument) {
 Item* item = static_cast<Item*>(FUN_00273560(16));
 void* result = 0;
 if (item) result = item->FUN_00274ba0(argument, owner);
 return owner->FUN_00272b60(result, value, 0);
}
}