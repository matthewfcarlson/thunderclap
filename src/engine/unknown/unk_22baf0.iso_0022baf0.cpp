// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0022baf0..0x00230800 (kind game, layer engine, confidence low)
// (tree_prelude.h: not needed)


// 0x0022baf0 FUN_0022baf0 (299 B): equivalent/0x0022baf0.cpp [isolated: code differs from its standalone build]
// sym: ?build@Matrix@fn_ff6652fc@@QAEXPBUVec_22baf0@2@M@Z @9fe4f618d445 @w7eb562666496
#include "gen/owners.h"
namespace fn_ff6652fc {} using namespace fn_ff6652fc;
namespace fn_ff6652fc {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0022baf0 @ 0x0022baf0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl cos(double);
#endif

struct Vec_22baf0 { float x,y,z;  };
struct Matrix { float m[16]; void build(const Vec_22baf0* axis,float angle); };
void Matrix::build(const Vec_22baf0* axis,float angle) {
 Vec_22baf0 v; ((owners::Vec3_22d1c0 *)&v)->FUN_0022d1c0((const owners::Vec3_22d1c0 *)(const Vec_22baf0 *)axis);
 double s=sin((double)angle*0.5), c=cos((double)angle*0.5);
 float x=(float)(v.x*s), y=(float)(v.y*s);
 double z=v.z*s;
 double xx2=(double)x+x;
 float y2=y+y,z2=(float)(z+z);
 volatile float xc=(float)(xx2*c),yc=(float)(y2*c),zc=(float)(z2*c);
 volatile float xx=(float)(xx2*x); /* kept as a rounded frame copy in the original */
 volatile float xy=y2*x,xz=z2*x,yy=y2*y,yz=z2*y;
 double zz=z2*z;
 m[0]=(float)(1.0-((double)yy+zz)); m[1]=xy-zc; m[2]=xz+yc;
 m[4]=xy+zc; m[5]=(float)(1.0-(zz+xx)); m[6]=yz-xc;
 m[8]=xz-yc; m[9]=yz+xc; m[10]=(float)(1.0-((double)yy+xx));
}
} // namespace fn_ff6652fc

