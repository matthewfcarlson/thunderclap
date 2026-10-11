// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_6 @ 0x00276860
namespace core { struct InstanceDrive; }
struct Entry { void* FUN_00275880(core::InstanceDrive*, unsigned int); };
struct Drive {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual signed char slot6();
 void FUN_00272b60(void*, unsigned int, int);
};
void __cdecl FUN_002697c0(unsigned int, char*, char*, unsigned int*, unsigned int*);
Entry* __cdecl FUN_00273560(unsigned int);
namespace core {
struct InstanceDrive {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned int);
 char bases[8];
 Drive* drive;
 unsigned int context;
};
void InstanceDrive::vfunc_6(unsigned int input) {
 unsigned int first = 0, second = 0;
 char part[20]; char path[260];
 FUN_002697c0(input,path,part,&second,&first);
 unsigned int selected = second;
 if (drive->slot6() < 0) selected = first;
 Entry* entry = FUN_00273560(32);
 void* result = 0;
 if (entry) result = entry->FUN_00275880(this,selected);
 drive->FUN_00272b60(result,context,0);
}
}