// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00312fa0 @ 0x00312fa0
struct Vec3 { float x,y,z; };
struct Bounds {
 char pad[0x2004];
 unsigned char dirty;
 char pad2[3];
 Vec3 inverse;
 Vec3 maximum;
 void FUN_00312fa0(const Vec3* value);
};
void Bounds::FUN_00312fa0(const Vec3* value) {
 dirty = 1;
 if(value->x > maximum.x) maximum.x = value->x;
 if(value->y > maximum.y) maximum.y = value->y;
 if(value->z > maximum.z) maximum.z = value->z;
 float halfY = 0.5f * maximum.y;
 float halfZ = 0.5f * maximum.z;
 float resultZ = 1.0f / halfZ;
 inverse.x = 1.0f / (0.5f * maximum.x);
 inverse.z = resultZ;
 inverse.y = 1.0f / halfY;
}
