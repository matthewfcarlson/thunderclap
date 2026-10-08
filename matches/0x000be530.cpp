class Function { public: virtual void f0(); virtual void f1(); };
class Function0_void : public Function { public: virtual void f0(); virtual void f2(int,int,int); char pad[0x18]; void (__cdecl *mFn)(); };
void Function0_void::f2(int,int,int) { mFn(); }