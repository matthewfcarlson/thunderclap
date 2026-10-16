// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 16/16)
// FUN_00201e00 @ 0x00201e00
#include "decls/data/game/global.h"

struct Triple_201e00 { unsigned x,y,z; };
struct Triangle_201e00 { char pad[22]; unsigned short flags; };
struct Mesh_201e00 { char pad[24]; Triangle_201e00* triangles; };
struct Object { char pad[68]; Mesh_201e00* mesh; };
struct Hit_201e00 { char pad0[24]; Triple_201e00 normal; char pad1[20]; Triple_201e00 point; void FUN_002f8e10(Object**, unsigned short*); };
struct Manager_201e00 { char pad[432]; Hit_201e00* begin; Hit_201e00* end; bool FUN_002edb20(Object*, void*, int); };
bool __stdcall FUN_00201e00(Object* object, void* query, unsigned mask, Triple_201e00* point, Triple_201e00* normal, Triangle_201e00** triangleOut, Object** objectOut) {
 if(triangleOut) *triangleOut=0;
 if(objectOut) *objectOut=0;
 Manager_201e00* manager=(*(Manager_201e00**)&DAT_00554c14);
 if(!manager->FUN_002edb20(object,query,10)) return false;
 unsigned count=(manager->end-manager->begin);
 if(!count) return false;
 for(unsigned i=0;i<count;++i) {
  unsigned short index;
  manager->begin[i].FUN_002f8e10(&object,&index);
  Triangle_201e00* triangle=&object->mesh->triangles[index];
  if(!(mask & (triangle->flags >> 3))) {
   Triple_201e00* src=&manager->begin[i].point;
   point->x=src->x; point->y=src->y; point->z=src->z;
   src=&manager->begin[i].normal;
   normal->x=src->x; normal->y=src->y; normal->z=src->z;
   if(triangleOut) *triangleOut=triangle;
   if(objectOut) *objectOut=object;
   return true;
  }
 }
 return false;
}