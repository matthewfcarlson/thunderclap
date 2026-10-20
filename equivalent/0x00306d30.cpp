// STATUS: equivalent (tools/equiv.py level 3: 403 inputs, branch coverage 12/12)
// physics::CollisionVolume::vfunc_14 @ 0x00306d30
#include "compat/ptr.h"
void* __cdecl FUN_0008d690(hulk_uintptr);
namespace physics { struct CollisionVolume; }
struct VolumeArray {
 physics::CollisionVolume **begin, **end, **limit;
 unsigned int extra;
 void FUN_002ede00(int count);
};
namespace physics {
struct CollisionVolume {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void vfunc_6();
 virtual void vfunc_7();
 virtual void vfunc_8();
 virtual void vfunc_9();
 virtual void vfunc_10();
 virtual void vfunc_11();
 virtual void vfunc_12();
 virtual void vfunc_13();
 virtual void vfunc_14(CollisionVolume* dest);
 unsigned int field4, field8, fieldC, field10;
 VolumeArray* children;
 unsigned char flag;
 char pad19[3];
 unsigned int field1C, field20, field24, field28, field2C, field30, field34;
 CollisionVolume* FUN_00306c60();
};
void CollisionVolume::vfunc_14(CollisionVolume* dest) {
 dest->field28 = field28;
 dest->field2C = field2C;
 dest->field30 = field30;
 dest->field34 = field34;
 dest->flag = flag;
 dest->field8 = field8;
 dest->fieldC = fieldC;
 dest->field1C = field1C;
 dest->field20 = field20;
 dest->field24 = field24;
 if (children) {
  VolumeArray* a = (VolumeArray*)FUN_0008d690(16);
  if (a) { a->begin=0; a->end=0; a->limit=0; }
  dest->children=a;
  dest->children->FUN_002ede00((int)((char*)children->end-(char*)children->begin)>>2);
  unsigned int i=0;
  while (i < (unsigned int)((int)((char*)children->end-(char*)children->begin)>>2)) {
   CollisionVolume* child=children->begin[i]->FUN_00306c60();
   child->vfunc_0();
   VolumeArray* out=dest->children;
   if ((hulk_uintptr)out->end < (hulk_uintptr)out->limit) {
    CollisionVolume** place=out->end;
    out->end=place+1;
    if(place) *place=child;
   }
   ++i;
  }
 }
}
}
