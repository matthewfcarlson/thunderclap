// STATUS: equivalent (tools/equiv.py level 3: 344 inputs, branch coverage 16/16)
// pure3d::Font::vfunc_11 @ 0x002c3ad0
#include "decls/data/engine/pure3d/prop.h"

struct MatrixStack_2c3ad0 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(int); virtual void s16(int);
};
struct Context { MatrixStack_2c3ad0* stack; void FUN_00293d40(float,float,float); };
namespace pure3d {
struct Font {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual float s7(); virtual void s8(); virtual float s9(const unsigned short*); virtual void s10(); virtual void vfunc_11(const unsigned short*,unsigned int); virtual float s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(const unsigned short*,unsigned int);
};
void Font::vfunc_11(const unsigned short* text,unsigned int flags) {
 if (!text) return;
 float height=s12();
 float advance=s7()+height;
 (*(Context**)&DAT_0052c2ac)->stack->s15(0);
 float x=0.0f;
 if(flags & 2) x=s9(text)*-0.5f;
 (*(Context**)&DAT_0052c2ac)->FUN_00293d40(0.0f,x,0.0f);
 unsigned int i=0;
 if(text[0]) {
 float step=-advance;
 do {
 s19(text+i,flags);
 while(text[i] && text[i]!=10) ++i;
 if(text[i]==10) ++i;
 (*(Context**)&DAT_0052c2ac)->FUN_00293d40(0.0f,step,0.0f);
 } while(text[i]);
 }
 (*(Context**)&DAT_0052c2ac)->stack->s16(0);
}
}
