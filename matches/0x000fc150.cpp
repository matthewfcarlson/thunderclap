class C { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); };
extern C *g;
void target() { g->f5(); }