// Same code shape as 0x002665a0 (propagated; names are from that function)
class C { public: char pad[12]; C* field; void g(); void f(); };
void C::f() { field->g(); }