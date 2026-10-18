typedef unsigned __int64 U64;
extern U64 __cdecl getValue(void*);
class Caster {
  public:
    virtual void f();
    Caster() {}
};
class Inventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int load(Caster*, U64);
};
int __cdecl FUN_00286750(Inventory* inv, void* p) {
    U64 v = getValue(p);
    Caster caster;
    return inv->load(&caster, v);
}
