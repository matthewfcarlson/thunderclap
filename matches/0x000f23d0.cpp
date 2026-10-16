class Caster {
  public:
    virtual void f();
};
class Inv {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void use(Caster*, __int64);
};
extern __int64 __cdecl fetch(void*);
void __cdecl target(Inv* inv, void* name) {
    __int64 val = fetch(name);
    Caster caster;
    inv->use(&caster, val);
}