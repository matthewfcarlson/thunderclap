struct A { void* f(); }; struct B { int f(); };
struct CButtonCondition { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(void*); virtual void f10(); char pad[8]; int mIndex; };
void CButtonCondition::f9(void* arg) { void* p=((A*)arg)->f(); int v=((B*)p)->f(); f9((void*)(v+0x1f58+mIndex*12)); }
