// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0022b220 @ 0x0022b220
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Quaternion_22b220 {
 float x,y,z,w;
 void FUN_0022b220(float a,float b,float c);
};
void Quaternion_22b220::FUN_0022b220(float a,float b,float c) {
 double sa=sin(a*0.5), sb=sin(b*0.5);
 float ca=(float)cos(a*0.5), cb=(float)cos(b*0.5);
 float sc=(float)sin(c*0.5), cc=(float)cos(c*0.5);
 float t=(float)(ca*sb), u=(float)(sb*sa);
 double v=sa*cb, k=cb*ca;
 x=(float)(v*cc-t*sc);
 y=(float)(v*sc+t*cc);
 z=(float)(k*sc-u*cc);
 w=(float)(k*cc+u*sc);
}