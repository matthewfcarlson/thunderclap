// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_00278500 @ 0x00278500
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/game/global.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

typedef unsigned int uint;
extern "C" void __cdecl FUN_002705f0();
extern "C" uint __stdcall XGetDevices(void*);
extern "C" void* __cdecl FUN_0026fd50(void*,int);
extern "C" void __cdecl FUN_0026d820(void*);
extern "C" void* __cdecl FUN_00266e00(int, int);
// core::DriveThread (0x002733c0 constructs it: the device's lock, the heap id; slot 0 adds a reference)
struct DriveThread_278500 { virtual void action(); void* FUN_002733c0(hulk_uintptr, hulk_uintptr); };
extern "C" char DAT_003ea820;
extern "C" char* __cdecl _strncpy(char*,const char*,unsigned int);
// core::Drive's constructor (0x00272d00), named by its address, on core::XboxSaveDrive's layout (records.h)
struct FUN_00272d00 : CoreXboxSaveDrive { FUN_00272d00(); };
namespace core { struct XboxSaveDrive_278500 : FUN_00272d00 {
 XboxSaveDrive_278500(const char*, int);
}; }
extern "C" char DAT_0042c064[], DAT_0042c058[], DAT_0042c048[], DAT_0042c038[], DAT_0042c028[], DAT_0042c008[], DAT_0042c018[];
core::XboxSaveDrive_278500::XboxSaveDrive_278500(const char* nameArg, int heap) {
 HULK_SIZE32(CoreDriveThread, 0x94);
 *(const void* volatile*)&vftableReader=DAT_0042c008; *(const void* volatile*)&vftableWriter=DAT_0042c018;
 drive.vftable=DAT_0042c064; drive.vftableObject=DAT_0042c058; drive.vftableMutable=DAT_0042c048;
 *(const void* volatile*)&vftableReader=DAT_0042c038; *(const void* volatile*)&vftableWriter=DAT_0042c028;
 openFiles=0; mounted=0; driveLetter=0;
 FUN_002705f0();
 if (!(*(char*)&DAT_0052c280)) {
  uint mask=XGetDevices(&DAT_003ea820);
  (*(unsigned char*)&DAT_0052a228)=(unsigned char)(((mask>>12)&0xf0) | (mask&15));
  (*(unsigned char*)&DAT_0052a229)=0;
  (*(void**)&DAT_0052c270)=FUN_0026fd50(((char*)&DAT_0052a230),32);
 }
 if (!(*(DriveThread_278500**)&DAT_0052c26c)) {
  FUN_0026d820(((char*)&DAT_0052c250));
  DAT_004cdbb0=heap;
  DriveThread_278500* p=(DriveThread_278500*)FUN_00266e00(heap,(int)sizeof(CoreDriveThread));
  if(p) { drive.driveThread=p->FUN_002733c0((hulk_uintptr)&DAT_0052c250,(hulk_uintptr)(hulk_intptr)heap); (*(void**)&DAT_0052c26c)=drive.driveThread; }
  else {drive.driveThread=0;(*(void**)&DAT_0052c26c)=0;}
 } else { drive.driveThread=(*(void**)&DAT_0052c26c); ((DriveThread_278500*)drive.driveThread)->action(); }
 if(nameArg[0]==((char*)&DAT_004004f8)[0] && nameArg[1]==((char*)&DAT_004004f8)[1] && nameArg[2]==((char*)&DAT_004004f8)[2]) { type=0xc3;mounted=1;driveLetter=0x55; drive.label.buffer[0]=0; }
 else type=0xc7;
 _strncpy(name,nameArg,16);
 terminator=0;
 for(int i=0;i<4;i++) files[i]=(hulk_uintptr)-1;
 slots[0].handle=slots[1].handle=slots[2].handle=slots[3].handle=(hulk_uintptr)-1;
}
