// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FEMemCardControl::vfunc_13 @ 0x000d8030
extern unsigned int DAT_004d9968;
void __fastcall __security_check_cookie(unsigned int);
struct Label { void FUN_000bc9f0(const char*, int); struct Stage1* FUN_000b5000(int); };
struct Stage2 { void FUN_0008c870(); };
struct Stage1 { Stage2* FUN_00089a50(); };
struct Child { char pad[0xab9]; unsigned char flag; };
struct Parent { char pad[0x175c]; Child* child; };
struct Timer { int value; void FUN_000f8500(void*, int, int); };
struct Service { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual int s44(); };
Service* __cdecl FUN_000fc3d0();
extern void* DAT_004a0c64;
struct FEMemCardControl {
 char p0[0xa8]; Parent* parent; char p1[0x150-0xac]; Label* label; char p2[0x1d0-0x154]; int a,b; char p3[0x34c-0x1d8]; int c,d,e; char p4[4]; Timer timer; char p5[0x380-0x360]; unsigned char flag380; char p6[0x3ac-0x381]; int state; unsigned char skip; char p7[0x3e9-0x3b1]; unsigned char f9,fa,fb,fc; char p8[3]; int count; char p9[0x418-0x3f4]; int x,y,z;
 void vfunc_13(int);
};
void FEMemCardControl::vfunc_13(int) {
 unsigned int cookie=DAT_004d9968;
 if (!skip) {
  bool active=fa!=0;
  x=31; fc=0; count=0; f9=0; fb=0;
  if(active) {
   fb=1; y=31; z=31;
   label->FUN_000bc9f0("DynamicControlButtonLabel",0);
   parent->child->flag=0;
   state=15;
  } else state=0;
  b=0; a=0;
  label->FUN_000b5000(0)->FUN_00089a50()->FUN_0008c870();
  d=4; e=4; c=0; flag380=0;
  int v=FUN_000fc3d0()->s44();
  timer.value=0;
  timer.FUN_000f8500(DAT_004a0c64,v,1);
 }
 skip=0;
 __security_check_cookie(cookie);
}
