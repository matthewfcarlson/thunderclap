class Caster {
  public:
    virtual void f();
};
class Inv {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int use(Caster*, __int64);
};
extern __int64 __cdecl fetch(void*);
int __cdecl target(Inv* inv, void* name) {
    __int64 val = fetch(name);
    Caster caster;
    return inv->use(&caster, val);
}