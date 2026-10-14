// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1b00 @ 0x002d1b00
struct Particle {
 float x,y,z;
 char pad0[0x20-12];
 float vx,vy,vz;
 char pad1[0x38-0x2c];
 float acceleration;
 short factor;
 void FUN_0022d260(void* transform);
};
struct Emitter {
 char pad0[0xe0];
 float x,y,z;
 char pad1[0x140-0xec];
 void* transform;
 char pad2[0x1a4-0x144];
 float accelerationScale;
 char pad3[4];
 float speed;
};
void __cdecl FUN_002d1b00(float dt, Emitter* emitter, Particle* particle) {
 float speed = emitter->speed;
 particle->acceleration = (float)particle->factor * emitter->accelerationScale * 0.00390625f * dt + particle->acceleration;
 float x = speed * particle->vx * dt + particle->x;
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
