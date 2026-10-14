// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00224db0 @ 0x00224db0
struct Vec_224db0 { float x,y,z; }; struct Matrix { float m[4][4]; };
void __cdecl FUN_00224db0(Matrix* out, const Vec_224db0* a, const Vec_224db0* b) {
 double x=(double)b->z*a->y-(double)b->y*a->z;
 double y=(double)b->x*a->z-(double)b->z*a->x;
 double z=(double)b->y*a->x-(double)b->x*a->y;
 volatile float dot=(float)(((double)b->z*a->z+(double)b->y*a->y)+(double)a->x*b->x);
 volatile float zz=(float)(z*z); double yy=y*y,xx=x*x;
 volatile float factor=(float)((1.0f-dot)/((xx+yy)+zz));
 out->m[0][0]=(float)(xx*factor+dot);
 double xy=x*y*factor; out->m[0][1]=(float)(xy+z);
 double xz=x*z*factor; volatile float sxz=(float)xz; out->m[0][2]=(float)(xz-y);
 out->m[1][0]=(float)(xy-z); out->m[1][1]=(float)(yy*factor+dot);
 double yz=z*y*factor; volatile float syz=(float)yz; out->m[1][2]=(float)(yz+x);
 out->m[2][0]=(float)((double)sxz+y); out->m[2][1]=(float)((double)syz-x); out->m[2][2]=zz*factor+dot;
}