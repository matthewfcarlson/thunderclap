// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 14/14)
// FUN_002de790 @ 0x002de790
struct PixelFormat_2de790 {
 unsigned width, height;
 char reserved08[12];
 unsigned char directCopy;
 char reserved15[3];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 char reserved38[16];
 unsigned pitch;
};
// equiv-conv: FUN_002de790 eax ebx stack
void __cdecl FUN_002de790(unsigned char* destination, volatile PixelFormat_2de790* format, const unsigned* source)
{
 unsigned rows = format->height;
 if (format->directCopy) {
  unsigned bytes = format->width * 4;
  while (rows--) {
   unsigned words = bytes / 4;
   unsigned* out = (unsigned*)destination;
   const unsigned* in = source;
   while (words--) *out++ = *in++;
   bytes = format->width * 4;
   source = (const unsigned*)((const unsigned char*)source + bytes);
   destination += format->pitch;
  }
 } else {
  int gap = (int)(format->pitch - format->width * 4);
  gap = (gap / 4) * 4;
  while (rows--) {
   unsigned count = format->width;
   while (count--) {
    unsigned pixel = *source++;
    unsigned blue = ((pixel & 0xff) >> (format->blueRight & 31)) << (format->blueLeft & 31);
    unsigned red = ((pixel & 0xff0000) >> (format->redRight & 31)) << (format->redLeft & 31);
    unsigned alpha = ((pixel & 0xff000000) >> (format->alphaRight & 31)) << (format->alphaLeft & 31);
    unsigned green = ((pixel & 0xff00) >> (format->greenRight & 31)) << (format->greenLeft & 31);
    *(unsigned*)destination = blue | red | alpha | green;
    destination += 4;
   }
   destination += gap;
  }
 }
}
