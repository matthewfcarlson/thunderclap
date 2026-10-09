// Same code shape as 0x0002caf0 (propagated; names are from that function)
struct Function { virtual void f0(); virtual void f1(); };
struct Method6 : Function { char pad[0x18]; int value; void f2(const char*,const char*,const char*); };
void FUN_0002cb10(const char*,const char*,const char*,int);
void Method6::f2(const char* a,const char* b,const char* c) { FUN_0002cb10(a,b,c,value); }