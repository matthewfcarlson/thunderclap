// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::InstanceDrive::vfunc_4 @ 0x002767d0
namespace core { struct InstanceDrive; }
struct Wrapper_2767d0 {
 Wrapper_2767d0* FUN_00275750(core::InstanceDrive*, unsigned int);
};
extern Wrapper_2767d0* __cdecl FUN_00273560(unsigned int);
struct Registry_2767d0 {
 unsigned int FUN_00272b60(Wrapper_2767d0*, unsigned int, unsigned int);
};
namespace core {
struct InstanceDrive {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual unsigned int vfunc_4(unsigned int);
 char pad[8];
 Registry_2767d0* registry;
 unsigned int key;
};
unsigned int InstanceDrive::vfunc_4(unsigned int argument) {
 Wrapper_2767d0* memory = FUN_00273560(16);
 Wrapper_2767d0* object = 0;
 if (memory) object = memory->FUN_00275750(this, argument);
 return registry->FUN_00272b60(object, key, 0);
}
}