// Same code shape as 0x001fb9b0 (propagated; names are from that function)
class C { char pad[0x1c]; int value; public: void Set(int x); };
void C::Set(int x) { value = x; }