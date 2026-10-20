// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 16/16)
// pure3d::TextureBuilder::vfunc_1 @ 0x002ae5a0
#include "gen/pure3d.h"

namespace pure3d {
struct PixelFormat_2ae5a0 {
 int width; int unknown4; int bits; char reserved[8]; unsigned char directCopy; char pad[3];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 unsigned FUN_002addb0(unsigned pixel);
};

}
void pure3d::TextureBuilder::vfunc_1(void* __p0) { const unsigned int * source = (const unsigned int *)__p0;

 if (!(*(unsigned int *)&this->f_04)) return;
 if ((*(PixelFormat_2ae5a0 * *)&this->f_0c)->bits == 16) {
  unsigned short* out = (unsigned short*)(*(unsigned char * *)&this->f_14);
  for (int i=0; i<(*(PixelFormat_2ae5a0 * *)&this->f_0c)->width; ++i) {
   PixelFormat_2ae5a0* f = (*(PixelFormat_2ae5a0 * *)&this->f_0c);
   unsigned p = *source++;
   unsigned b = ((p & 0xffu) >> (f->blueRight & 31)) << (f->blueLeft & 31);
   unsigned r = ((p & 0xff0000u) >> (f->redRight & 31)) << (f->redLeft & 31);
   unsigned a = ((p & 0xff000000u) >> (f->alphaRight & 31)) << (f->alphaLeft & 31);
   unsigned g = ((p & 0xff00u) >> (f->greenRight & 31)) << (f->greenLeft & 31);
   *out++ = (unsigned short)(b | r | a | g);
  }
 } else if ((*(PixelFormat_2ae5a0 * *)&this->f_0c)->bits == 32) {
  unsigned* out = (unsigned*)(*(unsigned char * *)&this->f_14);
  if ((*(PixelFormat_2ae5a0 * *)&this->f_0c)->directCopy) {
   unsigned count = ((unsigned)(*(PixelFormat_2ae5a0 * *)&this->f_0c)->width << 2) >> 2;
   for (unsigned i=0; i<count; ++i) *out++ = *source++;
  } else {
   for (int i=0; i<(*(PixelFormat_2ae5a0 * *)&this->f_0c)->width; ++i) {
    unsigned converted = (*(PixelFormat_2ae5a0 * *)&this->f_0c)->FUN_002addb0(*source);
    *out++ = converted;
    ++source;
   }
  }
 }
 (*(unsigned char * *)&this->f_14) += (*(unsigned int *)&this->f_10);
 ++(*(unsigned int *)&this->f_18);
}
