// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00278500 @ 0x00278500
typedef unsigned int uint;
struct Base_278500 { void FUN_00272d00(); };
extern "C" void __cdecl FUN_002705f0();
extern "C" uint __stdcall XGetDevices(void*);
extern "C" void* __cdecl FUN_0026fd50(void*,int);
extern "C" void __cdecl FUN_0026d820(void*);
extern "C" void* __cdecl FUN_00266e00(void*,int);
struct Device_278500 { virtual void action(); void* FUN_002733c0(void*,void*); };
extern "C" char DAT_003ea820;
extern "C" char DAT_0052c280;
extern "C" unsigned char DAT_0052a228, DAT_0052a229;
extern "C" char DAT_0052a230, DAT_0052c250;
extern "C" void* DAT_0052c270;
extern "C" Device_278500* DAT_0052c26c;
extern "C" void* DAT_004cdbb0;
extern "C" char DAT_004004f8[];
extern "C" char* __cdecl _strncpy(char*,const char*,unsigned int);
namespace core { struct XboxSaveDrive : Base_278500 {
 void* vt0; void* vt4; char pad8[4]; void* vtc; char pad10[0xa8]; Device_278500* device; volatile void* vtbc; volatile void* vtc0; int mode; void* state; char name[16]; unsigned char term, flag, key; char padDF; int indexes[4]; char padF0[0x204]; int slot0; char pad2F8[0x204]; int slot1; char pad500[0x204]; int slot2; char pad708[0x204]; int slot3;
 XboxSaveDrive(const char*,void*);
}; }
extern "C" char DAT_0042c064,DAT_0042c058,DAT_0042c048,DAT_0042c038,DAT_0042c028,DAT_0042c008,DAT_0042c018;
core::XboxSaveDrive::XboxSaveDrive(const char* nameArg,void* arg) {
 FUN_00272d00();
 vtbc=&DAT_0042c008; vtc0=&DAT_0042c018;
 vt0=&DAT_0042c064; vt4=&DAT_0042c058; vtc=&DAT_0042c048; vtbc=&DAT_0042c038; vtc0=&DAT_0042c028;
 state=0; flag=0; key=0;
 FUN_002705f0();
 if (!DAT_0052c280) {
  uint mask=XGetDevices(&DAT_003ea820);
  DAT_0052a228=(unsigned char)(((mask>>12)&0xf0) | (mask&15));
  DAT_0052a229=0;
  DAT_0052c270=FUN_0026fd50(&DAT_0052a230,32);
 }
 if (!DAT_0052c26c) {
  FUN_0026d820(&DAT_0052c250);
  DAT_004cdbb0=arg;
  Device_278500* p=(Device_278500*)FUN_00266e00(arg,0x94);
  if(p) { device=(Device_278500*)p->FUN_002733c0(&DAT_0052c250,arg); DAT_0052c26c=device; }
  else {device=0;DAT_0052c26c=0;}
 } else { device=DAT_0052c26c; device->action(); }
 if(nameArg[0]==DAT_004004f8[0] && nameArg[1]==DAT_004004f8[1] && nameArg[2]==DAT_004004f8[2]) { mode=0xc3;flag=1;key=0x55; *((char*)this+0x70)=0; }
 else mode=0xc7;
 _strncpy(name,nameArg,16);
 term=0;
 for(int i=0;i<4;i++) indexes[i]=-1;
 slot0=slot1=slot2=slot3=-1;
}
