// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 10/10)
// pure3d::Image32::vfunc_7 @ 0x002c00b0
void* __cdecl FUN_0008d6d0(unsigned int);
void __cdecl FUN_0008d340(void*);
namespace pure3d {
struct Image32 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(int,int);
 char pad[12]; int width; int height; char pad2[12]; unsigned int* pixels;
};
void Image32::vfunc_7(int newWidth,int newHeight) {
 int copyWidth = width < newWidth ? width : newWidth;
 int copyHeight = height < newHeight ? height : newHeight;
 unsigned int size = (unsigned int)newWidth * (unsigned int)newHeight * 4;
 unsigned int* buffer = (unsigned int*)FUN_0008d6d0(size);
 for(unsigned int i=0;i<(size>>2);++i) buffer[i]=0;
 if(pixels) {
  unsigned int* src=pixels;
  unsigned int* dst=buffer;
  for(int y=0;y<copyHeight;++y) {
   unsigned int bytes=(unsigned int)copyWidth*4;
   for(unsigned int x=0;x<(bytes>>2);++x) dst[x]=src[x];
   dst+=newWidth;
   src+=width;
  }
  unsigned int* old=pixels;
  width=newWidth;
  height=newHeight;
  FUN_0008d340(old);
 }
 pixels=buffer;
}
}