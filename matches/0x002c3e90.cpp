// Same code shape as 0x002a07c0 (propagated; names are from that function)
class Light { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(int,int,int); virtual void f8(); virtual void f9(); void vfunc_8(int*); };
void Light::vfunc_8(int* p) { f7(p[0], p[1], p[2]); }