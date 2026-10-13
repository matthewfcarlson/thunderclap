// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002c5f20 @ 0x002c5f20
struct Vec { float x,y,z; void FUN_0022d180(); };
struct Input { char pad[20]; unsigned int value; Vec position; char pad2[52]; Vec direction; void FUN_002c4200(float*,float*,float*); };
extern "C" double __cdecl tan(double);
extern void __cdecl FUN_002c5260(int,Vec*,float,Vec*,unsigned int,unsigned int,unsigned int,unsigned int);
struct Target { unsigned int a,b,c,d; void run(Input*,float); };
void Target::run(Input* input,float distance) {
 b=input->value;
 float angle,unused1,unused2;
 input->FUN_002c4200(&angle,&unused1,&unused2);
 float half=angle*0.5f;
 Vec pos=input->position;
 Vec dir=input->direction;
 dir.FUN_0022d180();
 dir.x*=distance; dir.y*=distance; dir.z*=distance;
 pos.x+=dir.x; pos.y+=dir.y; pos.z+=dir.z;
 FUN_002c5260(0,&input->position,(float)(tan(half)*distance),&pos,a,b,c,d);
}
