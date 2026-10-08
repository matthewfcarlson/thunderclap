// Same code shape as 0x00265560 (propagated; names are from that function)
class Obj { public: virtual void f(); virtual void g(); };
class Holder { public: int Count(Obj*); };
class C { public: char pad[0x0c]; Holder* m; void target(Obj* p); };
void C::target(Obj* p) { int n = m->Count(p); while (n > 0) { p->g(); --n; } }