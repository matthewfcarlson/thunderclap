// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 10/10)
// pure3d::Image8::vfunc_7 @ 0x002bfe10
#include "gen/pure3d.h"

extern "C" void* __cdecl FUN_0008d6d0(unsigned int size);
extern "C" void __cdecl FUN_0008d340(void* data);
namespace pure3d {

}
void pure3d::Image8::vfunc_7(int newWidth, int newHeight) {
 int copyWidth = this->f_10 < newWidth ? this->f_10 : newWidth;
 int copyHeight = this->f_14 < newHeight ? this->f_14 : newHeight;
 unsigned int size = (unsigned int)newWidth * (unsigned int)newHeight;
 unsigned char* buffer = (unsigned char*)FUN_0008d6d0(size);
 for (unsigned int i=0;i<size;++i) buffer[i]=0;
 unsigned char* source=(*(unsigned char * *)&this->f_24);
 if (source) {
  unsigned char* dest=buffer;
  for (int y=0;y<copyHeight;++y) {
   for (unsigned int x=0;x<(unsigned int)copyWidth;++x) dest[x]=source[x];
   dest+=newWidth;
   source+=this->f_10;
  }
  unsigned char* old=(*(unsigned char * *)&this->f_24);
  this->f_10=newWidth;
  this->f_14=newHeight;
  FUN_0008d340(old);
 }
 (*(unsigned char * *)&this->f_24)=buffer;
}
