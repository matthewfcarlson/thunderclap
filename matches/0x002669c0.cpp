class Inner { public: virtual void f(); virtual void g(); };
class Outer { public: char pad[0x284]; Inner* p; };
void __fastcall target(Outer* self) { self->p->g(); }