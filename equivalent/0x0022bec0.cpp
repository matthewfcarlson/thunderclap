// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022bec0 @ 0x0022bec0
#include "decls/data/engine/unknown.h"

struct Vec_22bec0 { float x,y,z,w; void FUN_0022d180(); };
struct Basis_22bec0 { Vec_22bec0 a,b,c; void FUN_0022bec0(Vec_22bec0* u, Vec_22bec0* v); };
void Basis_22bec0::FUN_0022bec0(Vec_22bec0* u, Vec_22bec0* v) {
 float cy=u->x*v->z-u->z*v->x;
 float cz=u->y*v->x-u->x*v->y;
 float cx=u->z*v->y-u->y*v->z;
 a.x=cx; a.y=cy; a.z=cz;
 if (a.x*a.x+a.y*a.y+a.z*a.z <= (*(float*)&DAT_00427598)) {
 float y=u->y, z=u->z;
 a.x=0.0f; a.y=-z; a.z=y;
 if (a.y*a.y+a.z*a.z+a.x*a.x <= (*(float*)&DAT_00427598)) {
 float x=u->x; float z2=u->z;
 a.x=z2; a.z=-x; a.y=0.0f;
 }
 }
 cy=u->z*a.x-a.z*u->x;
 cz=a.y*u->x-u->y*a.x;
 cx=a.z*u->y-a.y*u->z;
 b.x=cx; b.y=cy; b.z=cz;
 c.x=u->x; c.y=u->y; c.z=u->z;
 a.FUN_0022d180(); b.FUN_0022d180(); c.FUN_0022d180();
}