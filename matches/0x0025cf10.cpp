struct Inner { void f(); };
struct Obj { char pad[0x1c]; Inner inner; Obj* target(); };
Obj* Obj::target() { inner.f(); return this; }