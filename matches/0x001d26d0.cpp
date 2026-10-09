class B { public: void f(unsigned int); };
class D { public: void h(B*); };
class C { public: char pad[12]; D d; void g(unsigned int, B*); };
void C::g(unsigned int a, B* b) { b->f(a); d.h(b); }
