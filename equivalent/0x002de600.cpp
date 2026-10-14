// STATUS: equivalent (tools/equiv.py level 3: 60 inputs, branch coverage 8/8)
// FUN_002de600 @ 0x002de600
struct Format_2de600 {
 unsigned width, height;
 char pad08[16];
 unsigned redLeft, greenLeft, blueLeft, alphaLeft;
 unsigned redRight, greenRight, blueRight, alphaRight;
 char pad38[16];
 int pitch;
};
// equiv-conv: FUN_002de600 eax ecx esi
void FUN_002de600(unsigned short* destination, const unsigned* source, const Format_2de600* format)
{
 int padding = (format->pitch - (int)(format->width * 2)) / 2;
 unsigned rows = format->height;
 if (rows) {
   do {
     unsigned count = format->width;
     if (count) {
       do {
         unsigned pixel = *source++;
         unsigned result = (((pixel & 0xffu) >> (format->blueRight & 31)) << (format->blueLeft & 31));
         result |= (((pixel & 0xff0000u) >> (format->redRight & 31)) << (format->redLeft & 31));
         result |= (((pixel & 0xff000000u) >> (format->alphaRight & 31)) << (format->alphaLeft & 31));
         result |= (((pixel & 0xff00u) >> (format->greenRight & 31)) << (format->greenLeft & 31));
         *destination++ = (unsigned short)result;
       } while (--count);
     }
     destination = (unsigned short*)((char*)destination + padding * 2);
   } while (--rows);
 }
}
