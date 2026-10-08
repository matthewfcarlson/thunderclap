typedef unsigned int U;
struct B { U FUN(U); };
struct A { U x; B* y; A* f(); };
A* A::f() { x = y->FUN(x); return this; }