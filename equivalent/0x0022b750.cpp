// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4; Wine build 605 inputs, 4/4)
// FUN_0022b750 @ 0x0022b750
#include "compat/ptr.h"
extern "C" hulk_freg __cdecl FUN_00018a20(float);
extern "C" double __cdecl sin(double);
struct Quaternion_22b750 { float x,y,z,w; void interpolate(const Quaternion_22b750* a,const Quaternion_22b750* b,float t); };
void Quaternion_22b750::interpolate(const Quaternion_22b750* a,const Quaternion_22b750* b,float t) {
 double dot = (double)a->z*b->z + (double)a->y*b->y + (double)b->w*a->w + (double)a->x*b->x;
 float d=(float)dot;
 float sign=1.0f;
 if(dot<0.0f) { sign=-1.0f; d=-d; dot=d; }
 double first, second;
 if(dot>=0.997222245f) { first=1.0-t; second=(double)sign*t; }
 else {
  // x87: the acos result stays in st0 for the first fsin (1/sin(angle)); its rounded copy (fst) is what the two
  // products (1-t)*angle and angle*t read
  hulk_freg ang=FUN_00018a20(d);
  float angle=(float)ang;
  float inv=(float)(1.0/sin((double)ang));
  first=sin((1.0-t)*angle)*inv;
  second=sin((double)angle*t)*inv*sign;
 }
 x=(float)(first*a->x+second*b->x);
 y=(float)(first*a->y+second*b->y);
 z=(float)(first*a->z+second*b->z);
 w=(float)(first*a->w+second*b->w);
}
