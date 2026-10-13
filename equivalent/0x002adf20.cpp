// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 12/12)
// pure3d::ImageBuilder::vfunc_0 @ 0x002adf20
void* __cdecl FUN_00263ea0(unsigned);
struct Image {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
 virtual void size(int,int);
 virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
 virtual void count(unsigned);
 virtual void s14(); virtual void s15(); virtual void palette(void*,unsigned);
 char pad[0x1c]; int format; char* pixels; unsigned char flag;
 Image* FUN_002bfcb0(); Image* FUN_002bffc0();
};
namespace pure3d { struct ImageHandler { struct Builder {
 virtual bool vfunc_0(int,int,int,int,void*);
 virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
 Image* image; void* paletteData; char* cursor; int index; int stride; int depth;
}; }; struct ImageBuilder : ImageHandler::Builder { virtual bool vfunc_0(int,int,int,int,void*); }; }
bool pure3d::ImageBuilder::vfunc_0(int width,int height,int bits,int direction,void* pal) {
 int bytes=1;
 if(depth<=8 && bits<=8) {
  Image* p=(Image*)FUN_00263ea0(0x438);
  image=p ? p->FUN_002bfcb0() : 0;
  unsigned n=1u << (bits & 31);
  image->palette(pal,n);
  image->count(n);
 } else {
  Image* p=(Image*)FUN_00263ea0(0x30);
  image=p ? p->FUN_002bffc0() : 0;
  bytes=4;
 }
 image->size(width,height);
 image->flag=1;
 image->format=bits==32 ? 8 : 1;
 cursor=image->pixels;
 index=0;
 stride=bytes*width;
 if(direction==1) { cursor+=(height-1)*bytes*width; stride=-stride; }
 paletteData=pal;
 return true;
}