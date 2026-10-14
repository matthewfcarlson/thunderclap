// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 8/8)
// FUN_002de6c0 @ 0x002de6c0
struct Source {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual unsigned int pixel(int x,int y);
};
struct Format {
 int width,height;
 char pad08[16];
 unsigned int redLeft,greenLeft,blueLeft,alphaLeft;
 unsigned int redRight,greenRight,blueRight,alphaRight;
 char pad38[16];
 int pitch;
};
// equiv-conv: FUN_002de6c0 eax esi stack
void FUN_002de6c0(unsigned short* destination, Format* format, Source* source) {
 int remainder = (int)((unsigned int)format->pitch - (unsigned int)format->width*2);
 int padding = (remainder / 2)*2;
 if(format->height <= 0) return;
 for(int y=0; y<format->height; ++y) {
  for(int x=0; x<format->width; ++x) {
   unsigned int color = source->pixel(x,y);
   unsigned int a = ((color & 0xff000000u) >> (format->alphaRight & 31)) << (format->alphaLeft & 31);
   unsigned int g = ((color & 0xff00u) >> (format->greenRight & 31)) << (format->greenLeft & 31);
   unsigned int b = ((color & 0xffu) >> (format->blueRight & 31)) << (format->blueLeft & 31);
   unsigned int r = ((color & 0xff0000u) >> (format->redRight & 31)) << (format->redLeft & 31);
   *destination++ = (unsigned short)(a|g|b|r);
  }
  destination = (unsigned short*)((char*)destination + padding);
 }
}
