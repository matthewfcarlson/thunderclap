class Obj { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual int f11(); };
class S { public: void run(); };
class A { public: char pad0[4]; char flag; char pad5[0x21]; short x26; short x28; char pad2a[6]; Obj *p30; char gap34[4]; Obj *p38; void finish(char *,int,int,int); };
void FUN_00267110(int);
void __fastcall target(A *a) { a->flag=0; ((S*)a->p38)->run(); a->p38=0; if(a->p30) { int r=a->p30->f11(); FUN_00267110((int)a->x26); int old=(int)a->x26; a->x26=0; a->p30->f1(); a->p30=0; a->finish((char*)a+5,old,r,(int)a->x28); } }