// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000595f0 @ 0x000595f0
struct Vec_595f0 { float x,y,z; };
struct World { char pad[16]; Vec_595f0 value; };
extern World* DAT_00554c10;
struct Obj_595f0 { char pad[0x28]; Vec_595f0 velocity; char pad2[0x28]; float duration; char pad3[4]; float acceleration;
void FUN_000595f0(const Vec_595f0* v, float scale, float time, float height);
};
void Obj_595f0::FUN_000595f0(const Vec_595f0* v, float scale, float time, float height) {
 if (time <= 0.0f) { duration=0.0f; velocity.z=0.0f; velocity.y=0.0f; velocity.x=0.0f; acceleration=DAT_00554c10->value.y * -0.01f; return; }
 double inverse=1.0f / (double)time;
 duration=time; velocity=*v;
 double factor=(double)scale*inverse;
 velocity.x=(float)(factor*velocity.x);
 velocity.z=(float)(factor*velocity.z);
 union { float f; unsigned int u; } magnitude;
 magnitude.f=height; magnitude.u &= 0x7fffffff;
 if(magnitude.f<=1e-05f) {velocity.y=0.0f; acceleration=0.0f;return;}
 if(height<0.0f) {velocity.y=(float)(inverse*height); acceleration=DAT_00554c10->value.y * -0.01f;}
 else {velocity.y=(float)(inverse*height*4.0f); acceleration=(float)(((double)height*8.0f)/((double)time*time));}
}
