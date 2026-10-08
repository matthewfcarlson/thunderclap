// Same code shape as 0x00098e20 (propagated; names are from that function)
class A { char pad[12]; int value; public: void Set(int x); };
void A::Set(int x) { value = x; }