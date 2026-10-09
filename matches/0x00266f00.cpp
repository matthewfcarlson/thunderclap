struct C { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(int); };
struct S { C* p; char pad[12]; };
extern S g[];
void __cdecl target(int a, int b) { g[a].p->f4(b); }