class B { public: void G(); };
class A { public: virtual void F(); };
void A::F() { ((B*)*(void**)*(void**)this)->G(); }