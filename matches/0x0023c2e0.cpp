// Same code shape as 0x00231960 (propagated; names are from that function)
extern void* vtable;
struct Sub { void init(); };
struct Foo { void* vt; char pad[0x24]; void target(); void finish(); };
void Foo::target() { vt = &vtable; ((Sub*)((char*)this + 0x28))->init(); finish(); }
