// Same code shape as 0x000cae70 (propagated; names are from that function)
class C { public: char pad[0x88]; int value; int target(); };
int C::target() { return value; }