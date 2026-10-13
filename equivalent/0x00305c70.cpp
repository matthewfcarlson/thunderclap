// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00305c70 @ 0x00305c70
extern "C" double sqrt(double); extern "C" double sin(double); extern "C" double cos(double);
float __cdecl FUN_00018a20(float);
struct Vec { float x,y,z; float FUN_0022d110(); };
struct Quat { float x,y,z,w; void FUN_0022b1c0(float); void FUN_0022b120(); };
bool __cdecl FUN_00305c70(const Vec* a,const Vec* b,Quat* out,bool* opposite) {
 *opposite=false;
 double lengths=sqrt(a->x*a->x+a->y*a->y+a->z*a->z)*sqrt(b->x*b->x+b->y*b->y+b->z*b->z);
 if(lengths < 0.000001f) {out->z=0;out->y=0;out->x=0;out->w=1;return false;}
 double dot=(a->y*b->y+a->z*b->z)+a->x*b->x;
 float savedDot=(float)dot;
 double ratio=dot/lengths;
 float angle;
 if(ratio>=1.0f) angle=0; else angle=FUN_00018a20((float)ratio);
 Vec axis;
 axis.x=b->z*a->y-a->z*b->y;
 axis.y=b->x*a->z-b->z*a->x;
 axis.z=a->x*b->y-b->x*a->y;
 if(sqrt(axis.z*axis.z+axis.x*axis.x+axis.y*axis.y)<0.000001f) {
  if(savedDot>0.0f) {out->z=0;out->y=0;out->x=0;out->w=1;return true;}
  *opposite=true; angle=3.141592741012573242f;
  axis.x=a->z*0.0f-a->y*0.0f;
  axis.y=a->x*0.0f-a->z;
  axis.z=a->y-a->x*0.0f;
  if(sqrt(axis.z*axis.z+axis.x*axis.x+axis.y*axis.y)<0.000001f) {out->FUN_0022b1c0(3.141592741012573242f);return true;}
 }
 if(axis.FUN_0022d110()!=0.0f) {
  double half=angle*0.5f;
  out->w=(float)cos(half);
  double s=sin(half);
  out->x=(float)(axis.x*s);out->y=(float)(axis.y*s);out->z=(float)(axis.z*s);
  out->FUN_0022b120();
 } else {out->z=0;out->y=0;out->x=0;out->w=1;}
 return true;
}