class C { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(int); int x[4]; int m; void target(int); };
void C::target(int a) { m = a; f9(0); }
