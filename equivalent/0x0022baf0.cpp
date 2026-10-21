// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_0022baf0 @ 0x0022baf0
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Vec_22baf0 { float x,y,z; void FUN_0022d1c0(const Vec_22baf0*); };
struct Matrix { float m[16]; void build(const Vec_22baf0* axis,float angle); };
void Matrix::build(const Vec_22baf0* axis,float angle) {
 Vec_22baf0 v; v.FUN_0022d1c0(axis);
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