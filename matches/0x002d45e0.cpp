// Same code shape as 0x001d4e00 (propagated; names are from that function)
typedef unsigned int u32;
class C { public: char pad[0xa8]; u32 value; u32 f(); };
u32 C::f() { return value; }