// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// core::FileReadRequest::vfunc_1 @ 0x00273f00
#include "compat/ptr.h"
typedef unsigned int uint;
struct Info_273f00 { char pad[12]; uint limit; };
struct Device_273f00 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual int read(uint, char*, uint, uint, void*, uint, uint*, uint);
 Info_273f00* FUN_002728d0(); uint FUN_00272880();
};
struct Lock_273f00 { virtual void enter(); virtual void leave(); };
struct Reader { bool FUN_00277ca0(); int FUN_00278010(Device_273f00*,uint,char*,uint,uint,void*,hulk_uintptr,uint*,uint); char pad[0x30]; };
struct File { uint unknown; Lock_273f00 lock; uint x8; Device_273f00* device; uint x10; uint status; char gap[6]; char name[0x102]; uint handle; uint position; uint length; Reader reader; uint extra; };
extern hulk_uintptr __cdecl FUN_0026fd50(hulk_uintptr,uint);
namespace core {
struct FileReadRequest {
 virtual void vfunc_0(); virtual int vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6();
 uint unknown; File* file; void* buffer; uint size; uint flags;
};
int FileReadRequest::vfunc_1() {
 uint length=file->length;
 hulk_uintptr count=size;
 Device_273f00* device=file->device;
 if(file->position>=length) count=0;
 hulk_uintptr maximum=FUN_0026fd50(length,device->FUN_002728d0()->limit);
 uint position=file->position;
 if(position+count>maximum) count=maximum-position;
 int result;
 if(count) {
  uint transferred;
  bool useReader=file->reader.FUN_00277ca0();
  File* current=file;
  if(useReader) result=current->reader.FUN_00278010(device,current->extra,current->name,current->handle,current->position,buffer,count,&transferred,flags);
  else result=device->read(current->extra,current->name,current->handle,current->position,buffer,count,&transferred,flags);
  if(result==1) file->position+=transferred;
 } else result=1;
 uint status=device->FUN_00272880();
 file->lock.enter();
 file->status=status;
 file->lock.leave();
 return result;
}
}
