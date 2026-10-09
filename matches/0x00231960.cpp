extern void* vtable;
struct Sub { void init(); };
struct Foo { void* vt; char pad[0x24]; void target(); void finish(); };
void Foo::target() { vt = &vtable; ((Sub*)((char*)this + 0x28))->init(); finish(); }
