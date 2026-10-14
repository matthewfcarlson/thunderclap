// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00029a90 @ 0x00029a90
extern "C" double __cdecl sqrt(double);
struct Vec3_29a90 { float x,y,z; };
struct Owner_29a90 { char pad[0x328]; int identifier; void FUN_000350c0(Vec3_29a90* out); };
extern void __cdecl FUN_00096a90(void* object, Vec3_29a90* out);
struct Object {
 char pad0[0x124]; Owner_29a90* owner;
 char pad1[0x330-0x128]; Vec3_29a90 center; float radius;
 char pad2[4]; void* object; int identifier; float alternateRadius;
 bool FUN_00029a90();
};
bool Object::FUN_00029a90() {
 if (!owner) return true;
 Vec3_29a90 position = {0.0f,0.0f,0.0f};
 float r;
 if(object && identifier == owner->identifier) {
  FUN_00096a90(object, &position);
  r=alternateRadius;
 } else {
  owner->FUN_000350c0(&position);
  r=radius;
 }
 double dx = (double)position.x-center.x;
 double dy = (double)position.y-center.y;
 double dz = (double)position.z-center.z;
 return sqrt(dz*dz+dx*dx+dy*dy)<=r;
}