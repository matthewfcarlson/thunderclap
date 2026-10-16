// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 28/28)
// FUN_002059d0 @ 0x002059d0
#include "decls/data/game/global.h"

struct Resource_2059d0 { virtual void unused(); virtual void release(); void FUN_002665a0(); };
struct Handle_2059d0 { void FUN_00263e90(); };
extern void __cdecl FUN_00267110(int);
extern void __cdecl FUN_00267090(void*);
struct Entry_2059d0 {
 unsigned char active, flag;
 char pad0[32];
 short id;
 char pad1[4];
 void* allocation;
 Resource_2059d0* resource;
 char pad2[4];
 Handle_2059d0* handle;
 char pad3[4];
};
struct Object {
 char pad[0x44];
 Resource_2059d0* mainResource;
 char pad1[4];
 Entry_2059d0 entries[20];
 union { Entry_2059d0 extra[2]; struct {char padding[116]; int values[2];} tail; };
 void cleanup();
};
void Object::cleanup() {
 if ((*(unsigned char*)&DAT_004c91d8)) {
  for (int i=0;i<20;++i) {
   Entry_2059d0& e=entries[i];
   if(e.handle) {e.handle->FUN_00263e90(); e.handle=0;}
   if(e.resource) FUN_00267110(e.id);
   if(e.resource) {e.resource->release(); e.resource=0;}
   if(e.allocation) {FUN_00267090(e.allocation); e.allocation=0;}
   e.active=0; e.flag=0; e.id=0;
  }
 }
 if(mainResource) {
  mainResource->FUN_002665a0();
  if(mainResource) {mainResource->release();mainResource=0;}
 }
 for(int j=0;j<2;++j) {
  if((*(unsigned char*)((char*)&DAT_004c91d8 + 1))) {
   Entry_2059d0& e=extra[j];
   if(e.handle) {e.handle->FUN_00263e90();e.handle=0;}
   if(e.resource) FUN_00267110(e.id);
   if(e.resource) {e.resource->release();e.resource=0;}
   if(e.allocation) {FUN_00267090(e.allocation);e.allocation=0;}
   e.active=0;e.flag=0;e.id=0;
  }
  tail.values[j]=0;
 }
}
