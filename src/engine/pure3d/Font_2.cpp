// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c3aa0..0x002c3c10 (kind game, layer engine, confidence medium), dominant class pure3d::Font
#include "tree_prelude.h"
#include "decls/data/engine/pure3d/prop.h"
#define TREE_TU_BEGIN namespace fn_f0d385cd {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f0d385cd {} using namespace fn_f0d385cd;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f0d385cd {
struct X_2c3aa0 {
    int a, b, c, d;
    short e;
    X_2c3aa0();
};
struct MatrixStack_2c3ad0 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(int); virtual void s16(int);
};
struct Context { MatrixStack_2c3ad0* stack; void FUN_00293d40(float,float,float); };
namespace pure3d {
struct Font {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual float s7(); virtual void s8(); virtual float s9(const unsigned short*); virtual void s10(); virtual void vfunc_11(const unsigned short*,unsigned int); virtual float s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(const unsigned short*,unsigned int);
};
}


// 0x002c3aa0 FUN_002c3aa0 (20 B): matches/0x002c3aa0.cpp
// sym: ??0X_2c3aa0@fn_f0d385cd@@QAE@XZ
X_2c3aa0::X_2c3aa0() : a(0), b(0), c(0), d(0), e(0) {}


// 0x002c3ac0 FUN_002c3ac0 (1 B): matches/0x002c3ac0.cpp
// sym: ?FUN_002c3ac0@fn_f0d385cd@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002c3ac0(void* /*this, unused: callers pass it (unb4)*/) {}


// 0x002c3ad0 pure3d::Font::vfunc_11 (235 B): equivalent/0x002c3ad0.cpp
// sym: ?vfunc_11@Font@pure3d@fn_f0d385cd@@UAEXPBGI@Z @f904a1d66634 @w674a216ec56b
// STATUS: equivalent (tools/equiv.py level 3: 344 inputs, branch coverage 16/16)
// pure3d::Font::vfunc_11 @ 0x002c3ad0
namespace pure3d {
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

} // namespace fn_f0d385cd
