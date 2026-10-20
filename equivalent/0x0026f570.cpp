// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 14/14)
// FUN_0026f570 @ 0x0026f570
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/platform/xbox/core.h"

extern "C" void __cdecl FUN_002705f0();
extern "C" void __cdecl FUN_0026d820(void*);
struct Resource_26f570 { virtual void retain(); Resource_26f570* FUN_002733c0(void*,const char*); };
extern "C" Resource_26f570* __cdecl FUN_00266e00(const char*,hulk_intptr);
extern "C" char* __cdecl _strncpy(char*,const char*,unsigned);
extern char DAT_00445644[];
struct DAT_0042b52c { virtual void slot0(); };
struct DAT_0042b524 { virtual void slot4(); int unknown8; };
struct DAT_0042b514 { virtual void slotC(); };
struct FUN_00272d00 : DAT_0042b52c, DAT_0042b524, DAT_0042b514 {
 FUN_00272d00();
 char padding10[0x50]; int state60; char padding64[12];
 union { const char* labelPointer; char label[16]; };
 char padding80[0x38]; Resource_26f570* resource; int type, stateC0;
 char path[17]; char paddingD5[0x103]; int state1D8, state1DC; void* resourceData;
};
namespace core { struct XboxDrive : FUN_00272d00 {
 virtual void slot0(); virtual void slot4(); virtual void slotC(); XboxDrive(const char*,const char*);
}; }
core::XboxDrive::XboxDrive(const char* name,const char* source) {
 stateC0=0; state1D8=0; state1DC=0; FUN_002705f0();
 if(name[0]=='D' && name[1]==':' && name[2]==0) {
  type=0x22; labelPointer= ((char*)0x445644);
  if(!(*(Resource_26f570**)&DAT_00528408)) {
   FUN_0026d820(((char*)&DAT_005283e8)); (*(const char**)&DAT_004cdbb0)=source;
   Resource_26f570* p=FUN_00266e00(source,0x94);
   (*(Resource_26f570**)&DAT_00528408)=p ? p->FUN_002733c0(((char*)&DAT_005283e8),source) : 0;
   resourceData=((char*)&DAT_005283e8); resource=(*(Resource_26f570**)&DAT_00528408);
  } else { resourceData=((char*)&DAT_005283e8); resource=(*(Resource_26f570**)&DAT_00528408); resource->retain(); }
 } else {
  type=0x33;
  if(name[0]=='Z' && name[1]==':' && name[2]==0) type=0x3b;
  else if(name[0]=='W' && name[1]==':' && name[2]==0) type=0x20;
  const char* title="Xbox Hard Disk";
  for(int i=0;i<15;++i) label[i]=title[i];
  if(!(*(Resource_26f570**)&DAT_0052840c)) {
   FUN_0026d820(((char*)&DAT_005283cc)); (*(const char**)&DAT_004cdbb0)=source;
   Resource_26f570* p=FUN_00266e00(source,0x94);
   (*(Resource_26f570**)&DAT_0052840c)=p ? p->FUN_002733c0(((char*)&DAT_005283cc),source) : 0;
   resourceData=((char*)&DAT_005283cc); resource=(*(Resource_26f570**)&DAT_0052840c);
  } else { resourceData=((char*)&DAT_005283cc); resource=(*(Resource_26f570**)&DAT_0052840c); resource->retain(); }
 }
 state60=0; _strncpy(path,name,16); path[16]=0;
}
