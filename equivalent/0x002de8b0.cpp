// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 8/8)
// FUN_002de8b0 @ 0x002de8b0
struct Source {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual unsigned int pixel(int x,int y);
};
struct Format {
 int width,height; char pad08[16];
 unsigned int redOut,greenOut,blueOut,alphaOut;
 unsigned int redIn,greenIn,blueIn,alphaIn;
 char pad38[16]; int pitch;
};
// equiv-conv: FUN_002de8b0 eax esi stack
void FUN_002de8b0(unsigned int* destination, Format* format, Source* source) {
 int padding = (format->pitch - format->width * 4) / 4 * 4;
 for(int y=0;y<format->height;++y) {
  for(int x=0;x<format->width;++x) {
   unsigned int p=source->pixel(x,y);
   unsigned int a=((p & 0xff000000U) >> (format->alphaIn & 31)) << (format->alphaOut & 31);
   unsigned int g=((p & 0xff00U) >> (format->greenIn & 31)) << (format->greenOut & 31);
   unsigned int b=((p & 0xffU) >> (format->blueIn & 31)) << (format->blueOut & 31);
   unsigned int r=((p & 0xff0000U) >> (format->redIn & 31)) << (format->redOut & 31);
   *destination++=a|g|b|r;
  }
  destination=(unsigned int*)((char*)destination+padding);
 }
}
