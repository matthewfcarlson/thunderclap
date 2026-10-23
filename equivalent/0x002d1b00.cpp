// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// FUN_002d1b00 @ 0x002d1b00
#include "compat/ptr.h"
struct Particle_2d1b00 {
 float x,y,z;
 char pad0[0x20-12];
 float vx,vy,vz;
 char pad1[0x38-0x2c];
 float acceleration;
 short factor;
 void FUN_0022d260(void* transform);
};
struct Emitter_2d1b00 {
 char pad0[0xe0];
 float x,y,z;
 char pad1[0x140-0xec];
 void* transform;
 char pad2[0x1a4-0x144];
 float accelerationScale;
 char pad3[4];
 float speed;
};
void __cdecl FUN_002d1b00(float dt, Emitter_2d1b00* emitter, Particle_2d1b00* particle) {
 float speed = emitter->speed;
 particle->acceleration = (float)particle->factor * emitter->accelerationScale * 0.00390625f * dt + particle->acceleration;
 hulk_freg x = speed * particle->vx * dt + particle->x;
 particle->x = x;
 float y = (particle->vy + particle->acceleration) * speed * dt + particle->y;
 particle->y = y;
 float z = speed * particle->vz * dt + particle->z;
 particle->z = z;
 particle->x = x - emitter->x;
 particle->y = y - emitter->y;
 particle->z = z - emitter->z;
 particle->FUN_0022d260(emitter->transform);
 particle->x = emitter->x + particle->x;
 particle->y = emitter->y + particle->y;
 particle->z = emitter->z + particle->z;
}
