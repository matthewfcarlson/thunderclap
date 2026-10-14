// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0028d820 @ 0x0028d820
struct Quaternion { float x,y,z,w; };
extern "C" double __cdecl sqrt(double);
struct Packed { unsigned int bits; Quaternion* decode(Quaternion* out); };
Quaternion* Packed::decode(Quaternion* out) {
 unsigned int v=bits;
 double x=(int)(v&2047)* (double)0.00097751710657030344f - 1.0;
 float y=(float)((int)((v>>11)&2047)*(double)0.00097751710657030344f-1.0);
 double zz=(int)(v>>22)*(double)0.001956947147846222f-1.0;
 float z=(float)zz;
 double w=1.0-((zz*z+(double)y*y)+x*x);
 if(w<0.0) w=0.0; else w=sqrt(w);
 out->x=(float)x; out->y=y; out->z=z; out->w=(float)w;
 return out;
}