// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 16/16)
// pure3d::TextureBuilder::vfunc_1 @ 0x002ae5a0
namespace pure3d {
struct PixelFormat_2ae5a0 {
 int width; int unknown4; int bits; char reserved[8]; unsigned char directCopy; char pad[3];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 unsigned FUN_002addb0(unsigned pixel);
};
struct TextureBuilder {
 virtual void vfunc_0();
 virtual void vfunc_1(const unsigned* source);
 unsigned active; unsigned unknown8; PixelFormat_2ae5a0* format; unsigned stride; unsigned char* destination; unsigned row;
};
void TextureBuilder::vfunc_1(const unsigned* source) {
 if (!active) return;
 if (format->bits == 16) {
  unsigned short* out = (unsigned short*)destination;
  for (int i=0; i<format->width; ++i) {
   PixelFormat_2ae5a0* f = format;
   unsigned p = *source++;
   unsigned b = ((p & 0xffu) >> (f->blueRight & 31)) << (f->blueLeft & 31);
   unsigned r = ((p & 0xff0000u) >> (f->redRight & 31)) << (f->redLeft & 31);
   unsigned a = ((p & 0xff000000u) >> (f->alphaRight & 31)) << (f->alphaLeft & 31);
   unsigned g = ((p & 0xff00u) >> (f->greenRight & 31)) << (f->greenLeft & 31);
   *out++ = (unsigned short)(b | r | a | g);
  }
 } else if (format->bits == 32) {
  unsigned* out = (unsigned*)destination;
  if (format->directCopy) {
   unsigned count = ((unsigned)format->width << 2) >> 2;
   for (unsigned i=0; i<count; ++i) *out++ = *source++;
  } else {
   for (int i=0; i<format->width; ++i) {
    unsigned converted = format->FUN_002addb0(*source);
    *out++ = converted;
    ++source;
   }
  }
 }
 destination += stride;
 ++row;
}
}
