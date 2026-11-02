// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 8/8)
// FUN_002de8b0 @ 0x002de8b0
struct Source_2de8b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual unsigned int pixel(int x,int y);
};
struct Format_2de8b0 {
 int width,height; char pad08[16];
 unsigned int redOut,greenOut,blueOut,alphaOut;
 unsigned int redIn,greenIn,blueIn,alphaIn;
 char pad38[16]; int pitch;
};
// equiv-conv: FUN_002de8b0 eax esi stack
extern "C" void FUN_002de8b0(unsigned int* destination, void * format, void * source) {
 int padding = (((Format_2de8b0 *)format)->pitch - ((Format_2de8b0 *)format)->width * 4) / 4 * 4;
 for(int y=0;y<((Format_2de8b0 *)format)->height;++y) {
  for(int x=0;x<((Format_2de8b0 *)format)->width;++x) {
   unsigned int p=((Source_2de8b0 *)source)->pixel(x,y);
   unsigned int a=((p & 0xff000000U) >> (((Format_2de8b0 *)format)->alphaIn & 31)) << (((Format_2de8b0 *)format)->alphaOut & 31);
   unsigned int g=((p & 0xff00U) >> (((Format_2de8b0 *)format)->greenIn & 31)) << (((Format_2de8b0 *)format)->greenOut & 31);
   unsigned int b=((p & 0xffU) >> (((Format_2de8b0 *)format)->blueIn & 31)) << (((Format_2de8b0 *)format)->blueOut & 31);
   unsigned int r=((p & 0xff0000U) >> (((Format_2de8b0 *)format)->redIn & 31)) << (((Format_2de8b0 *)format)->redOut & 31);
   *destination++=a|g|b|r;
  }
  destination=(unsigned int*)((char*)destination+padding);
 }
}
