// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0022b650 @ 0x0022b650
struct Matrix { float m[12]; void FUN_0022b9c0(); };
struct Quaternion_22b650 { float x,y,z,w; void convert(Matrix* out); };
void Quaternion_22b650::convert(Matrix* out) {
 float delta=w-1.0f;
 if (delta<0) delta=-delta;
 if (delta<=1e-05f) { out->FUN_0022b9c0(); return; }
 double dx=(double)x*2, dy=(double)y*2;
 float dz=z*2;
 float xw=(float)(dx*w), yw=(float)(dy*w), zw=dz*w;
 float xx=(float)(dx*x), xy=(float)(dy*x), xz=dz*x, yy=(float)(dy*y);
 double yz=dy*z, zz=(double)dz*z;
 out->m[0]=(float)(1.0-(yy+zz));
 out->m[4]=xy-zw;
 out->m[8]=xz+yw;
 out->m[1]=xy+zw;
 out->m[5]=(float)(1.0-(zz+xx));
 out->m[9]=(float)(yz-xw);
 out->m[2]=xz-yw;
 out->m[6]=(float)(yz+xw);
 out->m[10]=1.0f-(yy+xx);
}