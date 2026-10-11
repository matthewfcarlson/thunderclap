// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// core::File::vfunc_7 @ 0x00275ff0
namespace core { struct File; }
struct Allocation { void* FUN_002754d0(core::File*, unsigned int); };
Allocation* __cdecl FUN_00273560(unsigned int);
struct Owner { unsigned int FUN_00272b60(void*, unsigned int, unsigned int); };
namespace core {
struct File {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual unsigned int vfunc_7(unsigned int);
 char padding[8];
 Owner* owner;
 unsigned int value;
};
unsigned int File::vfunc_7(unsigned int argument) {
 Allocation* allocation = FUN_00273560(16);
 void* result = 0;
 if (allocation) result = allocation->FUN_002754d0(this, argument);
 return owner->FUN_00272b60(result, value, 0);
}
}