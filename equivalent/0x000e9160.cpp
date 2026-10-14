// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FEObject::vfunc_3 @ 0x000e9160
struct FEObject;
struct Source_e9160 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void* s44();
};
struct Link_e9160 { char pad[4]; Source_e9160* source; };
struct Triple_e9160 { float x,y,z; };
struct Owner_e9160 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int s15(Triple_e9160*,FEObject*); virtual float s16(FEObject*); virtual float s17(FEObject*);
 char pad[4]; Link_e9160* link;
};
struct Matrix {
 struct Row {float a,b,scale,d;} rows[8]; char pad[8]; int index; int tail;
 void FUN_000f7fe0(void*);
 float FUN_000f8840(Triple_e9160*);
 float FUN_000f88a0(Triple_e9160*);
};
// equiv-conv: FUN_000f78e0 eax ecx
int FUN_000f78e0(int, Matrix*);
struct FEObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual int vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
 char pad04[16]; Owner_e9160* owner; Triple_e9160 position; char pad24[0x48]; int mode; char pad70[8]; float offset; char pad7c[0x1c]; unsigned char dirty; char pad99[3]; float x,y;
};
int FEObject::vfunc_3() {
 Matrix matrix;
 matrix.FUN_000f7fe0(owner->link->source->s44());
 float scale = owner->s17(this);
 matrix.rows[matrix.index].scale = owner->s16(this)*scale;
 x = matrix.FUN_000f8840(&position);
 y = matrix.FUN_000f88a0(&position);
 int result=mode;
 if(mode==0) { Triple_e9160 t; result=owner->s15(&t,this); offset=t.x * -0.5f; }
 else if(mode==1) { result=0; offset=0.0f; }
 else if(mode==2) { Triple_e9160 t; result=owner->s15(&t,this); offset=t.x * 0.5f; }
 else result-=2;
 dirty=1;
 return FUN_000f78e0(result,&matrix);
}