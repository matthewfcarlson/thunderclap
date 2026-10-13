// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f0d80 @ 0x002f0d80
struct Vec3 { float x,y,z; };
extern bool __cdecl FUN_002f0080(Vec3*, Vec3*, Vec3*);
extern bool __cdecl FUN_002f08d0(Vec3*, Vec3*, void*, float, float, Vec3*);
bool __cdecl FUN_002f0d80(Vec3 a, Vec3 b, Vec3* center, void* data, float r1, float r2, float r3, Vec3* output) {
 Vec3 local;
 a.x -= center->x; a.y -= center->y; a.z -= center->z;
 b.x -= center->x; b.y -= center->y; b.z -= center->z;
 local.x = local.y = local.z = r1 + r2 + r3;
 if (FUN_002f0080(&a,&b,&local)) return false;
 if (!FUN_002f08d0(&a,&b,data,r1+r3,r2+r3,&local)) return false;
 if (output) {
 float x = local.x + center->x;
 float y = local.y + center->y;
 local.z = local.z + center->z;
 output->z = local.z;
 output->x = x;
 output->y = y;
 }
 return true;
}