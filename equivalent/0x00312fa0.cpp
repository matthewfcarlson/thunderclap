// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 6/6)
// FUN_00312fa0 @ 0x00312fa0
struct Vec3_312fa0 { float x,y,z; };
struct Bounds_312fa0 {
 char pad[0x2004];
 unsigned char dirty;
 char pad2[3];
 Vec3_312fa0 inverse;
 Vec3_312fa0 maximum;
 void FUN_00312fa0(const Vec3_312fa0* value);
};
void Bounds_312fa0::FUN_00312fa0(const Vec3_312fa0* value) {
 dirty = 1;
 if(value->x > maximum.x) maximum.x = value->x;
 if(value->y > maximum.y) maximum.y = value->y;
 if(value->z > maximum.z) maximum.z = value->z;
 volatile float halfY = 0.5f * maximum.y; // the original stores these two halves (rounded) in its frame
 volatile float halfZ = 0.5f * maximum.z;
 float resultZ = 1.0f / halfZ;
 inverse.x = 1.0f / (0.5f * maximum.x);
 inverse.z = resultZ;
 inverse.y = 1.0f / halfY;
}
