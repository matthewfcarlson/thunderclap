// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001d66b0 @ 0x001d66b0
struct Vec { float x,y,z; };
struct Transform { char rotation[48]; Vec position; unsigned int tail; void FUN_0022b980(); };
struct Orientation { bool FUN_0022d2b0(Vec*,float); };
struct Handle { unsigned int a,b; };
struct Manager { void FUN_00283a40(Handle*,Transform*,float,float); };
extern Manager* __cdecl FUN_0027f250();
extern void __cdecl FUN_00224db0(Transform*,Vec*,Orientation*);
struct Object { char pad[0x240]; Handle handle; void target(Vec*,Orientation*); };
void Object::target(Vec* position, Orientation* orientation) {
 if (handle.a || handle.b) {
  Manager* manager=FUN_0027f250();
  Transform transform;
  transform.FUN_0022b980();
  Vec up; up.x=0.0f; up.y=1.0f; up.z=0.0f;
  if (!orientation->FUN_0022d2b0(&up,0.00001f)) {
   up.x=0.0f; up.y=1.0f; up.z=0.0f;
   FUN_00224db0(&transform,&up,orientation);
  }
  transform.position=*position;
  manager->FUN_00283a40(&handle,&transform,-1.0f,1.0f);
 }
}