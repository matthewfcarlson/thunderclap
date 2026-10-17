// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 0/0)
// FUN_00224d70 @ 0x00224d70
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Vec3 { float x,y,z; };
extern "C" void __cdecl FUN_00224d70(float angle, Vec3 *v)
{
    float x = v->x;
    float z = v->z;
    double s = sin(angle);
    double c = cos(angle);
    v->x = (float)(x*c + z*s);
    v->z = (float)(z*c - x*s);
}