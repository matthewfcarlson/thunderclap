class A { public: virtual void f(); };
class B { public: virtual void f(); virtual void g(); };
class C { char pad[0x40]; B* m; public: void set(A*); };
class D { public: char pad[0x5c]; A* m; };
void C::set(A* p) { A* n = ((D*)p)->m; if (n) n->f(); if (m) m->g(); m = (B*)n; }