class Caster {
  public:
    virtual void Cast();
};
extern "C" void* Find(void*, Caster*);
class Obj {
  public:
    void Use(void*);
};
void Func(Obj* obj, void* name) {
    Caster caster;
    obj->Use(Find(name, &caster));
}