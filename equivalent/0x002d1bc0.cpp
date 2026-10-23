// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// FUN_002d1bc0 @ 0x002d1bc0
#include "compat/ptr.h"
struct Curves_2d1bc0 { char pad[0x14]; float *speed; char pad18[8]; float *acceleration; };
struct Particle_2d1bc0 { float x,y,z; char pad0c[0x14]; float vx,vy,vz; char pad2c[0xc]; float acceleration; short weight; void FUN_0022d210(void*); };
struct Emitter_2d1bc0 { char pad0[0xe0]; float x,y,z; char padEC[0x54]; void *transform; char pad144[0x60]; float accelerationScale; char pad1a8[4]; float speedScale; char pad1b0[0xc]; Curves_2d1bc0 *curves; };
void __cdecl FUN_002d1bc0(float dt, int index, float blend, Emitter_2d1bc0 *emitter, Particle_2d1bc0 *p) {
 hulk_freg speed = emitter->curves->speed[index] + (emitter->curves->speed[index+1]-emitter->curves->speed[index])*blend;
 p->acceleration += (emitter->curves->acceleration[index] + (emitter->curves->acceleration[index+1]-emitter->curves->acceleration[index])*blend) * p->weight * emitter->accelerationScale * 0.00390625f * dt;
 float x = speed * p->vx * emitter->speedScale * dt + p->x;
 p->x = x;
 float y = (speed * p->vy + p->acceleration) * emitter->speedScale * dt + p->y;
 p->y = y;
 double z = speed * p->vz * emitter->speedScale * dt + p->z;
 p->z = (float)z;
 p->x = x - emitter->x;
 p->y = y - emitter->y;
 p->z = (float)(z - emitter->z);
 p->FUN_0022d210(emitter->transform);
 p->x += emitter->x;
 p->y += emitter->y;
 p->z += emitter->z;
}
