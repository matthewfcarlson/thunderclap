// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0030ad10 @ 0x0030ad10
struct Vec3_30ad10 { float x,y,z; };
struct Helper_30ad10 { void FUN_00310490(int, Vec3_30ad10*, int); };
extern float __cdecl FUN_00018a20(float);
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual float v6();
 char pad4[8]; int value; char pad10[8]; Helper_30ad10* helper; char pad1c[0x7c]; float x,y,z;
 void target(char mode, float* out);
};
void Object::target(char mode, float* out) {
 if (!mode) { *out=v6(); return; }
 Vec3_30ad10 v;
 helper->FUN_00310490(value,&v,0);
 float a=v.z*z + v.y*y + v.x*x;
 *out=a;
 float r;
 if (!(a >= 1.0f)) r=FUN_00018a20(a); else r=0.0f;
 *out=r;
 union { float f; unsigned int u; } bits;
 bits.f=r; bits.u &= 0x7fffffff;
 if (bits.f < 0.1f) *out=0.0f;
}
