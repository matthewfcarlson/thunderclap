struct V { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(int,int); };
struct A { bool run(); }; struct B { bool run(); };
struct G { char pad[8]; B *p; }; extern G *g_4dd700;
struct CSPHulkPropInstance { char x[0x9c]; V *obj; char pad[0x4c]; A *a; void vfunc_8(int, int); };
void CSPHulkPropInstance::vfunc_8(int x, int y) {
 if (a->run() && g_4dd700->p->run()) return;
 obj->f8(x,y);
}