// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c6250 @ 0x000c6250
struct Vec3_c6250 { float x, y, z; };
extern int __cdecl FUN_000c60f0(Vec3_c6250, Vec3_c6250, Vec3_c6250, Vec3_c6250, unsigned int, unsigned int);
int __cdecl FUN_000c6250(float x1, float y1, float unused1, float x2, float y2, float unused2, unsigned int a7, unsigned int a8)
{
    Vec3_c6250 v1, v2, v3, v4;
    v1.x=x1; v1.y=y1; v1.z=0.0f;
    v2.x=x2; v2.y=y1; v2.z=0.0f;
    v3.x=x1; v3.y=y2; v3.z=0.0f;
    v4.x=x2; v4.y=y2; v4.z=0.0f;
    return FUN_000c60f0(v1,v2,v3,v4,a7,a8);
}