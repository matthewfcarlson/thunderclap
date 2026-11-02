class Caster {
  public:
    virtual void Cast();
};
extern "C" void* Find(void*, Caster*);
class Obj {
  public:
    void Use(void*);
};
extern "C" void FUN_0017dd30(Obj* obj, void* name) {
    Caster caster;
    obj->Use(Find(name, &caster));
}