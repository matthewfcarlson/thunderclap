struct Sub { void A(); void B(); };
struct X { int* v; char pad[0x64]; void f(); void C(); };
void X::f() { v = (int*)0x4193ec; ((Sub*)((char*)this + 0x78))->A(); ((Sub*)((char*)this + 0x68))->B(); C(); }
