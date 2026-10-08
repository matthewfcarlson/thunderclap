struct Tmp { char pad[0x18]; Tmp(void*); void Run(int, int); };
struct C { void F(int, int); };
void C::F(int a, int b) { Tmp t(this); t.Run(a,b); }