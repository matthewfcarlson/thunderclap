// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0022b750 @ 0x0022b750
extern "C" float __cdecl FUN_00018a20(float);
extern "C" double __cdecl sin(double);
struct Quaternion { float x,y,z,w; void interpolate(const Quaternion* a,const Quaternion* b,float t); };
void Quaternion::interpolate(const Quaternion* a,const Quaternion* b,float t) {
 double dot = (double)a->z*b->z + (double)a->y*b->y + (double)b->w*a->w + (double)a->x*b->x;
 float d=(float)dot;
 float sign=1.0f;
 if(dot<0.0f) { sign=-1.0f; d=-d; dot=d; }
 double first, second;
 if(dot>=0.997222f) { first=1.0-t; second=(double)sign*t; }
 else { float angle=FUN_00018a20(d); float inv=(float)(1.0/sin((double)angle)); first=sin((1.0-t)*angle)*inv; second=sin((double)angle*t)*inv*sign; }
 x=(float)(first*a->x+second*b->x);
 y=(float)(first*a->y+second*b->y);
 z=(float)(first*a->z+second*b->z);
 w=(float)(first*a->w+second*b->w);
}