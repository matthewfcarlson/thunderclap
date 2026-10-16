// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1970 @ 0x002d1970
#include "decls/data/engine/pure3d.h"

struct Vec_2d1970 { float x, y, z; };
struct Src_2d1970 { char pad[0x30]; Vec_2d1970 v30; };
struct Owner_2d1970 {
 char pad0[0x140]; Src_2d1970* src;
 char pad1[0x1a4 - 0x144]; float k1a4;
 char pad2[4]; float k1ac;
};
struct Particle_2d1970 {
 float x, y, z;
 char pad0[0x20 - 0xc];
 float vx, f24, vz;
 char pad1[0x38 - 0x2c];
 float f38; short s3c;
};
void Integrate(float dt, Owner_2d1970* o, Particle_2d1970* p) {
 float t = o->k1ac;
 p->f38 = (float)p->s3c * o->k1a4 * DAT_004d0ed4 * dt + p->f38;
 double x = t * p->vx * dt + p->x;
 p->x = (float)x;
 float y = (p->f24 + p->f38) * t * dt + p->y;
 p->y = y;
 float z = t * p->vz * dt + p->z;
 p->z = z;
 Vec_2d1970* q = &o->src->v30;
 p->x = (float)(x + q->x);
 p->y = y + q->y;
 p->z = z + q->z;
}
