// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// pure3d::d3dPrimBufferStream::vfunc_1 @ 0x00327480
extern "C" double __cdecl sqrt(double);
namespace pure3d {
struct pddiPrimBufferStream { virtual void vfunc_0(); virtual void vfunc_1(float x,float y,float z); };
struct d3dPrimBufferStream : pddiPrimBufferStream {
 char reserved[0x24]; float* normal; unsigned int* packedNormal;
 virtual void vfunc_1(float x,float y,float z);
};
void d3dPrimBufferStream::vfunc_1(float x,float y,float z) {
 unsigned int* output=packedNormal;
 if(output) {
  double scale=1.0f/(sqrt((double)x*x+(double)y*y+(double)z*z)*1.001f);
  int iy=(int)((double)y*scale*2147483648.0f);
  unsigned int bits=(iy>>21)&0x7ff;
  int iz=(int)((double)z*scale*2147483648.0f);
  bits|=(unsigned int)(iz>>22)<<11;
  bits<<=11;
  int ix=(int)(scale*x*2147483648.0f);
  bits|=(ix>>21)&0x7ff;
  *output=bits;
 } else { normal[0]=x; normal[1]=y; normal[2]=z; }
}
}