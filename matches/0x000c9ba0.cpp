class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(Caster*, __int64);
};
extern "C" __int64 FUN_0027b020(void*);
void target(Obj* obj, void* input) {
    __int64 p = FUN_0027b020(input);
    Caster caster;
    obj->d(&caster, p);
}