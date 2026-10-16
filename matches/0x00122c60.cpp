class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Lookup(void*, Caster*);
void Func(Obj* obj, void* key) {
    Caster caster;
    void* found = Lookup(key, &caster);
    obj->Apply(found);
}