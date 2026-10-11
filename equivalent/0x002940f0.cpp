// STATUS: equivalent (tools/equiv.py level 3: 29 inputs, branch coverage 4/4)
// FUN_002940f0 @ 0x002940f0
struct Vec { float x,y,z; };
struct Camera { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(float* angle,float* scale); };
struct System { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float s16(); };
extern System* DAT_0052c2a4;
extern "C" double __cdecl tan(double);
struct Owner { char pad[24]; Camera* camera; void target(const Vec* in,Vec* out); };
void Owner::target(const Vec* in,Vec* out) {
 if (!camera) return;
 if (in->z == 0.0f) { out->x=0.0f; out->y=0.0f; out->z=1.0f; return; }
 float inverseDepth=1.0f/in->z;
 float scale,angle;
 camera->s6(&angle,&scale);
 double adjustedScale=DAT_0052c2a4->s16()* (double)scale;
 double focal=1.0/tan((double)angle*0.5f);
 out->x=(float)(focal*in->x*inverseDepth*0.5f);
 out->y=(float)(focal*adjustedScale*in->y*inverseDepth*0.5f);
 out->z=in->z;
}
