// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CDropShadowDisplayEffect::vfunc_0 @ 0x000dee60
#include "decls/data/engine/pure3d/prop.h"

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
