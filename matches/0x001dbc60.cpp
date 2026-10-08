// Same code shape as 0x00090470 (propagated; names are from that function)
class C { char pad[8]; public: void f(); };
class S { public: void h(); };
void C::f() { ((S*)((char*)this + 8))->h(); ((S*)this)->h(); }