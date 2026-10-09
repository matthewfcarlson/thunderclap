// Same code shape as 0x00201c00 (propagated; names are from that function)
struct Inner { void Init(int); };
class Thing { public: char pad[0x18]; int value; char pad2[4]; Inner inner; void f(); };
void Thing::f() { value = 0xc61c4000; inner.Init(0); ((char*)this)[0x28] = 0; }