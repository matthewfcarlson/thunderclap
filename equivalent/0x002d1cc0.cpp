// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1cc0 @ 0x002d1cc0
struct Particle_2d1cc0 {
 float x,y,z;
 char pad0[0x14];
 float vx,vy,vz;
 char pad1[0xc];
 float acceleration;
 short factor;
 void FUN_0022d210(void* transform);
};
struct Emitter_2d1cc0 {
 char pad0[0xe0];
 float x,y,z;
 char pad1[0x54];
 void* transform;
 char pad2[0x60];
 float accelerationScale;
 char pad3[4];
 float speed;
};
void __cdecl FUN_002d1cc0(float dt, Emitter_2d1cc0* emitter, Particle_2d1cc0* particle) {
 float speed = emitter->speed;
 particle->acceleration = particle->acceleration + particle->factor * emitter->accelerationScale * 0.00390625f * dt;
 particle->x = particle->x + speed * particle->vx * dt;
 float y = particle->y + (particle->vy + particle->acceleration) * speed * dt;
 particle->y = y;
 float z = particle->z + speed * particle->vz * dt;
 particle->z = z;
 particle->x = particle->x - emitter->x;
 particle->y = y - emitter->y;
 particle->z = z - emitter->z;
 particle->FUN_0022d210(emitter->transform);
 particle->x = emitter->x + particle->x;
 particle->y = emitter->y + particle->y;
 particle->z = emitter->z + particle->z;
}
