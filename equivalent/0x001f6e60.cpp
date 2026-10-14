// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001f6e60 @ 0x001f6e60
struct Vec3_1f6e60 { float x,y,z; };
struct Transform_1f6e60 { char data[64]; void FUN_0022ba00(); void FUN_0022be40(const Vec3_1f6e60*); void FUN_0022bec0(const Vec3_1f6e60*,const Vec3_1f6e60*); };
struct Handle_1f6e60 { char data[8]; void FUN_0027b0e0(void*); void FUN_0027af50(); };
struct Service_1f6e60 { int FUN_00283a40(Handle_1f6e60*,Transform_1f6e60*,float,float); };
struct Object { char pad[0x24]; Vec3_1f6e60 position; Vec3_1f6e60 direction; Vec3_1f6e60 rotation; Service_1f6e60* FUN_0027f250(); int target(void*); };
int Object::target(void* arg) {
 Service_1f6e60* service=FUN_0027f250();
 int result=0;
 if(service) {
 Vec3_1f6e60 point;
 point.x=direction.x*0.01f+position.x;
 point.y=direction.y*0.01f+position.y;
 point.z=direction.z*0.01f+position.z;
 Transform_1f6e60 transform;
 transform.FUN_0022ba00();
 transform.FUN_0022be40(&point);
 transform.FUN_0022bec0(&direction,&rotation);
 Handle_1f6e60 handle;
 handle.FUN_0027b0e0(arg);
 result=service->FUN_00283a40(&handle,&transform,-1.0f,1.0f);
 handle.FUN_0027af50();
 }
 return result;
}