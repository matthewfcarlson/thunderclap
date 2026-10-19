// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001c20e0 @ 0x001c20e0
struct Vec_1c20e0 { float x,y,z; float FUN_0022d110(); };
struct Input_1c20e0 { float x,y,z,radius; };
struct Matrix { float m[16]; void FUN_0022c2b0(const Input_1c20e0*, Vec_1c20e0*); };
struct Object { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual float s8(); virtual void s9(); virtual float s10(); virtual void s11(); virtual void s12(); virtual Matrix* s13(); };
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl atan(double);
float __cdecl FUN_00018a20(float);
struct Target_1c20e0 { char pad[8]; Object* object; char pad2[0xa4]; float horizontalLimit,verticalLimit; int FUN_001c20e0(const Input_1c20e0*); };
int Target_1c20e0::FUN_001c20e0(const Input_1c20e0* input) {
 Matrix matrix=*object->s13(); Vec_1c20e0 position; matrix.FUN_0022c2b0(input,&position);
 if (object->s8()>position.z) return false;
 if (object->s10()<position.z) return false;
 Vec_1c20e0 direction=position; direction.y=0.0f;
 float angularRadius=(float)atan(input->radius/sqrt((double)position.x*position.x+(double)position.y*position.y+(double)position.z*position.z));
 direction.FUN_0022d110();
 if (FUN_00018a20(direction.z)+angularRadius>horizontalLimit) return false;
 direction.x=0.0f; direction.y=position.y; direction.z=position.z;
 direction.FUN_0022d110();
 return !(FUN_00018a20(direction.z)+angularRadius>verticalLimit);
}