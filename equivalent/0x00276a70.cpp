// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_10 @ 0x00276a70
struct ParsedData { char bytes[260]; };
void __cdecl FUN_002697c0(const char*, ParsedData*, unsigned int*, unsigned int*, unsigned int*);
void* __cdecl FUN_00273560(unsigned int);
namespace core { struct InstanceDrive; }
struct Created_276a70 { Created_276a70* FUN_00275bd0(core::InstanceDrive*, unsigned int); };
struct Backend_276a70 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual signed char slot6();
 unsigned int FUN_00272b60(Created_276a70*, unsigned int, int);
};
namespace core {
struct InstanceDrive {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual unsigned int vfunc_10(const char*);
 char padding[8]; Backend_276a70* backend; unsigned int context;
};
unsigned int InstanceDrive::vfunc_10(const char* name) {
 unsigned int alternate = 0, primary = 0, other;
 ParsedData parsed;
 FUN_002697c0(name, &parsed, &other, &primary, &alternate);
 unsigned int selected = primary;
 if (backend->slot6() < 0) selected = alternate;
 Created_276a70* memory = (Created_276a70*)FUN_00273560(0x110);
 Created_276a70* object = memory ? memory->FUN_00275bd0(this, selected) : 0;
 return backend->FUN_00272b60(object, context, 0);
}
}