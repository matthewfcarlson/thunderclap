// Same code shape as 0x001c5790 (propagated; names are from that function)
class StoreBase { public: virtual void x(); char pad[0x118]; unsigned char flag; };
class ObjectTemplate { public: void f(); };
void __cdecl ReleaseTemplate(ObjectTemplate*);
class Store : public StoreBase { public: virtual void a(); virtual void b(); virtual void vfunc_2(ObjectTemplate* p); };
void Store::vfunc_2(ObjectTemplate* p) { if (flag && p) { p->f(); ReleaseTemplate(p); } }
