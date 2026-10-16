// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 10/10)
// pure3d::Image32::vfunc_7 @ 0x002c00b0
#include "gen/pure3d.h"

void* __cdecl FUN_0008d6d0(unsigned int);
void __cdecl FUN_0008d340(void*);
namespace pure3d {

}
void pure3d::Image32::vfunc_7(int newWidth, int newHeight) {
 int copyWidth = this->f_10 < newWidth ? this->f_10 : newWidth;
 int copyHeight = this->f_14 < newHeight ? this->f_14 : newHeight;
 unsigned int size = (unsigned int)newWidth * (unsigned int)newHeight * 4;
 unsigned int* buffer = (unsigned int*)FUN_0008d6d0(size);
 for(unsigned int i=0;i<(size>>2);++i) buffer[i]=0;
 if((*(unsigned int * *)&this->f_24)) {
  unsigned int* src=(*(unsigned int * *)&this->f_24);
  unsigned int* dst=buffer;
  for(int y=0;y<copyHeight;++y) {
   unsigned int bytes=(unsigned int)copyWidth*4;
   for(unsigned int x=0;x<(bytes>>2);++x) dst[x]=src[x];
   dst+=newWidth;
   src+=this->f_10;
  }
  unsigned int* old=(*(unsigned int * *)&this->f_24);
  this->f_10=newWidth;
  this->f_14=newHeight;
  FUN_0008d340(old);
 }
 (*(unsigned int * *)&this->f_24)=buffer;
}
