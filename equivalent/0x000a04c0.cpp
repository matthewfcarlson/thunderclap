// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000a04c0 @ 0x000a04c0
struct Vec { float x,y,z; };
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl atan2(double,double);
extern float __cdecl FUN_000a02a0(float);
extern float __cdecl FUN_000189c0(float);
void __cdecl FUN_000a04c0(Vec* v, float* yaw, float* pitch, float* length) {
 float len = (float)sqrt((double)v->x*v->x + (double)v->y*v->y + (double)v->z*v->z);
 *length = len;
 if (len < 0.00001f) { *yaw=0.0f; *pitch=0.0f; return; }
 union Bits { float f; unsigned int u; } a,b;
 a.f=v->x; a.u &= 0x7fffffff;
 b.f=v->z; b.u &= 0x7fffffff;
 if (a.f <= 0.00001f && b.f <= 0.00001f) *yaw=0.0f;
 else *yaw=FUN_000a02a0((float)(atan2(v->x,v->z)*57.2958f));
 *pitch=FUN_000189c0(v->y/len)*57.2958f;
}