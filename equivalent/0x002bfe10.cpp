// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 10/10)
// pure3d::Image8::vfunc_7 @ 0x002bfe10
extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
extern "C" void __cdecl FUN_0008d340(void* data);
namespace pure3d {
struct Image8 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(int width, int height);
 char padding04[12];
 int width;
 int height;
 char padding18[12];
 unsigned char* pixels;
};
void Image8::vfunc_7(int newWidth,int newHeight) {
 int copyWidth = width < newWidth ? width : newWidth;
 int copyHeight = height < newHeight ? height : newHeight;
 unsigned int size = (unsigned int)newWidth * (unsigned int)newHeight;
 unsigned char* buffer = (unsigned char*)FUN_0008d6d0(size);
 for (unsigned int i=0;i<size;++i) buffer[i]=0;
 unsigned char* source=pixels;
 if (source) {
  unsigned char* dest=buffer;
  for (int y=0;y<copyHeight;++y) {
   for (unsigned int x=0;x<(unsigned int)copyWidth;++x) dest[x]=source[x];
   dest+=newWidth;
   source+=width;
  }
  unsigned char* old=pixels;
  width=newWidth;
  height=newHeight;
  FUN_0008d340(old);
 }
 pixels=buffer;
}
}
