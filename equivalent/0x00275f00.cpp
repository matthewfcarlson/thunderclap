// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_4 @ 0x00275f00
void* __cdecl FUN_00273560(unsigned int size);
namespace core { struct File; }
struct Operation {
 Operation* FUN_002752e0(core::File* file, unsigned int a, unsigned int b, unsigned int c);
};
struct Manager {
 unsigned int FUN_00272b60(Operation* operation, unsigned int value, unsigned int zero);
};
namespace core {
struct File {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual unsigned int vfunc_4(unsigned int a, unsigned int b, unsigned int c);
 char padding[8];
 Manager* manager;
 unsigned int value;
};
unsigned int File::vfunc_4(unsigned int a, unsigned int b, unsigned int c) {
 Operation* operation = static_cast<Operation*>(FUN_00273560(24));
 if (operation) operation = operation->FUN_002752e0(this, a, b, c);
 return manager->FUN_00272b60(operation, value, 0);
}
}
