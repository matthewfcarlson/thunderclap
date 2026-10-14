// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_20 @ 0x00276c70
void* __cdecl FUN_00273560(unsigned int size);
struct Owner_276c70 {
 unsigned int FUN_00272b60(void* object, unsigned int value, unsigned int zero);
};
struct Item_276c70 {
 void* FUN_00274ba0(unsigned int argument, Owner_276c70* owner);
};
namespace core {
struct InstanceDrive {
 void* vtable;
 void* refVtable;
 unsigned int field8;
 Owner_276c70* owner;
 unsigned int value;
 unsigned int vfunc_20(unsigned int argument);
};
unsigned int InstanceDrive::vfunc_20(unsigned int argument) {
 Item_276c70* item = static_cast<Item_276c70*>(FUN_00273560(16));
 void* result = 0;
 if (item) result = item->FUN_00274ba0(argument, owner);
 return owner->FUN_00272b60(result, value, 0);
}
}