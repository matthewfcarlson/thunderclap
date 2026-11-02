class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void take(void*);
};
extern "C" void* lookup(void*, Caster*);
extern "C" void FUN_00113cc0(Obj* obj, void* name) {
    Caster caster;
    obj->take(lookup(name, &caster));
}