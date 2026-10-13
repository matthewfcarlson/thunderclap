// STATUS: equivalent (tools/equiv.py level 3: 185 inputs, branch coverage 16/16)
// Render::Canvas::HulkShaderCallback::vfunc_3 @ 0x001c1460
typedef unsigned long U32;
struct Color { U32 value; void FUN_00011750(U32 from, U32 to, float amount); };
struct Device {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
 virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
 virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
 virtual void s32(); virtual void s33(); virtual int count(); virtual void setColor(U32); virtual Color* getColor(Color*); virtual void s37(); virtual void s38(); virtual bool enabled(int); virtual void s40(); virtual void s41(); virtual void setLight(int,U32); virtual Color* getLight(Color*,int);
};
extern Device* DAT_0052c2a8;
struct Shader { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void setInt(U32,int); virtual void setFloat(U32,float); };
struct Object { char pad[16]; Shader* shader; };
namespace Render { namespace Canvas {
struct HulkShaderCallback {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual Object* vfunc_3(Object*); virtual void vfunc_4(); virtual void vfunc_5();
 U32 refs; float fade; float lighting; float blend; U32 blendColor; U32 savedColor;
};
Object* HulkShaderCallback::vfunc_3(Object* object) {
 Color color;
 if (blend > 0.0f) {
  U32 original = DAT_0052c2a8->getColor(&color)->value;
  savedColor = original;
  color.FUN_00011750(original, blendColor, blend);
  DAT_0052c2a8->setColor(color.value);
  int n = DAT_0052c2a8->count();
  for(int i=0;i<n;++i) {
   if(DAT_0052c2a8->enabled(i)) {
    DAT_0052c2a8->getLight(&color,i);
    color.FUN_00011750(color.value,0xff000000,blend);
    DAT_0052c2a8->setLight(i,color.value);
   }
  }
 }
 if(fade > 0.0f && object) object->shader->setFloat(0x45444146,fade);
 if(lighting < 1.0f && object) object->shader->setInt(0x4153524c,1);
 return object;
}
}}
