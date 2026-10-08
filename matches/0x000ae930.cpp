class B { public: void F(int); };
class A { public: char pad[4]; B* p4; int p8; void Set(int x); };
void A::Set(int x) { if (p4) { p4->F(x); p8=x; } else { p8=x; } }