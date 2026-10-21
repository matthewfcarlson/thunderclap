// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 4/4)
// FUN_00302620 @ 0x00302620
#include "compat/ptr.h"
extern "C" double __cdecl sqrt(double);
struct Vec3_302620 { float x,y,z; };
struct Shape_302620 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual Vec3_302620* position();
 char pad04[0x30]; float radius; char pad38[0xc]; Vec3_302620 normal; float extent; float thickness; unsigned char flag;
};
float __cdecl FUN_00302620(Shape_302620* a, Shape_302620* b) {
 float limit = a->flag ? a->extent : a->thickness + a->extent;
 Vec3_302620* pa=a->position(); Vec3_302620* pb=b->position();
 float dx=pb->x-pa->x, dy=pb->y-pa->y;
 hulk_freg dzWide=(hulk_freg)pb->z-pa->z; // kept in st0 for the dot product, stored rounded as dz
 float dz=dzWide;
 hulk_freg dot=dzWide*a->normal.z; dot+=dy*a->normal.y; dot+=dx*a->normal.x;
 hulk_freg negDot=-dot;
 hulk_freg x=negDot*a->normal.x+dx, y=negDot*a->normal.y+dy, z=negDot*a->normal.z+dz;
 union { float f; unsigned int u; } length, distance;
 length.f=(float)sqrt(z*z+y*y+x*x); length.u &= 0x7fffffff;
 float edge=length.f-((hulk_freg)a->thickness+b->radius);
 distance.f=dot; distance.u &= 0x7fffffff;
 hulk_freg face=distance.f-((hulk_freg)limit+b->radius);
 return face<edge ? edge : face;
}
