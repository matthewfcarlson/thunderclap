// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 14/14)
// FUN_0026f570 @ 0x0026f570
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/core.h"
#include "decls/data/records.h"

extern "C" void __cdecl FUN_002705f0();
extern "C" void __cdecl FUN_0026d820(void*);
// core::DriveThread (0x002733c0 constructs it: the device's lock, the heap id; slot 0 adds a reference)
struct DriveThread_26f570 { virtual void retain(); DriveThread_26f570* FUN_002733c0(hulk_uintptr, hulk_uintptr); };
extern "C" void* __cdecl FUN_00266e00(int, int);
extern "C" char* __cdecl _strncpy(char*,const char*,unsigned);
extern "C" char DAT_00445644[];
extern "C" char DAT_0042b52c[];
extern "C" char DAT_0042b524[];
extern "C" char DAT_0042b514[];
// core::Drive's constructor (0x00272d00), named by its address, on core::XboxDrive's layout (records.h CoreXboxDrive)
struct FUN_00272d00 : CoreXboxDrive { FUN_00272d00(); };
namespace core { struct XboxDrive_26f570 : FUN_00272d00 { XboxDrive_26f570(const char*, int); }; }
core::XboxDrive_26f570::XboxDrive_26f570(const char* nameArg, int heap) {
 HULK_SIZE32(CoreDriveThread, 0x94);
 drive.vftable=DAT_0042b52c; drive.vftableObject=DAT_0042b524; drive.vftableMutable=DAT_0042b514;
 openFiles=0; path=0; pathLength=0; FUN_002705f0();
 if(nameArg[0]=='D' && nameArg[1]==':' && nameArg[2]==0) {
  type=0x22; drive.label.text=DAT_00445644;
  if(!(*(DriveThread_26f570**)&DAT_00528408)) {
   FUN_0026d820(((char*)&DAT_005283e8)); DAT_004cdbb0=heap;
   DriveThread_26f570* p=(DriveThread_26f570*)FUN_00266e00(heap,(int)sizeof(CoreDriveThread));
   (*(DriveThread_26f570**)&DAT_00528408)=p ? p->FUN_002733c0((hulk_uintptr)&DAT_005283e8,(hulk_uintptr)(hulk_intptr)heap) : 0;
   lock=((char*)&DAT_005283e8); drive.driveThread=(*(DriveThread_26f570**)&DAT_00528408);
  } else { lock=((char*)&DAT_005283e8); drive.driveThread=(*(DriveThread_26f570**)&DAT_00528408); ((DriveThread_26f570*)drive.driveThread)->retain(); }
 } else {
  type=0x33;
  if(nameArg[0]=='Z' && nameArg[1]==':' && nameArg[2]==0) type=0x3b;
  else if(nameArg[0]=='W' && nameArg[1]==':' && nameArg[2]==0) type=0x20;
  const char* title="Xbox Hard Disk";
  for(int i=0;i<15;++i) drive.label.buffer[i]=title[i];
  if(!(*(DriveThread_26f570**)&DAT_0052840c)) {
   FUN_0026d820(((char*)&DAT_005283cc)); DAT_004cdbb0=heap;
   DriveThread_26f570* p=(DriveThread_26f570*)FUN_00266e00(heap,(int)sizeof(CoreDriveThread));
   (*(DriveThread_26f570**)&DAT_0052840c)=p ? p->FUN_002733c0((hulk_uintptr)&DAT_005283cc,(hulk_uintptr)(hulk_intptr)heap) : 0;
   lock=((char*)&DAT_005283cc); drive.driveThread=(*(DriveThread_26f570**)&DAT_0052840c);
  } else { lock=((char*)&DAT_005283cc); drive.driveThread=(*(DriveThread_26f570**)&DAT_0052840c); ((DriveThread_26f570*)drive.driveThread)->retain(); }
 }
 drive.result=0; _strncpy(name,nameArg,16); name[16]=0;
}
