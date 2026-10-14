// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1a00 @ 0x002d1a00
struct Particle_2d1a00 { float x,y,z; char pad0[0x14]; float vx,vy,vz; char pad1[0xc]; float drift; short factor; void FUN_0022d260(void*); };
struct Curves_2d1a00 { char pad0[0x14]; float* speed; char pad1[8]; float* drift; };
struct Emitter_2d1a00 { char pad0[0xe0]; float x,y,z; char pad1[0x54]; void* transform; char pad2[0x60]; float driftScale; char pad3[4]; float speedScale; char pad4[0xc]; Curves_2d1a00* curves; };
void __cdecl FUN_002d1a00(float dt, int index, float fraction, Emitter_2d1a00* emitter, Particle_2d1a00* p) {
 double scale=emitter->speedScale;
 double speed=emitter->curves->speed[index]+((double)emitter->curves->speed[index+1]-emitter->curves->speed[index])*fraction;
 double drift=emitter->curves->drift[index]+((double)emitter->curves->drift[index+1]-emitter->curves->drift[index])*fraction;
 p->drift=(float)(drift*p->factor*emitter->driftScale*0.00390625f*dt+p->drift);
 float x=(float)(speed*p->vx*scale*dt+p->x); p->x=x;
 float y=(float)((speed*p->vy+p->drift)*scale*dt+p->y); p->y=y;
 double z=speed*p->vz*scale*dt+p->z; p->z=(float)z;
 p->x=x-emitter->x; p->y=y-emitter->y; p->z=(float)(z-emitter->z);
 p->FUN_0022d260(emitter->transform);
 p->x=emitter->x+p->x; p->y=emitter->y+p->y; p->z=emitter->z+p->z;
}