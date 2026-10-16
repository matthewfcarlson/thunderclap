class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(Caster*, __int64);
};
extern __int64 helper(Obj*);
void target(Obj* obj, Obj* value) {
    __int64 a = helper(value);
    Caster caster;
    obj->f3(&caster, a);
}