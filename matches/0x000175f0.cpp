class Obj { public: Obj* second(); void m40(int); void mC0(int); void m20(void*); void mA0(void*); };
class Factory { public: Obj* first(); };
class CInvulnerableAction { public: virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void vfunc_4(); virtual void e(); virtual void f(); virtual void g(); virtual void h(); char pad[0x18]; Factory* member1c; void* member20; };
void CInvulnerableAction::vfunc_4() { Obj* x = member1c->first(); Obj* s = x->second(); s->m40(0); s->mC0(0); s->m20(member20); s->mA0(member20); }