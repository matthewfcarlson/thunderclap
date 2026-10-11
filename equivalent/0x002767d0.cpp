// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_4 @ 0x002767d0
namespace core { struct InstanceDrive; }
struct Wrapper {
 Wrapper* FUN_00275750(core::InstanceDrive*, unsigned int);
};
extern Wrapper* __cdecl FUN_00273560(unsigned int);
struct Registry {
 unsigned int FUN_00272b60(Wrapper*, unsigned int, unsigned int);
};
namespace core {
struct InstanceDrive {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual unsigned int vfunc_4(unsigned int);
 char pad[8];
 Registry* registry;
 unsigned int key;
};
unsigned int InstanceDrive::vfunc_4(unsigned int argument) {
 Wrapper* memory = FUN_00273560(16);
 Wrapper* object = 0;
 if (memory) object = memory->FUN_00275750(this, argument);
 return registry->FUN_00272b60(object, key, 0);
}
}