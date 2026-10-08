class A { public: virtual void f(); virtual void g(); };
class B { public: char pad[0x10]; A* p; void clear(); };
void B::clear() { if (p) p->g(); p = 0; }