struct A { char pad[8]; };
struct B { void F(); };
struct X : A, B { void G(); };
void X::G() { B::F(); }