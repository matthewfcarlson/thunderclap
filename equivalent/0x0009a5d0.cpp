// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0009a5d0 @ 0x0009a5d0
#include "gen/owners.h"
struct Vec_9a5d0 { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022b980();   };
struct World { unsigned char FUN_00201e00(Vec_9a5d0*,Vec_9a5d0*,int,Vec_9a5d0*,Vec_9a5d0*,int,int); };
struct Globals_9a5d0 { char pad[0x24]; World* world; };
extern Globals_9a5d0* DAT_004dd700;
extern "C" int __stdcall FUN_0009a5d0(float x,float y,float z,float pitch,float yaw,float distance) {
 Vec_9a5d0 start; start.x=x; start.y=y; start.z=z;
 Matrix matrix; matrix.FUN_0022b980();
 ((owners::Matrix_22bc20 *)&matrix)->FUN_0022bc20(yaw*0.0174532924f, pitch*0.0174532924f, 0.0f);
 Vec_9a5d0 direction,forward; forward.x=0;forward.y=0;forward.z=-1.0f;
 ((owners::M_22c3b0 *)&matrix)->FUN_0022c3b0((float *)(Vec_9a5d0 *)(&forward), (float *)(Vec_9a5d0 *)(&direction));
 Vec_9a5d0 end; end.x=start.x+direction.x*distance; end.y=start.y+direction.y*distance; volatile float ez=direction.z*distance; /* the original rounds this product through its frame */ end.z=start.z+ez;
 Vec_9a5d0 out1,out2;
 return DAT_004dd700->world->FUN_00201e00(&end,&start,1,&out1,&out2,0,0)==0;
}