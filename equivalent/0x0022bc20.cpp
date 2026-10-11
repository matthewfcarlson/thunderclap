// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0022bc20 @ 0x0022bc20
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
struct Matrix { float m[3][4]; void FUN_0022bc20(float x,float y,float z); };
void Matrix::FUN_0022bc20(float x,float y,float z) {
 double sx=sin(x), cx=cos(x), sy=sin(y);
 float cy=(float)cos(y);
 double sz=sin(z), cz=cos(z);
 float a=(float)(cz*cx), b=(float)(sz*sx), c=(float)(cz*sx), d=(float)(sz*cx);
 m[0][0]=(float)(cz*cy); m[0][1]=(float)(sz*cy); m[0][2]=(float)-sy;
 m[1][0]=(float)(c*sy-d); m[1][1]=(float)(b*sy+a); m[1][2]=(float)(cy*sx);
 m[2][0]=(float)(a*sy+b); m[2][1]=(float)(d*sy-c); m[2][2]=(float)(cy*cx);
}