// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002c5f20 @ 0x002c5f20
struct Vec_2c5f20 { float x,y,z; void FUN_0022d180(); };
struct Input_2c5f20 { char pad[20]; unsigned int value; Vec_2c5f20 position; char pad2[52]; Vec_2c5f20 direction; void FUN_002c4200(float*,float*,float*); };
extern "C" double __cdecl tan(double);
extern void __cdecl FUN_002c5260(int,Vec_2c5f20*,float,Vec_2c5f20*,unsigned int,unsigned int,unsigned int,unsigned int);
struct Target_2c5f20 { unsigned int a,b,c,d; void run(Input_2c5f20*,float); };
void Target_2c5f20::run(Input_2c5f20* input,float distance) {
 b=input->value;
 float angle,unused1,unused2;
 input->FUN_002c4200(&angle,&unused1,&unused2);
 float half=angle*0.5f;
 Vec_2c5f20 pos=input->position;
 Vec_2c5f20 dir=input->direction;
 dir.FUN_0022d180();
 dir.x*=distance; dir.y*=distance; dir.z*=distance;
 pos.x+=dir.x; pos.y+=dir.y; pos.z+=dir.z;
 FUN_002c5260(0,&input->position,(float)(tan(half)*distance),&pos,a,b,c,d);
}
