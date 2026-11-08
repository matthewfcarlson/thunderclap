// STATUS: equivalent (tools/equiv.py level 3: 19905 inputs, branch coverage 10/10)
// core::FileReadRequest::vfunc_1 @ 0x00273f00
#include "compat/ptr.h"
#include "decls/data/records.h"
#include "gen/owners.h"

typedef unsigned int uint;
struct Info_273f00 { char pad[12]; uint limit; };
// the file's drive: slot 12 reads (core::XboxDrive 0x0026f920: the handle, the name, ..., the position, the buffer,
// the count, the count read, the flags)
struct Device_273f00 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
 virtual int read(uint, char*, uint, uint, void*, uint, uint*, uint);
 Info_273f00* FUN_002728d0(); uint FUN_00272880();
};
struct Lock_273f00 { virtual void enter(); virtual void leave(); };
extern "C" hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,uint);
extern bool __fastcall FUN_00277ca0(int* ptr);
// core::FileReadRequest (records.h CoreRequest: the file, then the buffer, the count, the flags; 0x00275230)
struct FileReadRequest_273f00 : CoreRequest {
 void* buffer; uint size; uint flags;
 int vfunc_1();
};
// core::FileReadRequest::vfunc_1 (records.h CoreFile): reads at the file's position (field124) up to its length
// (field128) and the drive's limit, through the cement library view when the file has one (0x00277ca0 /
// 0x00278010), else the drive's slot 12; the drive's error goes to the file's field14
int FileReadRequest_273f00::vfunc_1() {
 uint length=((CoreFile*)file)->field128;
 hulk_uintptr count=size;
 Device_273f00* device=(Device_273f00*)((CoreFile*)file)->provider;
 if(((CoreFile*)file)->field124>=length) count=0;
 hulk_uintptr maximum=FUN_0026fd50(length,device->FUN_002728d0()->limit);
 uint position=((CoreFile*)file)->field124;
 if(position+count>maximum) count=maximum-position;
 int result;
 if(count) {
  uint transferred;
  bool useReader=FUN_00277ca0((int*)&((CoreFile*)file)->view);
  CoreFile* current=(CoreFile*)file;
  if(useReader) result=((owners::Obj_278010*)&current->view)->FUN_00278010((hulk_intptr)device,current->view.words[11],(hulk_intptr)current->filename,current->field120,current->field124,(hulk_intptr)buffer,(int)count,(hulk_intptr)&transferred,flags);
  else result=device->read(current->view.words[11],current->filename,current->field120,current->field124,buffer,(uint)count,&transferred,flags);
  if(result==1) ((CoreFile*)file)->field124+=transferred;
 } else result=1;
 uint status=device->FUN_00272880();
 ((Lock_273f00*)&((CoreFile*)file)->vftableMutable)->enter();
 ((CoreFile*)file)->field14=status;
 ((Lock_273f00*)&((CoreFile*)file)->vftableMutable)->leave();
 return result;
}
