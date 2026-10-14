// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002f0d80 @ 0x002f0d80
struct Vec3_2f0d80 { float x,y,z; };
extern bool __cdecl FUN_002f0080(Vec3_2f0d80*, Vec3_2f0d80*, Vec3_2f0d80*);
extern bool __cdecl FUN_002f08d0(Vec3_2f0d80*, Vec3_2f0d80*, void*, float, float, Vec3_2f0d80*);
bool __cdecl FUN_002f0d80(Vec3_2f0d80 a, Vec3_2f0d80 b, Vec3_2f0d80* center, void* data, float r1, float r2, float r3, Vec3_2f0d80* output) {
 Vec3_2f0d80 local;
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