// STATUS: equivalent (tools/equiv.py level 3: 222 inputs, branch coverage 20/20)
// pure3d::ImageConverter::vfunc_2 @ 0x002de3f0
struct Name { void FUN_0027af70(Name*); };
struct Texture { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(int,int); virtual void s12(); virtual void* s13(int,int); virtual void s14(int); };
struct Image { virtual void s0(); virtual void s1(); char pad4[4]; Name name; char pad12[4]; int width,height,depth; char pad28[4]; int format; };
struct Result { virtual void s0(); virtual void s1(); char pad4[4]; Name name; char pad12[4]; Texture* texture; char pad20[4]; Result* FUN_002c1c30(); bool FUN_002c1cf0(int,int,int,int,int,int,int,int); };
struct Service { virtual void s0(); virtual void s1(); virtual int s2(); };
struct Extra { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual int s18(); };
extern Service* DAT_0052c2a0;
extern char DAT_004d098c[],DAT_004d09a8[];
void* __cdecl FUN_00263ea0(int);
Extra* __cdecl FUN_00344e74(Image*,int,void*,void*,int);
namespace pure3d { struct ImageConverter { virtual void vfunc_0(); virtual void vfunc_1(); virtual Result* vfunc_2(Image**,int,int,int); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(Image*,void*,int); virtual void vfunc_7(); virtual void vfunc_8(); }; }
Result* pure3d::ImageConverter::vfunc_2(Image** images,int count,int a,int b) {
 void* mem=FUN_00263ea0(24);
 Result* result=mem?((Result*)mem)->FUN_002c1c30():0;
 if(images[0]) result->name.FUN_0027af70(&images[0]->name);
 Image* image=images[0];
 int bits=image->depth==8?8:32; int indexed=image->depth==8?1:0;
 if(!result->FUN_002c1cf0(image->width,image->height,count,bits,image->format,a,indexed,b)) {
 int kind=DAT_0052c2a0->s2();
 if(kind!=1){result->s1();result=0;}
 }
 Texture* texture=result->texture;
 void* data=texture->s13(0,0);
 for(int i=0;i<count;++i) vfunc_6(images[i],data,i);
 texture->s14(0);
 Extra* extra=FUN_00344e74(images[0],0,DAT_004d098c,DAT_004d09a8,0);
 if(extra){int value=extra->s18();result->texture->s11(256,value);}
 return result;
}