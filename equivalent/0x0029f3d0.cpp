// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 14/14)
// FUN_0029f3d0 @ 0x0029f3d0
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
void* __cdecl FUN_00263ea0(unsigned int);
struct Pool_29f3d0 { char data[0x24]; void FUN_00231550(int,int,int); };
struct Helper_29f3d0 { void FUN_00231160(Pool_29f3d0*); };
struct Light { virtual void slot0(); Light* FUN_0029e6c0(void*); };
struct Entry_29f3d0 { char data[12]; Light* light; unsigned int a,b,c; };
struct EntryArray { int count; Entry_29f3d0 entries[1]; };
namespace pure3d { struct LightsChooser { struct CacheManager {
 virtual void slot0();
 Pool_29f3d0 pool;
 Helper_29f3d0* helper;
 Entry_29f3d0* entries;
 Entry_29f3d0** pointers;
 int count;
 int available;
 CacheManager(void* context,int n);
}; }; }
pure3d::LightsChooser::CacheManager::CacheManager(void* context,int n) {
 pool.FUN_00231550(n*2,0x50,0x64);
 count=n; available=n;
 Helper_29f3d0* h=(Helper_29f3d0*)FUN_0008d690(0x18);
 if(h) h->FUN_00231160(&pool);
 helper=h;
 int length=count;
 EntryArray* block=(EntryArray*)FUN_0008d6d0(length*0x1c+4);
 Entry_29f3d0* result=0;
 if(block) {
  block->count=length;
  result=block->entries;
  if(length-1>=0) for(int i=0;i<length;++i) {
   result[i].light=0; result[i].a=0; result[i].b=0; result[i].c=0;
  }
 }
 entries=result;
 pointers=(Entry_29f3d0**)FUN_0008d6d0(count*4);
 for(int i=0;i<count;++i) {
  Light* light=(Light*)FUN_00263ea0(0x48);
  if(light) light=light->FUN_0029e6c0(context);
  entries[i].light=light;
  entries[i].light->slot0();
  pointers[i]=&entries[i];
 }
}
