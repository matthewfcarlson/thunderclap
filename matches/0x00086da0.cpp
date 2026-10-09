class B { public: void a(); };
bool b80(); void c90(); void thunk(); void f656a0();
class C { public: void d(int,int); };
class A { public: char pad[0x1c]; B* x; char pad2[0x10]; C* y; void tail(); void run(); };
void A::run() { if (x) x->a(); else { thunk(); f656a0(); } if (y) y->d(0,0); if (x) { while (b80()) { c90(); x->a(); } } tail(); }