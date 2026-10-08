// Same code shape as 0x00086370 (propagated; names are from that function)
class A { char pad[0x48]; public: int x; int f(); };
int A::f() { return x; }