class B { public: virtual void V(int); };
class A { public: virtual void Finish(); char pad[0x3c]; int value; char pad2[4]; B *b; void Set(int); };
void A::Set(int x) { value=x; if (b) b->V(x); Finish(); }