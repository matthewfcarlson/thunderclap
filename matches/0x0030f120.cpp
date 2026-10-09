// Same code shape as 0x00221c60 (propagated; names are from that function)
struct Data { unsigned int a[16]; };
class C { public: Data d; char pad[0x10]; int x; void Copy(C*); };
void C::Copy(C* src) { d = src->d; x = 2; }