// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00294270 @ 0x00294270
#include "decls/data/game/global.h"

struct Vector { float x,y,z; };
struct Display_294270 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int width(); virtual int height(); };
struct Aspect_294270 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void get(float*,float*); };
struct Object { char pad[8]; float left,top,right,bottom; Aspect_294270* aspect; void transform(Vector* in,Vector* out); };
void Object::transform(Vector* in,Vector* out) {
 int h=(*(Display_294270**)&DAT_0052c2a4)->height();
 float x=(float)((double)in->x/h-0.5f);
 int w=(*(Display_294270**)&DAT_0052c2a4)->width();
 float z=in->z;
 float y=(float)(1.0f-(double)in->y/w-0.5f);
 union { int integer; float real; } unused;
 unused.integer=w;
 float scale;
 if(aspect) aspect->get(&unused.real,&scale); else scale=1.0f;
 out->x=(float)(((double)x+0.5f-left)/((double)right-left)-0.5f);
 out->z=z;
 out->y=(float)((0.5f-(0.5f-(double)y-top)/((double)bottom-top))/scale);
}