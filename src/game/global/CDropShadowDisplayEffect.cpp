// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000dee10..0x000def60 (kind game, layer game, confidence medium), dominant class CDropShadowDisplayEffect
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#define TREE_TU_BEGIN namespace fn_f7992297 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f7992297 {} using namespace fn_f7992297;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f7992297 {
extern "C" char DAT_0040bf00[];
class CGlowDisplayEffect {
  public:
    hulk_uintptr vptr;
    int a;
    int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int g;
    CGlowDisplayEffect();
};
class CDisplayEffect_dee40 {
  public:
    CDisplayEffect_dee40() {
        a = 0;
        b = 0;
    }
    int a;
    int b;
};
class CDropShadowDisplayEffect : public CDisplayEffect_dee40 {
  public:
    CDropShadowDisplayEffect();
    virtual void f();
    float c;
    unsigned int d;
};


// 0x000dee10 FUN_000dee10 (45 B): matches/0x000dee10.cpp
// sym: ??0CGlowDisplayEffect@fn_f7992297@@QAE@XZ
CGlowDisplayEffect::CGlowDisplayEffect() {
    a = 0;
    b = 0;
    vptr = ((hulk_intptr)DAT_0040bf00);
    c = 0x3dcccccd;
    d = 0x7f00de19;
    e = 0x3f800000;
    g = 0x3e79db23;
}


// 0x000dee40 FUN_000dee40 (31 B): matches/0x000dee40.cpp
// sym: ??0CDropShadowDisplayEffect@fn_f7992297@@QAE@XZ
CDropShadowDisplayEffect::CDropShadowDisplayEffect() {
    c = 0.1f;
    d = 0xff000000;
}

} // namespace fn_f7992297

// 0x000dee60 CDropShadowDisplayEffect::vfunc_0 (220 B): equivalent/0x000dee60.cpp [wrapped: conflict: CDropShadowDisplayEffect]
// sym: ?vfunc_0@CDropShadowDisplayEffect@fn_000dee60@@UAEXPAUDrawable@2@@Z
namespace fn_000dee60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CDropShadowDisplayEffect::vfunc_0 @ 0x000dee60

struct Drawable { virtual void draw(); virtual void setColor(unsigned); virtual void getColor(unsigned*); virtual float size(); };
struct Vector { float x,y,z; };
struct Renderer_dee60 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void push(int); virtual void pop(int); };
struct Context { Renderer_dee60* renderer; void FUN_00293d00(Vector*); };
struct CDropShadowDisplayEffect { virtual void vfunc_0(Drawable*); int mode; float unused; float scale; unsigned color; };
void CDropShadowDisplayEffect::vfunc_0(Drawable* object) {
 unsigned saved;
 object->getColor(&saved);
 unsigned alpha=(unsigned)(int)((int)((saved>>24)*(color>>24))*0.003921568859368563f);
 object->setColor((alpha<<24)|(color&0xffffff));
 Vector offset;
 if(mode==0) {
 float negative = -(object->size()*scale);
 offset.x=object->size()*scale;
 offset.y=negative;
 offset.z=0.01f;
 }
 (*(Context**)&DAT_0052c2ac)->renderer->push(0);
 (*(Context**)&DAT_0052c2ac)->FUN_00293d00(&offset);
 object->draw();
 (*(Context**)&DAT_0052c2ac)->renderer->pop(0);
 object->setColor(saved);
}
} // namespace fn_000dee60

