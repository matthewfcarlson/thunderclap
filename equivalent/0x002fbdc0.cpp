// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_002fbdc0 @ 0x002fbdc0
#include "compat/ptr.h"
struct Vec_2fbdc0 { float x,y,z; };
struct Shape_2fbdc0 {
 char pad[0x38]; int aligned; char pad2[0xc]; float extentX,extentY,extentZ; Vec_2fbdc0 axisX,axisY,axisZ;
 hulk_freg FUN_002fbdc0(const Vec_2fbdc0* v, int excluded);
};
hulk_freg Shape_2fbdc0::FUN_002fbdc0(const Vec_2fbdc0* v, int excluded) {
 union Bits { float f; unsigned int u; } b;
 double sum=0.0f;
 if (!aligned) {
  if(excluded!=0) { b.f=(axisX.z*v->z+axisX.y*v->y)+axisX.x*v->x; b.u &= 0x7fffffff; sum=(double)b.f*extentX; }
  if(excluded!=1) { b.f=(axisY.z*v->z+axisY.y*v->y)+axisY.x*v->x; b.u &= 0x7fffffff; sum+=(double)b.f*extentY; }
  if(excluded!=2) { b.f=(axisZ.z*v->z+axisZ.y*v->y)+axisZ.x*v->x; b.u &= 0x7fffffff; sum+=(double)b.f*extentZ; }
 } else {
  if(excluded!=0) { b.f=v->x; b.u &= 0x7fffffff; sum=(double)b.f*extentX; }
  if(excluded!=1) { b.f=v->y; b.u &= 0x7fffffff; sum+=(double)b.f*extentY; }
  if(excluded!=2) { b.f=v->z; b.u &= 0x7fffffff; sum+=(double)b.f*extentZ; }
 }
 return (float)sum;
}