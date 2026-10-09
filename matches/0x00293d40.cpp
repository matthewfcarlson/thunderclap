typedef unsigned int U;
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(int,void*); };
struct Holder { Obj *p; };
struct Sub { void init(); };
extern U g0,g1,g2,g4,g5,g6;
extern Sub gS;
struct C { Holder h; void run(U,U,U); };
void C::run(U a, U b, U c) { g0=a; g1=b; g2=c; gS.init(); g4=g0; g5=g1; g6=g2; h.p->f17(0,(void*)&gS); }
