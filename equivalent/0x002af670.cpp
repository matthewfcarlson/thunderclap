// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 12/12)
// FUN_002af670 @ 0x002af670
struct Stream {
 void FUN_002647e0(void*, int, int, int);
 int FUN_00263fc0();
 void FUN_00264510(int);
};
struct Info_2af670 { char pad0[8]; int position; char pad1[4]; int width; int height; char pad2[20]; int paletteCount; };
struct Image {
 virtual void init(int,int,int,int,void*);
 virtual void slot1();
 virtual void row(void*);
 virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual int finish();
};
extern void* __cdecl FUN_00266e00(int,int);
extern void __cdecl FUN_00267090(void*);
// equiv-conv: FUN_002af670 esi ebx stack
int __cdecl FUN_002af670(Info_2af670* info, Stream* stream, Image* image) {
 unsigned int palette[256] = {0};
 int count = info->paletteCount;
 if (!count) count = 256;
 stream->FUN_002647e0(palette,count,4,1);
 for(int i=0;i<count;++i) palette[i] |= 0xff000000;
 image->init(info->width,info->height,8,1,palette);
 int position=stream->FUN_00263fc0();
 stream->FUN_00264510(info->position-position);
 int width=info->width;
 int padding=(width & 3) ? 4-(width & 3):0;
 void* buffer=FUN_00266e00(1,width);
 for(int y=0;y<info->height;++y) {
 stream->FUN_002647e0(buffer,width,1,1);
 image->row(buffer);
 stream->FUN_00264510(padding);
 }
 FUN_00267090(buffer);
 return image->finish();
}