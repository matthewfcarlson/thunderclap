struct Inner {};
struct Tmp { char pad[0x18]; Tmp(Inner*); void f(int,int); };
struct Obj { char pad[0x38]; Inner inner; void target(int,int); };
void Obj::target(int a,int b) { Tmp t(&inner); t.f(a,b); }