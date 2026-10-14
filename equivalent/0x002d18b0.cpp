// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d18b0 @ 0x002d18b0
struct Curves { char pad[0x14]; float* speed; char pad2[8]; float* gravity; };
struct Origin { char pad[0x30]; float x,y,z; };
struct Context { char pad[0x140]; Origin* origin; char pad2[0x60]; float gravityScale; char pad3[4]; float speedScale; char pad4[0xc]; Curves* curves; };
struct Particle { float x,y,z; char pad[0x14]; float vx,vy,vz; char pad2[0xc]; float fall; short weight; };
void __cdecl FUN_002d18b0(float dt,int index,float t,Context* context,Particle* p) {
 float scale=context->speedScale;
 float speed=context->curves->speed[index]+(context->curves->speed[index+1]-context->curves->speed[index])*t;
 float gravity=context->curves->gravity[index]+(context->curves->gravity[index+1]-context->curves->gravity[index])*t;
 p->fall=gravity*p->weight*context->gravityScale*0.00390625f*dt+p->fall;
 float x=speed*p->vx*scale*dt+p->x;
 p->x=x;
 float y=(speed*p->vy+p->fall)*scale*dt+p->y;
 p->y=y;
 double z=(double)speed*p->vz*scale*dt+p->z;
 p->z=(float)z;
 Origin* origin=context->origin;
 p->x=x+origin->x;
 p->y=y+origin->y;
 p->z=(float)(z+origin->z);
}