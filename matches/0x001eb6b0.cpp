// Same code shape as 0x001eb6a0 (propagated; names are from that function)
class B { public: void G(); };
class A { public: virtual void F(); };
void A::F() { ((B*)*(void**)*(void**)this)->G(); }