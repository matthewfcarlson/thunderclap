// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d66b0 @ 0x001d66b0
struct Vec_1d66b0 { float x,y,z; };
struct Transform_1d66b0 { char rotation[48]; Vec_1d66b0 position; unsigned int tail; void FUN_0022b980(); };
struct Orientation_1d66b0 { bool FUN_0022d2b0(Vec_1d66b0*,float); };
struct Handle_1d66b0 { unsigned int a,b; };
struct Manager_1d66b0 { void FUN_00283a40(Handle_1d66b0*,Transform_1d66b0*,float,float); };
extern Manager_1d66b0* __cdecl FUN_0027f250();
extern void __cdecl FUN_00224db0(Transform_1d66b0*,Vec_1d66b0*,Orientation_1d66b0*);
struct Object { char pad[0x240]; Handle_1d66b0 handle; void target(Vec_1d66b0*,Orientation_1d66b0*); };
void Object::target(Vec_1d66b0* position, Orientation_1d66b0* orientation) {
 if (handle.a || handle.b) {
  Manager_1d66b0* manager=FUN_0027f250();
  Transform_1d66b0 transform;
  transform.FUN_0022b980();
  Vec_1d66b0 up; up.x=0.0f; up.y=1.0f; up.z=0.0f;
  if (!orientation->FUN_0022d2b0(&up,0.00001f)) {
   up.x=0.0f; up.y=1.0f; up.z=0.0f;
   FUN_00224db0(&transform,&up,orientation);
  }
  transform.position=*position;
  manager->FUN_00283a40(&handle,&transform,-1.0f,1.0f);
 }
}