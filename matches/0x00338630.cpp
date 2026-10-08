class A { public: virtual void f0(); virtual void f1(); virtual void f2(); };
struct B { char pad[4]; A* p; };
void __fastcall target(B* self) { self->p->f2(); }