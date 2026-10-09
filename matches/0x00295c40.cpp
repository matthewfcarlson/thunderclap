class B { public: B(); virtual void f(); };
class C : public B { public: C(); int pad[3]; int a; int b; };
C::C() { a=6; b=0; }