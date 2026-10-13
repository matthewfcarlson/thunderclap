// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009a5d0 @ 0x0009a5d0
struct Vec { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022b980(); void FUN_0022bc20(float,float,float); void FUN_0022c3b0(Vec*,Vec*); };
struct World { unsigned char FUN_00201e00(Vec*,Vec*,int,Vec*,Vec*,int,int); };
struct Globals { char pad[0x24]; World* world; };
extern Globals* DAT_004dd700;
int __stdcall FUN_0009a5d0(float x,float y,float z,float pitch,float yaw,float distance) {
 Vec start; start.x=x; start.y=y; start.z=z;
 Matrix matrix; matrix.FUN_0022b980();
 matrix.FUN_0022bc20(yaw*0.0174533f,pitch*0.0174533f,0.0f);
 Vec direction,forward; forward.x=0;forward.y=0;forward.z=-1.0f;
 matrix.FUN_0022c3b0(&forward,&direction);
 Vec end; end.x=start.x+direction.x*distance; end.y=start.y+direction.y*distance; end.z=start.z+direction.z*distance;
 Vec out1,out2;
 return DAT_004dd700->world->FUN_00201e00(&end,&start,1,&out1,&out2,0,0)==0;
}