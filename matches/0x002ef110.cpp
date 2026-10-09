struct A { void f1(); }; struct B { void f2(); }; struct D { void f3(); };
struct C { char p0[0x70]; A a; char p1[0x3f]; B b; char p2[0xff]; D c; C* target(unsigned char flag); void cleanup(); };
void destroy(C*);
C* C::target(unsigned char flag) { c.f3(); b.f2(); a.f1(); cleanup(); if (flag & 1) destroy(this); return this; }