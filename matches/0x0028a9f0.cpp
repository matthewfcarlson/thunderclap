class QuaternionChannel { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(int, int, void*); virtual void f4(int,int); virtual void f5(); virtual void f6(); void vfunc_4(int a, int b, int c); };
struct Helper { void call(int); };
void QuaternionChannel::vfunc_4(int a, int b, int c) { char local[16]; f3(a,b,local); ((Helper*)local)->call(*(int*)(&b+1)); }