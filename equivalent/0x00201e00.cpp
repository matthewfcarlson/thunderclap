// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 16/16)
// FUN_00201e00 @ 0x00201e00
struct Triple { unsigned x,y,z; };
struct Triangle { char pad[22]; unsigned short flags; };
struct Mesh { char pad[24]; Triangle* triangles; };
struct Object { char pad[68]; Mesh* mesh; };
struct Hit { char pad0[24]; Triple normal; char pad1[20]; Triple point; void FUN_002f8e10(Object**, unsigned short*); };
struct Manager { char pad[432]; Hit* begin; Hit* end; bool FUN_002edb20(Object*, void*, int); };
extern Manager* DAT_00554c14;
bool __stdcall FUN_00201e00(Object* object, void* query, unsigned mask, Triple* point, Triple* normal, Triangle** triangleOut, Object** objectOut) {
 if(triangleOut) *triangleOut=0;
 if(objectOut) *objectOut=0;
 Manager* manager=DAT_00554c14;
 if(!manager->FUN_002edb20(object,query,10)) return false;
 unsigned count=(manager->end-manager->begin);
 if(!count) return false;
 for(unsigned i=0;i<count;++i) {
  unsigned short index;
  manager->begin[i].FUN_002f8e10(&object,&index);
  Triangle* triangle=&object->mesh->triangles[index];
  if(!(mask & (triangle->flags >> 3))) {
   Triple* src=&manager->begin[i].point;
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