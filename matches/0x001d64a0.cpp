class B { public: void G(); };
class A { public: char pad[0xec]; B* p; void F(); };
void A::F() { p->G(); }