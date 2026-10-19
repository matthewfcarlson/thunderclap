// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00224f10 @ 0x00224f10
struct Vec3_224f10 { float x,y,z; };
extern "C" double __cdecl sqrt(double);
extern float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224f10(const Vec3_224f10* v) {
    float x=v->x, z=v->z;
    union { float f; unsigned int u; } a;
    a.f=v->y; a.u &= 0x7fffffff;
    if (!(a.f <= 1.0e-5f)) {
        double length=sqrt((double)z*z + (double)x*x);
        a.f=(float)length; a.u &= 0x7fffffff;
        if (!(a.f <= 1.0e-5f)) {
            double scale=1.0f/length;
            x=(float)(x*scale);
            z=(float)(z*scale);
        } else { x=0.0f; z=0.0f; }
    }
    return FUN_00224ea0(x,z);
}