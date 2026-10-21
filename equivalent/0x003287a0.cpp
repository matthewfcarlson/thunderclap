// STATUS: equivalent (tools/equiv.py level 3: 20066 inputs, branch coverage 17/20, incomplete)
// FUN_003287a0 @ 0x003287a0
#include "decls/data/platform/xbox/pure3d.h"

struct Item_3287a0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void enable(int); virtual void update(float,float,float,float,unsigned); };
struct Manager_3287a0 {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual Item_3287a0* get(int);
};
void __cdecl FUN_003287a0() {
 Item_3287a0* item=(*(Manager_3287a0**)&DAT_00555b88)->get(0x103);
 if (!(*(int*)&DAT_00555b84)) item->enable(0);
 else {
 float scale=1.0f / (*(int*)&DAT_00555b84);
 item->enable(1);
 int r=(int)(__int64)(DAT_00555b80 * scale);
 int g=(int)(__int64)(DAT_00555b7c * scale);
 int b=(int)(__int64)(DAT_00555b78 * scale);
 if(r<0) r=0; else if(r>255) r=255;
 if(g<0) g=0; else if(g>255) g=255;
 if(b<0) b=0; else if(b>255) b=255;
 unsigned color=0xff000000u | (b<<16) | (g<<8) | r;
 float d=DAT_00555b70 * scale;
 float c=DAT_00555b74 * scale;
 float y=DAT_00555b6c * scale;
 float x=DAT_00555b68 * scale;
 item->update(x,y,c,d,color);
 }
 (*(int*)&DAT_00555b84)=0;
 DAT_00555b68=0; DAT_00555b6c=0; DAT_00555b70=0; DAT_00555b74=0; DAT_00555b78=0; DAT_00555b7c=0; DAT_00555b80=0;
}