// Same code shape as 0x00264860 (propagated; names are from that function)
class C { public: int pad; int value; void Set(int); };
void C::Set(int x) { value = x; }