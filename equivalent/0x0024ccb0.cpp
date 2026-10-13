// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_0024ccb0 @ 0x0024ccb0
struct Body {
 float x,y,z,vx,vy,vz; char pad[0x18]; float a,b;
 bool FUN_0022d2b0(Body*,float);
};
extern "C" double __cdecl sqrt(double);
float __cdecl FUN_0024ccb0(Body* p, Body* q) {
 double value;
 if (p->FUN_0022d2b0(q,0.00001f)) value=0.0;
 else {
 double x=(double)p->x-q->x, y=(double)p->y-q->y, z=(double)p->z-q->z;
 value=-(((double)p->vz-q->vz)*z+((double)p->vy-q->vy)*y+((double)p->vx-q->vx)*x)/sqrt(z*z+y*y+x*x);
 }
 value=value*p->a*p->b;
 if(value>0.0) {
 if(value>=345.0) value=344.99f;
 value=345.0/(345.0-value);
 } else if(value<0.0) {
 if(value<=-345.0) value=-344.99f;
 value=1.0/(345.0/(value+345.0));
 } else return 1.0f;
 if(value>=0.5 && value<=1.5) return (float)value;
 if(value>1.5) return 1.5f;
 return 0.5f;
}