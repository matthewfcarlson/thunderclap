// Same code shape as 0x00034ad0 (propagated; names are from that function)
struct X { void Call(); X* Target(); };
X* X::Target() { Call(); return this; }