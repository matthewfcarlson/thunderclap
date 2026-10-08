class B { public: virtual void F(); };
class A { public: int pad; B *p; void Set(B *b); };
void A::Set(B *b) { p = b; b->F(); }