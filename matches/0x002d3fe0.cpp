// Same code shape as 0x001d4fc0 (propagated; names are from that function)
class C { public: char pad[0x90]; unsigned int value; unsigned int get(); };
unsigned int C::get() { return value; }