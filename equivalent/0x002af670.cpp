// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 12/12)
// FUN_002af670 @ 0x002af670
#include "gen/owners.h"
struct Stream {
 int FUN_00263fc0();
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
extern "C" int __cdecl FUN_002af670(void * info, void * stream, void * image) {
 unsigned int palette[256] = {0};
 int count = ((Info_2af670 *)info)->paletteCount;
 if (!count) count = 256;
 ((owners::X_2647e0 *)(((Stream *)stream)))->FUN_002647e0((hulk_intptr)palette, (hulk_intptr)count, 4, (hulk_intptr)1);
 for(int i=0;i<count;++i) palette[i] |= 0xff000000;
 ((Image *)image)->init(((Info_2af670 *)info)->width,((Info_2af670 *)info)->height,8,1,palette);
 int position=((Stream *)stream)->FUN_00263fc0();
 ((owners::S_264510 *)(((Stream *)stream)))->FUN_00264510((unsigned)(((Info_2af670 *)info)->position-position));
 int width=((Info_2af670 *)info)->width;
 int padding=(width & 3) ? 4-(width & 3):0;
 void* buffer=FUN_00266e00(1,width);
 for(int y=0;y<((Info_2af670 *)info)->height;++y) {
 ((owners::X_2647e0 *)(((Stream *)stream)))->FUN_002647e0((hulk_intptr)buffer, (hulk_intptr)width, 1, (hulk_intptr)1);
 ((Image *)image)->row(buffer);
 ((owners::S_264510 *)(((Stream *)stream)))->FUN_00264510((unsigned)padding);
 }
 FUN_00267090(buffer);
 return ((Image *)image)->finish();
}