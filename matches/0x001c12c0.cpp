struct Inner { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); virtual void i(); virtual void j(); virtual void k(); virtual void l(); virtual void m(); virtual void target(); };
struct Wrapper { int pad[2]; Inner* ptr; };
void __fastcall FUN_001c12c0(Wrapper* self) { self->ptr->target(); }
