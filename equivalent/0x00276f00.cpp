// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// core::InstanceDrive::vfunc_35 @ 0x00276f00
struct Drive {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual signed char slot6();
};
struct Created_276f00 {
 Created_276f00* FUN_002763a0(Drive*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
extern void __cdecl FUN_002697c0(const char*, char*, char*, unsigned*, unsigned*);
extern Created_276f00* __cdecl FUN_00275d50(unsigned);
namespace core {
struct InstanceDrive {
 char padding[12]; Drive* drive;
 Created_276f00* vfunc_35(Created_276f00**, const char*, unsigned, unsigned, unsigned, unsigned, unsigned);
};
Created_276f00* InstanceDrive::vfunc_35(Created_276f00** output, const char* input, unsigned a, unsigned b, unsigned c, unsigned d, unsigned e) {
 unsigned first=0, second=0;
 char small[20]; char large[260];
 FUN_002697c0(input,large,small,&second,&first);
 unsigned selected=second;
 if (drive->slot6()<0) selected=first;
 Created_276f00* result=FUN_00275d50(0x168);
 if(result) result=result->FUN_002763a0(drive,selected,a,b,c,d,e);
 *output=result;
 return result;
}
}