class Caster {
  public:
    Caster(unsigned __int64& v) { v = v; }
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void f(Caster*, unsigned __int64);
};
extern "C" unsigned __int64 __cdecl Make(int);
void __cdecl target(Obj* obj, int n) {
    unsigned __int64 v = Make(n);
    Caster caster(v);
    obj->f(&caster, v);
}