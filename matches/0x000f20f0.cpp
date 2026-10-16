class Caster {
  public:
    virtual void a();
};
class Object {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(Caster*, void*, void*);
};
void FUN_000f20f0(Object* obj, void* x, void* y) {
    Caster caster;
    obj->d(&caster, x, y);
}