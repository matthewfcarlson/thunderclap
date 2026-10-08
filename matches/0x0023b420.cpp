// Same code shape as 0x001cc840 (propagated; names are from that function)
class C { public: char pad[12]; unsigned int value; unsigned int get(); };
unsigned int C::get() { return value; }