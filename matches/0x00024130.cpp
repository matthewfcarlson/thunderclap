struct Part { char x[8]; void F(); };
struct Obj { char pad[0x40]; Part a; Part b; Obj* Target(); };
Obj* Obj::Target() { a.F(); b.F(); return this; }
