struct Dispatch { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(void*,int,int,int,int,int); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void n(); virtual void o(); virtual void p(); virtual void q(); virtual void r(); virtual void s(); virtual void t(); virtual void u(); virtual void v(); };
struct CementLibrary { void vfunc_8(int **, int, int, int, int, int); };
void CementLibrary::vfunc_8(int **p, int a, int b, int c, int d, int e) {
 Dispatch *dsp = (Dispatch*)this;
 dsp->h(p, a, b, c, d, e);
 Dispatch *v = (Dispatch*)*p;
 if (v) v->v();
}